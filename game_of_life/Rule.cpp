#include "Rule.h"
#include <vector>

int Rule::countAliveNeighbours(Board& board, int colIndex, int rowIndex) {
	int aliveNeighbors = 0;
	for (int dc = -1; dc <= 1; ++dc) {
		for (int dr = -1; dr <= 1; ++dr) {
			if (dc == 0 && dr == 0) continue; //pomijamy nasza komorke
			int c = colIndex + dc;
			int r = rowIndex + dr;
			// popraw boundary conditions - abstrakcja
			if (c < 0 || c >= board.getCols() || r < 0 || r >= board.getRows()) continue;
			if (isAlive(board,c, r)) {
				++aliveNeighbors;
			}
		}
	}
	return aliveNeighbors;
}


std::vector<int> Rule::calculateNextState(Board& board) {
	int cols = board.getCols();
	int rows = board.getRows();
	std::vector<int> tempBoard(cols * rows, 0);

	for (int c = 0; c < cols; ++c) {
		for (int r = 0; r < rows; ++r) {
			int aliveNeighbours = countAliveNeighbours(board, c, r);
			int idx = (r * cols) + c;
			if (isAlive(board, c, r)) {
				if (aliveNeighbours == 2 || aliveNeighbours == 3) {
					tempBoard[idx] = 1;
				}
			}
			else {
				if (aliveNeighbours == 3) {
					tempBoard[idx] = 1;
				}
			}
		}
	}
	return tempBoard;
}

int Rule::countCellPosition(Board& board, int colIndex, int rowindex) {
	return (rowindex * board.getCols()) + colIndex;
}

bool Rule::isAlive(Board& board, int colIndex, int rowIndex) {
	int pos = countCellPosition(board, colIndex, rowIndex);
	return board.getBoard()[pos];
}