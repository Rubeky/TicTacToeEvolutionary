#include <iostream>
#include "TicTacToe.h"


int main() {
	TicTacToe* ttt = new TicTacToe();
	int best = 0;

	//Randomise weightings within the TicTacToe algorithms
	ttt->randomiseWeightings();

	//Iterate competitions until best algorithm wins
	for (int i = 0; i < 10000; i++) {
		best = ttt->competeAll();
		ttt->updateBest(best);
	}

	best = ttt->competeAll();
	ttt->saveAlgorithm();
}