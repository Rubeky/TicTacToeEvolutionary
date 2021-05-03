#include <ctime>
#include <random>
#include "Neuron.h"

Neuron::Neuron()
{
	//Seed rand function
	srand(static_cast <unsigned> (time(0)));
	this->randomiseWeightings();
}

void Neuron::randomiseWeightings()
{
	//Iterating through weightings, randomising as it goes
	for (int i = 0; i < 18; i++) {
		//Generates weight between -1 and 1
		weightings[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 2) - 1;
	}
}

//Nudges random values a little bit (up to 50%)
void Neuron::editSlightly(Neuron neuron)
{
	
}
