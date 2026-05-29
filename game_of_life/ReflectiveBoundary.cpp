#include "ReflectiveBoundary.h"

bool ReflectiveBoundary::adjustCoordinates(int& currentCol, int& currentRow, int boardCols,
                                           int boardRows)
{
    adjustCols(currentCol, boardCols);
    adjustRows(currentRow, boardRows);
    return true;
}

bool ReflectiveBoundary::adjustCols(int& currentCol, int boardCols)
{
    if (currentCol < 0)
        currentCol = 0;
    if (currentCol >= boardCols)
        currentCol = boardCols - 1;
    return true;
}
bool ReflectiveBoundary::adjustRows(int& currentRow, int boardRows)
{
    if (currentRow < 0)
        currentRow = 0;
    if (currentRow >= boardRows)
        currentRow = boardRows - 1;
    return true;
}