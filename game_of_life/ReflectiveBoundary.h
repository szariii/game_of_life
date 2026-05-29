#pragma once
#include "BoundaryStrategy.h"
class ReflectiveBoundary : public BoundaryStrategy
{
  public:
    bool adjustCoordinates(int& currentCol, int& currentRow, int boardCols, int boardRows) override;
    bool adjustRows(int& currentRow, int boardRows);
    bool adjustCols(int& currentCol, int boardCols);
};
