#pragma once
#include "BoundaryStrategy.h"
#include "Point.h"
#include <memory>
#include <vector>
class Board;

class RuleAbstract
{
  public:
    std::shared_ptr<BoundaryStrategy> boundary;
    RuleAbstract(std::shared_ptr<BoundaryStrategy> boundaryStrategy) : boundary(boundaryStrategy)
    {
    }
    virtual ~RuleAbstract() = default;
    virtual int countAliveNeighbours(const Board& board, int colIndex, int rowIndex) = 0;
    virtual std::vector<int> calculateNextState(const Board& board) = 0;
    virtual int countCellPosition(const Board& board, int colIndex,
                                  int rowindex) = 0; // przeniesc
    virtual bool isAlive(const Board& board, int colIndex, int rowIndex) = 0;
};