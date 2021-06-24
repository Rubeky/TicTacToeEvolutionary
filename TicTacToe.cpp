#include "TicTacToe.h"
#include <vector>
#include "Structs.cpp"
#include <fstream>
using namespace std;

//Holds all neural networks, manipulates them as needed
TicTacToe::TicTacToe()
{
	//Initialising
	for (unsigned int i = 0; i < this->numAlgorithms; ++i) {
		Algorithm* algorithm = new Algorithm();
		this->algorithms.push_back(algorithm);
	}
}

//Makes all Algorithms compete, saving indices of 5 best algorithms to this->bestAlgorithm
void TicTacToe::competeAll()
{
	int wins[numAlgorithms] = { 0 };
	int wIndices[numAlgorithms] = { 0 };
	for (int i = 0; i < numAlgorithms; i++) wIndices[i] = i;
	int whoWon = 0;

	//Increments through all algorithms so they all fight
	for (int i = 0; i < this->numAlgorithms; i++) {
		for (int j = 0; j < this->numAlgorithms; j++) {
			//Sends algorithm to fight another algorithm if it's not itself
			if (i != j) {
				//Instantiates new board
				Board board;
				whoWon = this->algorithms.at(i)->playGame(*this->algorithms.at(j), board);
				//Increments the winning algorithm by 1 (if 3 occurs, no increment)
				switch (whoWon) {
				case(0): wins[j]++; break;
				case(1): wins[i]++; break;
				default: wins[j]++; wins[i]++;
				}

				//Instantiates new board
				Board board2;
				//Inverse fight, where the other side starts first
				whoWon = this->algorithms.at(j)->playGame(*this->algorithms.at(i), board2);
				//Increments the winning algorithm by 1 (if 3 occurs, no increment)
				switch (whoWon) {
				case(0): wins[i]++; break;
				case(1): wins[j]++; break;
				default: wins[j]++; wins[i]++; break;
				}
			} 
		}
	}

	//Sorting algorithms
	for (unsigned int i = 0; i < this->numAlgorithms; i++) {
		if (wins[i] > whoWon) whoWon = wins[i];
	}

	//Sorting so that best algorithm came "position 1" (index 0), using VERY basic bubblesort
	bool sorted = false;
	int swapVar;
	while (!sorted) {
		sorted = true;

		for (int i = 0; i < this->numAlgorithms - 1; i++) {
			if(wins[i] < wins[i + 1])
			{
				swapVar = wins[i];
				wins[i] = wins[i + 1];
				wins[i + 1] = swapVar;

				swapVar = wIndices[i];
				wIndices[i] = wIndices[i + 1];
				wIndices[i + 1] = swapVar;
				sorted = false;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		this->bestAlgorithm[i] = wIndices[i];
	}
}

//Works regardless of if the algorithm structure 
//(i.e. number of neurons per layer etc. has changed)
void TicTacToe::saveAlgorithm()
{
	//Getting current best algorithm
	Algorithm *best = this->algorithms.at(this->bestAlgorithm[0]);

	//Saving best algorithm to csv
	fstream fout;
	fout.open("savedAlgorithm.csv", ios::out | ios::app);

	//Useful numbers to have
	size_t numLayers = best->getLayers().size();
	std::vector<size_t> numNeurons;
	std::vector<std::vector<double>> weights;
	std::vector<double> biases;
	Layer* layer = new Layer(0, 0);

	for (int i = 0; i < numLayers; i++) {
		layer = &best->getLayers().at(i);
		numNeurons.push_back(layer->getWeights().size());
	}

	//First line gives number of layers
	//Second line gives number of neurons in each layer
	//Each line after that represents a neuron, all weightings, then bias
	fout << numLayers;
	fout << "\n";

	//Giving number of neurons in each layer
	for (int i = 0; i < numLayers; i++) {
		fout << numNeurons.at(i);
		if (i < numLayers - 1) fout << ",";
		else fout << "\n";
	}

	//Line 3 onward
	//Each layer
	for (unsigned int i = 0; i < this->algorithms.at(0)->getLayers().size(); i++) {
		layer = &this->algorithms.at(0)->getLayers().at(i);
		weights = layer->getWeights();
		biases = layer->getBiases();
		//Each neuron
		for (unsigned int j = 0; j < weights.size(); j++) {
			//Each weight
			for (unsigned int k = 0; k < weights.at(j).size(); k++) {
				fout << weights.at(j).at(k) << ",";
			}
			fout << biases.at(j) << "\n";
		}
	}
}

void TicTacToe::loadAlgorithm() 
{

}
