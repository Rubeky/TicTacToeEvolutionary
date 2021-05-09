#include "Structs.cpp"
#include "Algorithm.h"

Algorithm::Algorithm()
{
	this->randomiseWeightings();
	layers.push_back(Layer(18, 24));
	layers.push_back(Layer(24, 9));
}

//Not implemented (should copy, and modify slightly, the input algorithm)
Algorithm::Algorithm(Algorithm *a) {
	this->layers = a->layers;

	//Needs to modify slightly??
}

void Algorithm::randomiseWeightings() {
	for (int i = 0; i < layers.size(); i++) {
		layers.at(i).randomiseWeightings();
	}
}

//Sets inputs for algorithm, given the board structure
//side: if the player is the opposite side of the board
void Algorithm::setInputs(Board board, bool side)
{
	bool* iterator = 0;

	iterator = board.getIsPlayed();
	for (int i = 0; i < 9; i++) {
		inputs.push_back(iterator[i]);
	}

	iterator = board.getWhoPlayed();
	for (int i = 0; i < 9; i++) {
		//Switches who algorithm sees as played
		if (side) iterator[i] = !iterator[i];
		inputs.push_back(iterator[i]);
	}
}

//Finds "best" outputs given current neural network
void Algorithm::solveOutput() {
	std::vector<float> passThrough;
	int orderTemp;
	float outputTemp;

	//Full solving based on inputs
	for (int i = 0; i < inputs.size(); i++) {
		passThrough.push_back(float(inputs.at(i)));
	}

	passThrough = layers.at(0).processLayer(passThrough);
	outputs = layers.at(1).processLayer(passThrough);

	//Basic bubble sort, only needs to sort a 9 long list
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			if (outputs.at(j) < outputs.at(j + 1)) {
				//Swap
				orderTemp = outputOrder[j];
				outputOrder[j] = outputOrder[j + 1];
				outputOrder[j + 1] = orderTemp;

				outputTemp = outputs.at(j);
				outputs.at(j) = outputs.at(j + 1);
				outputs.at(j + 1) = outputTemp;
			}
		}
	}
}

int Algorithm::makeBestMove(int i) {
	return outputOrder[i];
}

bool Algorithm::playGame(Algorithm a, Board board)
{
	bool gameFinished = false;
	bool moveMade = false;
	int moveToMake = 0;

	while (!gameFinished) {
		moveMade = false;
		//Gives algorithm what it needs
		this->setInputs(board, 0);
		//Run algorithm
		this->solveOutput();
		//Make best move that is playable, recommended by algorithm
		for (int i = 0; !moveMade; i++) {
			moveToMake = this->makeBestMove(i);
			moveMade = board.makeMove(moveToMake, 0);
		}

		//Other algorithms move
		moveMade = false;
		a.setInputs(board, 1);
		a.solveOutput();
		for (int i = 0; !moveMade; i++) {
			moveToMake = a.makeBestMove(i);
			moveMade = board.makeMove(moveToMake, 1);
		}
	}
}
