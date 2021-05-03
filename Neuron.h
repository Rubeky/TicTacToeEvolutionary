#pragma once
class Neuron
{
private:
	//Weightings from the previous layer
	float weightings[18] = { 0 };

public:
	Neuron();
	void randomiseWeightings();
	void editSlightly(Neuron neuron);
};

