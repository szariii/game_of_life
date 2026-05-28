#pragma once

class BoundaryStrategy {
public:
  virtual bool adjustCoordinates(int &currentCol, int &currentRow,
                                 int boardCols, int boardRows) = 0;
  virtual ~BoundaryStrategy() = default;
};