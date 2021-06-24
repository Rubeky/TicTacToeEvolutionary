#pragma once
#include <vector>
#include <time.h>

struct Board {
	//0 is O, 1 is X
private:
	std::vector<bool> whoPlayed;

	//1 is played
	std::vector<bool> isPlayed;

public:

	Board() {
		this->whoPlayed = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		this->isPlayed = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	}

	//Checks if game is won
	//returns:
	// 0 - noughts won
	// 1 - crosses won
	// 2 - tie
	// 3 - no win yet
	int isFinished() {
		int max1 = std::min(isDiag(), isStraight());
		return std::min(max1, isAllFilled());
	}

	//Checking if a diagonal win is present
	int isDiag() {
		//Checking downward diagonal
		if (isPlayed[0] && isPlayed[4] && isPlayed[8]) {
			if (whoPlayed[0] && whoPlayed[4] && whoPlayed[8]) return 1;
			if (!whoPlayed[0] && !whoPlayed[4] && !whoPlayed[8]) return 0;
		}

		//Checking upward diagonal
		if (isPlayed[2] && isPlayed[4] && isPlayed[6]) {
			if (whoPlayed[2] && whoPlayed[4] && whoPlayed[6]) return 1;
			if (!whoPlayed[2] && !whoPlayed[4] && !whoPlayed[6]) return 0;
		}

		return 0;
	}

	//Checking that a horizontal or vertical win is present
	int isStraight() {
		for (unsigned int i = 0; i < 3; i++) {
			//Horizontal lines
			if (isPlayed[0 + i * 3] && isPlayed[1 + i * 3] && isPlayed[2 + i * 3]) {
				if (whoPlayed[0 + i * 3] && whoPlayed[1 + i * 3] && whoPlayed[2 + i * 3]) return 1;
				if (!whoPlayed[0 + i * 3] && !whoPlayed[1 + i * 3] && !whoPlayed[2 + i * 3]) return 0;
			}

			//Vertical lines
			if (isPlayed[0 + i] && isPlayed[3 + i] && isPlayed[6 + i]) {
				if (whoPlayed[0 + i] && whoPlayed[3 + i] && whoPlayed[6 + i]) return 1;
				if (!whoPlayed[0 + i] && !whoPlayed[3 + i] && !whoPlayed[6 + i]) return 0;
			}
		}
	}

	//Checks if game is over due to a tie
	int isAllFilled() {
		int howManyFilled = 0;
		for (unsigned int i = 0; i < 9; i++) {
			if (isPlayed[i]) howManyFilled++;
		}

		return 3 - (howManyFilled == 9);
	}

	//Fills in a move if it hasn't already been played
	//place: 0-8, place in board that wants to be filled
	//player: 0 is O, 1 is X
	bool makeMove(int place, bool player) {
		if (!isPlayed[place]) {
			isPlayed[place] = true;
			whoPlayed[place] = player;
			return true;
		}

		return false;
	}

	std::vector<bool> getWhoPlayed() {
		return whoPlayed;
	}

	std::vector<bool> getIsPlayed() {
		return isPlayed;
	}
};

struct Layer {
private:
	std::vector<std::vector<double>> weights;	//Contains weights for each neuron (num neurons, size of input vector)
	std::vector<double> biases;					//Contains biases for each neuron (num neurons)
public:
	//Allocates weights and biases to proper sizes
	Layer(int prevLayerSize, int currentLayerSize) {
		weights.resize(currentLayerSize);
		for (unsigned int i = 0; i < weights.size(); i++) {
			weights.at(i).resize(prevLayerSize);
		}

		biases.resize(currentLayerSize);
	}

	std::vector<double> processLayer(std::vector<double> prevLayerSize) {
		float tempVar = 0;
		std::vector<double> output;
		//Iterate neurons
		for (unsigned int i = 0; i < weights.size(); i++) {
			tempVar = 0;

			//Iterate weightings for neuron
			for (unsigned int j = 0; j < weights.at(i).size(); j++) {
				tempVar += weights.at(i).at(j) * prevLayerSize.at(j);
			}

			//Adds bias
			tempVar += biases.at(i);

			//Ready for output!
			output.push_back(tempVar);
		}

		return output;
	}

	void randomiseWeightings() {
		srand((unsigned)time(NULL));
		for (unsigned int i = 0; i < weights.size(); i++) {
			for (unsigned int j = 0; j < weights[i].size(); j++) {
				weights[i][j] = ((double)rand() / (RAND_MAX/2)) - 1;
			}
		}
	}

	std::vector<std::vector<double>> getWeights() {
		return this->weights;
	}

	std::vector<double> getBiases() {
		return this->biases;
	}
};