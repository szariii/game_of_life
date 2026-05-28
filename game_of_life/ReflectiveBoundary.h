#pragma once
#include "BoundaryStrategy.h"
class ReflectiveBoundary : public BoundaryStrategy
{
public:
	bool adjustCoordinates(int& currentCol, int& currentRow, int boardCols, int boardRows) override;
};

