#pragma once
class Neuron
{
private:
	//Weightings from the previous layer
	float weightings[9] = { 0 };

public:
	Neuron();
	void randomiseWeightings();
};

