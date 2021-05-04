#pragma once
#include "Neuron.h"
#include <vector>

class Algorithm
{
private:
	float inputs[18] = { 0 };
	Neuron hiddenNeurons[2][18];
	Neuron outputs[9];

public:
	Algorithm();
	void setInputs(Board board);
	void solveOutput();
	int makeBestMove(int i);
	bool playGame(Algorithm a, Board board);
};

