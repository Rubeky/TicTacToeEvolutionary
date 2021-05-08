#include <utility>
#include <vector>

struct Board {
	//0 is O, 1 is X
private:
	bool whoPlayed[9] = { 0 };

	//1 is played
	bool isPlayed[9] = { 0 };

public:
	//Checks if game is won
	//returns:
	// 0 - No win is present
	// 1 - noughts won
	// 2 - crosses won
	// 3 - tie
	int isFinished() {
		return std::max(isDiag(), isStraight(), isAllFilled());
	}

	//Checking if a diagonal win is present
	int isDiag() {
		//Checking downward diagonal
		if (isPlayed[0] && isPlayed[4] && isPlayed[8]) {
			if (whoPlayed[0] && whoPlayed[4] && whoPlayed[8]) return 2;
			if (!whoPlayed[0] && !whoPlayed[4] && !whoPlayed[8]) return 1;
		}

		//Checking upward diagonal
		if (isPlayed[2] && isPlayed[4] && isPlayed[6]) {
			if (whoPlayed[2] && whoPlayed[4] && whoPlayed[6]) return 2;
			if (!whoPlayed[2] && !whoPlayed[4] && !whoPlayed[6]) return 1;
		}

		return 0;
	}

	//Checking that a horizontal or vertical win is present
	int isStraight() {
		for (int i = 0; i < 3; i++) {
			//Horizontal lines
			if (isPlayed[0 + i*3] && isPlayed[1 + i*3] && isPlayed[2 + i*3]) {
				if (whoPlayed[0 + i * 3] && whoPlayed[1 + i * 3] && whoPlayed[2 + i * 3]) return 2;
				if (!whoPlayed[0 + i * 3] && !whoPlayed[1 + i * 3] && !whoPlayed[2 + i * 3]) return 1;
			}

			//Vertical lines
			if (isPlayed[0 + i] && isPlayed[3 + i] && isPlayed[6 + i]) {
				if (whoPlayed[0 + i] && whoPlayed[3 + i] && whoPlayed[6 + i]) return 2;
				if (!whoPlayed[0 + i] && !whoPlayed[3 + i] && !whoPlayed[6 + i]) return 1;
			}
		}
	}

	//Checks if game is over due to a tie
	int isAllFilled() {
		int howManyFilled = 0;
		for (int i = 0; i < 9; i++) {
			if (isPlayed[i]) howManyFilled++;
		}

		return howManyFilled == 9;
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
};

struct Layer {
private:
	std::vector<std::vector<float>> weights;	//Contains weights for each neuron (num neurons, size of input vector)
	std::vector<float> biases;					//Contains biases for each neuron (num neurons)
public:
	//Allocates weights and biases to proper sizes
	Layer(int prevLayerSize, int currentLayerSize) {
		weights.resize(currentLayerSize);
		for (int i = 0; i < weights.size(); i++) {
			weights.at(i).resize(prevLayerSize);
		}

		biases.resize(currentLayerSize);
	}

	std::vector<float> processLayer(std::vector<float> prevLayerOutputs) {
		float tempVar = 0;
		std::vector<float> output;
		//Iterate neurons
		for (int i = 0; i < weights.size(); i++) {
			tempVar = 0;

			//Iterate weightings for neuron
			for (int j = 0; j < weights.at(i).size(); j++) {
				tempVar += weights.at(i).at(j) * prevLayerOutputs.at(j);
			}

			//Adds bias
			tempVar += biases.at(i);

			//Ready for output!
			output.push_back(tempVar);
		}
	}
};