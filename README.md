# TicTacToeEvolutionary

This is a basic implementation of an evolutionary algorithm on a Tic Tac Toe algorithm tree

Source: Contains main, initialises everything, each iteration of the evolutionary algorithm happens there
TicTacToe: Holds all current algorithms, each time one wins, make offspring of that one and return that to main
Algorithm: Holds everything needed to run the algrithms against each other, manages evolutionary algorithm
Neuron: Holds weights and biases for each neuron (To be made redundant soon with refactor)

TicTacToeBoard: Holds Board struct which contains the tictactoe board and useful related methods