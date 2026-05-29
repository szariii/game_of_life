#pragma once
#include "Board.h"
#include "BoundaryStrategy.h"
#include "Point.h"
#include "RuleAbstract.h"
#include <vector>

class Rule : public RuleAbstract
{
  public:
    Rule(std::shared_ptr<BoundaryStrategy> strategy) : RuleAbstract(strategy)
    {
    }
    int countAliveNeighbours(const Board& board, int colIndex, int rowIndex) override;
    std::vector<int> calculateNextState(const Board& board) override;
    int countCellPosition(const Board& board, int colIndex,
                          int rowindex) override; // przeniesc
    bool isAlive(const Board& board, int colIndex, int rowIndex) override;
};