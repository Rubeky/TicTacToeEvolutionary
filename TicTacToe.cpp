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
	int returnValue = 0;
	bool whoWon = false;

	//Increments through all algorithms so they all fight
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//Sends algorithm to fight another algorithm if it's not itself
			if (i != j) {
				whoWon = this->algorithms.at(i)->playGame(*this->algorithms.at(j));
				//Increments the winning algorithm by 1 (if 3 occurs, no increment)
				switch (whoWon) {
				case(0): wins[j]++;
				case(1): wins[i]++;
				}

				//Inverse fight, where the other side starts first
				whoWon = this->algorithms.at(j)->playGame(*this->algorithms.at(i));
				//Increments the winning algorithm by 1 (if 3 occurs, no increment)
				switch (whoWon) {
				case(0): wins[i]++;
				case(1): wins[j]++;
				}
			} 
		}
	}

	//Finding algorithm with most wins
	for (int i = 0; i < 10; i++) {
		if (wins[i] > returnValue) returnValue = wins[i];
	}

	return returnValue;
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
