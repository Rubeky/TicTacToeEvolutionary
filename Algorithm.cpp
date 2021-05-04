#include "TicTacToeBoard.cpp"
#include "Algorithm.h"

Algorithm::Algorithm()
{
}

//Sets inputs for algorithm, given the board structure
void Algorithm::setInputs(Board board)
{
}

//Finds "best" outputs given current neural network
void Algorithm::solveOutput() {
}

int Algorithm::makeBestMove(int i) {
	return 0;
}

bool Algorithm::playGame(Algorithm a, Board board)
{
	bool gameFinished = false;
	bool moveMade = false;
	int moveToMake = 0;

	while (!gameFinished) {
		moveMade = false;
		//Gives algorithm what it needs
		this->setInputs(board);
		//Run algorithm
		this->solveOutput();
		//Make best move that is playable, recommended by algorithm
		for (int i = 0; !moveMade; i++) {
			moveToMake = this->makeBestMove(i);
			moveMade = board.makeMove(moveToMake, 0);
		}

		//Other algorithms move
		moveMade = false;
		a.setInputs(board);
		a.solveOutput();
		for (int i = 0; !moveMade; i++) {
			moveToMake = a.makeBestMove(i);
			moveMade = board.makeMove(moveToMake, 1);
		}
	}
}
