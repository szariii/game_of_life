#include "HardBoundary.h"

bool HardBoundary::adjustCoordinates(int& currentCol, int& currentRow, int boardCols, int boardRows)
{
    return !isOUtOfBounds(currentCol, currentRow, boardCols, boardRows);
}

bool HardBoundary::isOUtOfBounds(int& currentCol, int& currentRow, int boardCols, int boardRows)
{
    return (currentCol < 0 || currentCol >= boardCols || currentRow < 0 || currentRow >= boardRows);
}