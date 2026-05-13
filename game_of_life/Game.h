#pragma once
#include <vector>
#include "Point.h"
#include "Board.h"
#include "Rule.h"

class Game
{
	private:
		Board b;
		Rule r;

		int countCellPosition(int colIndex, int rowindex);
		void generateBoard();
		void setStartingPoints(std::vector<Point>& points);

	public:
		Game(int cols, int rows, std::vector<Point>& points, RuleAbstract* rule);
		void nextRound();
		void printBoard();
		
		Board& getBoard();

};

