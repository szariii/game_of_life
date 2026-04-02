#pragma once

class Point {
private:
    int col;
    int row;
public:
    Point(int col, int row);

    int getCol();
    int getRow();
    void setCol(int col);
    void setRow(int row);
};
