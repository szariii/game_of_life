#pragma once
#include <vector>
#include "Cell.h"
#include "Point.h"
#include "Board.h"

class Game
{
	private:
		Board b;

		int countCellPosition(int colIndex, int rowindex);
		void generateBoard();
		void setStartingPoints(std::vector<Point>& points);

	public:
		Game(int cols, int rows, std::vector<Point>& points);
		void nextRound();
		void printBoard();
		
		Board& getBoard();

};

