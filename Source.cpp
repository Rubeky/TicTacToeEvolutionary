#include <iostream>
#include "TicTacToe.h"


int main() {
	TicTacToe* ttt = new TicTacToe();
	int best = 0;

	//Randomise weightings within the TicTacToe algorithms
	ttt->randomiseWeightings();

	//Iterate competitions until best algorithm wins
	for (int i = 0; i < 1000; i++) {
		best = ttt->competeAll();
		ttt->updateBest(best);
	}

	ttt->saveAlgorithm();
}