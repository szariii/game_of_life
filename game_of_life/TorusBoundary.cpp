#include "TorusBoundary.h"

bool TorusBoundary::adjustCoordinates(int& currentCol, int& currentRow, int boardCols, int boardRows) {   
	currentCol = (currentCol % boardCols + boardCols) % boardCols; // Zawijanie ekranu 
	currentRow = (currentRow % boardRows + boardRows) % boardRows;
 return true; // Komórka zawsze ma s¹siada
}
