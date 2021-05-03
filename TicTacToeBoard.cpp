struct board {
	//0 is O, 1 is X
	bool whoPlayed[9];

	//1 is played
	bool isPlayed[9];

	//Checks if game is won
	bool isFinished() {
		return isDiag() || isStraight();
	}

	//Checking if a diagonal win is present
	bool isDiag() {
		//Checking downward diagonal
		if (isPlayed[0] && isPlayed[4] && isPlayed[8]) {
			if (whoPlayed[0] && whoPlayed[4] && whoPlayed[8]) return true;
			if (!whoPlayed[0] && !whoPlayed[4] && !whoPlayed[8]) return true;
		}

		//Checking upward diagonal
		if (isPlayed[2] && isPlayed[4] && isPlayed[6]) {
			if (whoPlayed[2] && whoPlayed[4] && whoPlayed[6]) return true;
			if (!whoPlayed[2] && !whoPlayed[4] && !whoPlayed[6]) return true;
		}
	}

	//Checking that a horizontal or vertical win is present
	bool isStraight() {
		for (int i = 0; i < 3; i++) {
			
		}
	}
};