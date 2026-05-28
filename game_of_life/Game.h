#pragma once
#include "Board.h"
#include "Point.h"
#include "Rule.h"
#include <vector>

class Game {
private:
  Board b;
  std::shared_ptr<RuleAbstract> r;

public:
  Game(int cols, int rows, std::vector<Point> &points,
       std::shared_ptr<RuleAbstract> rule);
  void nextRound();
  void printBoard();

  const Board getBoard() const;
};
