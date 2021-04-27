#pragma once
#include "Neuron.h"
#include <vector>

class Algorithm
{
private:
	vector<vector<Neuron>> neurons;

public:
	Algorithm();
	void randomiseWeightings();
};

