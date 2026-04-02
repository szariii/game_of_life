#include "Game.h"
#include <iostream>



Game::Game(int cols, int rows, std::vector<Point>& points) : b(cols, rows, points) {
	// zainicjalizuj w konstruktorze
}

void Game::nextRound() {
    int cols = b.getCols();
	int rows = b.getRows();
	std::vector<int> tempBoard(cols * rows, 0);

	for (int c = 0; c < cols; ++c) {
		for (int r = 0; r < rows; ++r) {
			int aliveNeighbours = b.countAliveNeighbors(c, r);
			int idx = b.countCellPosition(c, r);
			if (b.isAlive(c, r)) {
				if (aliveNeighbours == 2 || aliveNeighbours == 3) {
					tempBoard[idx] = 1;
				} else {
					tempBoard[idx] = 0;
				}
			} else {
				if (aliveNeighbours == 3) {
					tempBoard[idx] = 1;
				} else {
					tempBoard[idx] = 0;
				}
			}
		}
	}
	b.setState(tempBoard);
}

void Game::printBoard() {
	b.printBoard();
}

Board& Game::getBoard() {
	return b;
}


