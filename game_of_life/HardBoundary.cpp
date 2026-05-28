#include "HardBoundary.h"

bool HardBoundary::adjustCoordinates(int& currentCol, int& currentRow, int boardCols, int boardRows){
    if (currentCol < 0 || currentCol >= boardCols || currentRow < 0 || currentRow >= boardRows) {
        return false;
    }
    return true;
}

