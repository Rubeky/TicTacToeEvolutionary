#pragma once
#include <vector>
#include "Algorithm.h"
using namespace std;

class TicTacToe
{
private:
	vector<Algorithm*> algorithms;
public:
	TicTacToe();
	//All Algorithms compete against each other to see who wins
	int competeAll();
	//Updates Algorithms based on which one is best
	void updateBest(int best);
	//Saves best Algorithm to a csv
	void saveAlgorithm();
};

