#pragma once
#include "Point.h"
#include "RuleAbstract.h"
#include <vector>

class Board {
private:
  std::vector<int> mainBoard;
  int cols;
  int rows;
  std::shared_ptr<RuleAbstract> rule;

public:
  Board(int cols, int rows, std::vector<Point> &points,
        std::shared_ptr<RuleAbstract> rule);
  void generateBoard();
  void setStartingPoints(std::vector<Point> &points);
  void printBoard();
  void setState(std::vector<int> tempBoard);
  void setCols(int cols);
  void setRows(int rows);
  const int getCols() const;
  const int getRows() const;
  const std::vector<int> getBoard() const;
};
