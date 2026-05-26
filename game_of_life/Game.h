#pragma once
#include <vector>
#include "Point.h"
#include "Board.h"
#include "Rule.h"

class Game
{
	private:
		Board b;
		std::shared_ptr<RuleAbstract> r;
	public:
		Game(int cols, int rows, std::vector<Point>& points, std::shared_ptr<RuleAbstract> rule);
		void nextRound();
		void printBoard();
		
		Board& getBoard();

};

