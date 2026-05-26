#pragma once

class BoundaryStrategy {
public:
	virtual bool adjustCoordinates(int& c, int& r, int cols, int rows) = 0;
	virtual ~BoundaryStrategy() = default;
};