#include "ReflectiveBoundary.h"

bool ReflectiveBoundary::adjustCoordinates(int& c, int& r, int cols, int rows) {
	if (c < 0) c = 0;
	if (c >= cols) c = cols - 1;
	if (r < 0) r = 0;
	if (r >= rows) r = rows - 1;
	return true;
}
