#pragma once
#include "Cell.h"
#include "Point.h"
#include <vector>


class Board
{
private:
	std::vector<int> mainBoard;
	std::vector<Cell> cells;
	int cols;
	int rows;
public:
	Board(int cols, int rows, std::vector<Point>& points);
	void generateBoard();
	void setStartingPoints(std::vector<Point>& points);
	int countCellPosition(int colIndex, int rowindex);
	void printBoard();
	int countAliveNeighbors(int colIndex, int rowIndex);
	bool isAlive(int colIndex,int rowIndex);
	void setState(std::vector<int> tempBoard);
	void setCols(int cols);
	void setRows(int rows);
	int	getCols();
	int getRows();
	const std::vector<int> &getBoard();
};

