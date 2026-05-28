#pragma once
#include "BoundaryStrategy.h"

class TorusBoundary : public BoundaryStrategy {
public:
  bool adjustCoordinates(int &currentCol, int &currentRow, int boardCols,
                         int boardRows) override;
};