#pragma once

class Point {
private:
    int col;
    int row;
public:
    Point(int col, int row);

    const int getCol();
    const int getRow();
    void setCol(int col);
    void setRow(int row);
};
