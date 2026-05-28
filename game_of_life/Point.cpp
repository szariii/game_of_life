#include "Point.h"

Point::Point(int col, int row) {
    this->col = col;
    this->row = row;
}

const int Point::getCol() const { return this->col; }
const int Point::getRow() const { return this->row; }
void Point::setCol(int col) { this->col = col; }
void Point::setRow(int row) { this->row = row; }
