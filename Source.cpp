#include <iostream>
#include "TicTacToe.h"
#include "TicTacToeBoard.cpp"


int main() {
	TicTacToe* ttt = new TicTacToe();
	int best = 0;

	//Iterate competitions until best algorithm wins
	for (int i = 0; i < 1000; i++) {
		best = ttt->competeAll();
		ttt->updateBest(best);
	}

	ttt->saveAlgorithm();
}