#pragma once
#include "board.h"
#include "Point.h"
#include <vector>


class Rule {
	public:
		int countAliveNeighbours(Board& board, int colIndex, int rowIndex);
		std::vector<int> calculateNextState(Board& board);
};