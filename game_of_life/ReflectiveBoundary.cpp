#include "ReflectiveBoundary.h"

bool ReflectiveBoundary::adjustCoordinates(int &currentCol, int &currentRow,
                                           int boardCols, int boardRows) {
  if (currentCol < 0)
    currentCol = 0;
  if (currentCol >= boardCols)
    currentCol = boardCols - 1;
  if (currentRow < 0)
    currentRow = 0;
  if (currentRow >= boardRows)
    currentRow = boardRows - 1;
  return true;
}
