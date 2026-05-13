#pragma once
#include "Point.h"
#include "RuleAbstract.h"
#include <vector>


class Board
{
private:
	std::vector<int> mainBoard;
	int cols;
	int rows;
	RuleAbstract* rule;
public:
	Board(int cols, int rows, std::vector<Point>& points, RuleAbstract* rule);
	void generateBoard();
	void setStartingPoints(std::vector<Point>& points);
	//int countCellPosition(int colIndex, int rowindex);
	void printBoard();
	//bool isAlive(int colIndex,int rowIndex);
	void setState(std::vector<int> tempBoard);
	void setCols(int cols);
	void setRows(int rows);
	int	getCols();
	int getRows();
	const std::vector<int> &getBoard();
};

