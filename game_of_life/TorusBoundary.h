#pragma once
#include "BoundaryStrategy.h"

class TorusBoundary : public BoundaryStrategy {
public:
    bool adjustCoordinates(int& c, int& r, int cols, int rows) override;
};