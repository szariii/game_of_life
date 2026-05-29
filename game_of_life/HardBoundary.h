#pragma once
#include "BoundaryStrategy.h"

class HardBoundary : public BoundaryStrategy
{
  public:
    bool adjustCoordinates(int& currentCol, int& currentRow, int boardCols, int boardRows) override;
    bool isOUtOfBounds(int& currentCol, int& currentRow, int boardCols, int boardRows);
};