#pragma once
#include "Point.h"
#include <vector>

class Board;

class RuleAbstract {
public:
	virtual int countAliveNeighbours(Board& board, int colIndex, int rowIndex)=0;
	virtual std::vector<int> calculateNextState(Board& board)=0;
	virtual int countCellPosition(Board& board, int colIndex, int rowindex)=0; //przeniesc
	virtual bool isAlive(Board& board, int colIndex, int rowIndex)=0;
};