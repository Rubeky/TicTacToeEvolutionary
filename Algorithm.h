#pragma once
#include "Structs.cpp"
#include <vector>

class Algorithm
{
private:
	//Input structure:
	//0-8: isPlayed
	//9-17: whoPlayed
	std::vector<bool> inputs;

	//Runs through algorithm
	std::vector<Layer> layers;

	//Which one to play
	std::vector<double> outputs;

	int outputOrder[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

public:
	Algorithm();
	Algorithm(Algorithm* a);
	std::vector<Layer> getLayers();
	void randomiseWeightings();
	void setInputs(Board board, bool side);
	void solveOutput();
	int makeBestMove(int i);
	bool playGame(Algorithm a, Board board);
};

