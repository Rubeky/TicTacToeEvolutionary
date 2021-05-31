#include <iostream>
#include "TicTacToe.h"
#include "Structs.cpp"


int main() {
	TicTacToe* ttt = new TicTacToe();

	//Iterate competitions until best algorithm wins
	for (int i = 0; i < 1000; i++) {
		ttt->competeAll();
	}

	ttt->saveAlgorithm();
}