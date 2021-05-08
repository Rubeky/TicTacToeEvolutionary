#pragma once
#include "Neuron.h"
#include <vector>

class Algorithm
{
private:
	float inputs[18] = { 0 };
	std::vector<Layer> layers;
	float outputs[9] = { 0 };

public:
	Algorithm();
	Algorithm(Algorithm* a);
	void randomiseWeightings();
	void setInputs(Board board);
	void solveOutput();
	int makeBestMove(int i);
	bool playGame(Algorithm a, Board board);
};

