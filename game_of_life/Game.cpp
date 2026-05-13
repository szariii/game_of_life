#include "Game.h"
#include <iostream>



Game::Game(int cols, int rows, std::vector<Point>& points) : b(cols, rows, points) {
	// zainicjalizuj w konstruktorze
}

void Game::nextRound() {
  
	std::vector<int>nextRoundBoard = r.calculateNextState(this->b);
	b.setState(nextRoundBoard);
}

void Game::printBoard() {
	b.printBoard();
}

Board& Game::getBoard() {
	return b;
}


