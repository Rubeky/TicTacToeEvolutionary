#include <utility>

struct board {
	//0 is O, 1 is X
	bool whoPlayed[9];

	//1 is played
	bool isPlayed[9];

	//Checks if game is won
	//returns:
	// 0 - No win is present
	// 1 - noughts won
	// 2 - crosses won
	int isFinished() {
		return std::max(isDiag(), isStraight());
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
};