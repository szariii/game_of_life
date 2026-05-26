#include "HardBoundary.h"

bool HardBoundary::adjustCoordinates(int& c, int& r, int cols, int rows){
    if (c < 0 || c >= cols || r < 0 || r >= rows) {
        return false;
    }
    return true;
}

