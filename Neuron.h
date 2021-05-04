#pragma once
class Neuron
{
private:
	//Weightings from the previous layer
	float weightings[18] = { 0 };

	float bias = 0;

public:
	Neuron();
	void randomiseWeightings();
	void setWeightings(float *weightings);
	void editSlightly(Neuron neuron);
};

