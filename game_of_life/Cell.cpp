#include "Cell.h"

Cell::Cell(int position) {
	this->position = position;
}

int Cell::getPosition() {
	return position;
}

void Cell::setPosition(int position) {
	this->position = position;
}
