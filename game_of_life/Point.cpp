#include "Point.h"

Point::Point(int col, int row) {
    this->col = col;
    this->row = row;
}

int Point::getCol() { return this->col; }
int Point::getRow() { return this->row; }
void Point::setCol(int col) { this->col = col; }
void Point::setRow(int row) { this->row = row; }
