#include "Game.h"
#include <iostream>



Game::Game(int cols, int rows, std::vector<Point>& points, std::shared_ptr<RuleAbstract> rule) : b(cols, rows, points, rule), r(rule) {
	
}

void Game::nextRound() {
  
	std::vector<int>nextRoundBoard = r->calculateNextState(this->b);
	b.setState(nextRoundBoard);
}

void Game::printBoard() {
	b.printBoard();
}

Board& Game::getBoard() {
	return b;
}


