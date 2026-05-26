#pragma once
#include "Board.h"
#include "Point.h"
#include "RuleAbstract.h"
#include <vector>
#include "BoundaryStrategy.h"

class Rule: public RuleAbstract {
public:
		Rule(std::shared_ptr<BoundaryStrategy> strategy) : RuleAbstract(strategy) {}
		int countAliveNeighbours(Board& board, int colIndex, int rowIndex) override;
		std::vector<int> calculateNextState(Board& board) override;
		int countCellPosition(Board& board, int colIndex, int rowindex) override; //przeniesc
		bool isAlive(Board& board, int colIndex, int rowIndex) override;
};