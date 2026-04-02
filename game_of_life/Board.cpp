#include <iostream>
#include <vector>
#include "Board.h"


Board::Board(int cols, int rows, std::vector<Point>& points) : cols(cols), rows(rows) {
    generateBoard();
	setStartingPoints(points);
}

int Board::countCellPosition(int colIndex, int rowindex) {
	return (rowindex * this->cols) + colIndex;
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
		mainBoard.at(countCellPosition(points[i].getCol(), points[i].getRow())) = 1;
		cells.push_back(countCellPosition(points[i].getCol(), points[i].getRow()));
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

int Board::countAliveNeighbors(int colIndex, int rowIndex) {
    int aliveNeighbors = 0;
	for (int dc = -1; dc <= 1; ++dc) {
		for (int dr = -1; dr <= 1; ++dr) {
			if (dc == 0 && dr == 0) continue; //pomijamy nasza komorke
			int c = colIndex + dc;
			int r = rowIndex + dr;
			if (c < 0 || c >= this->cols || r < 0 || r >= this->rows) continue;
			if (mainBoard[countCellPosition(c, r)] == 1) {
				++aliveNeighbors;
			}
		}
	}
  return aliveNeighbors;
}

bool Board::isAlive(int colIndex, int rowIndex) {
	int pos = countCellPosition(colIndex, rowIndex);
	return mainBoard[pos];
}

void Board::setState(std::vector<int> tempBoard) {
	mainBoard = tempBoard;
}

void Board::setCols(int cols) {
	this->cols = cols;
}
void Board::setRows(int rows) {
	this->rows = rows;
}
int	Board::getCols() {
	return this->cols;
}
int Board::getRows() {
	return this->rows;
}
const std::vector<int>& Board::getBoard() {
	return this->mainBoard;
}