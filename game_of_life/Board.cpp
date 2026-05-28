#include <iostream>
#include "Board.h"


Board::Board(int cols, int rows, std::vector<Point>& points, std::shared_ptr<RuleAbstract> rule) : cols(cols), rows(rows), rule(rule) {
    generateBoard();
	setStartingPoints(points);
}


void Board::generateBoard() {
    // fill in row-major order: rows outer, cols inner
	mainBoard.clear();
	mainBoard.reserve(this->cols * this->rows);
	for (int r = 0; r < this->rows; ++r) {
		for (int c = 0; c < this->cols; ++c) {
			mainBoard.push_back(0);
		}
	}
}

void Board::setStartingPoints(std::vector<Point>& points) {
	for (size_t i = 0; i < points.size(); i++) {
		mainBoard.at(rule->countCellPosition(*this,points[i].getCol(), points[i].getRow())) = 1;
	}
}

void Board::printBoard() {
	std::cout << "\n";
	for (size_t i = 0; i < mainBoard.size(); i++) {
      if (i % this->cols == 0) {
			std::cout << "\n";
		}
		std::cout << " " << mainBoard.at(i);
	}
}
 // dodac Rule zamiast funkcji coutnCellPosition (wiêcej info na mes)


void Board::setState(std::vector<int> tempBoard) {
	mainBoard = tempBoard;
}

void Board::setCols(int cols) {
	this->cols = cols;
}
void Board::setRows(int rows) {
	this->rows = rows;
}
const int Board::getCols() {
	return this->cols;
}
const int Board::getRows() {
	return this->rows;
}
const std::vector<int>& Board::getBoard() {
	return this->mainBoard;
}