#pragma once
#include <vector>
#include "Algorithm.h"
using namespace std;

class TicTacToe
{
private:
	static const int numAlgorithms = 100;
	vector<Algorithm*> algorithms;
	int bestAlgorithm[5] = { 0 };
public:
	TicTacToe();
	//All Algorithms compete against each other to see who wins, saving best 5 indices
	void competeAll();
	//Saves best Algorithm to a csv
	void saveAlgorithm();
	void loadAlgorithm();
};

