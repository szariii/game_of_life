#include "TorusBoundary.h"

bool TorusBoundary::adjustCoordinates(int& c, int& r, int cols, int rows) {   
 c = (c % cols + cols) % cols; // Zawijanie ekranu 
 r = (r % rows + rows) % rows;
 return true; // Komórka zawsze ma s¹siada
}
