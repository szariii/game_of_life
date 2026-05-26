#pragma once
#include "BoundaryStrategy.h"
class ReflectiveBoundary : public BoundaryStrategy
{
public:
	bool adjustCoordinates(int& c, int& r, int cols, int rows) override;
};

