#include "TicTacToe.h"
#include <vector>
using namespace std;

//Holds all neural networks, manipulates them as needed
TicTacToe::TicTacToe()
{
	//Initialising
	for (int i = 0; i < 10; i++) {
		Algorithm* algorithm = new Algorithm();
		this->algorithms.push_back(algorithm);
	}
}

int TicTacToe::competeAll()
{
	int wins[10] = { 0 };
	bool whoWon = false;

	//Increments through all algorithms so they all fight
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//Sends algorithm to fight another algorithm
			if (i != j) whoWon = this->algorithms.at(i)->playGame(*this->algorithms.at(j));
			//Increments the winning algorithm by 1
			whoWon ? wins[i]++ : wins[j]++;
		}
	}
}

void TicTacToe::updateBest(int best)
{
}

void TicTacToe::saveAlgorithm()
{
	//Getting current best algorithm
	int best = competeAll();

	//Saving best algorithm to csv

}
