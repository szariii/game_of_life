#include "Rule.h"
#include <vector>

int Rule::countAliveNeighbours(const Board& board, int colIndex, int rowIndex)
{
    auto aliveNeighbors = 0;
    for (int dc = -1; dc <= 1; ++dc)
    {
        for (int dr = -1; dr <= 1; ++dr)
        {
            if (dc == 0 && dr == 0)
                continue; // pomijamy nasza komorke
            int c = colIndex + dc;
            int r = rowIndex + dr;
            if (boundary->adjustCoordinates(c, r, board.getCols(), board.getRows()))
            {
                if (isAlive(board, c, r))
                {
                    ++aliveNeighbors;
                }
            }
        }
    }
    return aliveNeighbors;
}

std::vector<int> Rule::calculateNextState(const Board& board)
{
    int cols = board.getCols();
    int rows = board.getRows();
    std::vector<int> tempBoard(cols * rows, 0);

    for (int c = 0; c < cols; ++c)
    {
        for (int r = 0; r < rows; ++r)
        {
            const auto aliveNeighbours = countAliveNeighbours(board, c, r);
            const auto idx = countCellPosition(board, c, r);
            if (isAlive(board, c, r))
            {
                if (aliveNeighbours == 2 || aliveNeighbours == 3)
                {
                    tempBoard.at(idx) = 1;
                }
            }
            else
            {
                if (aliveNeighbours == 3)
                {
                    tempBoard.at(idx) = 1; /// todo
                }
            }
        }
    }
    return tempBoard;
}

int Rule::countCellPosition(const Board& board, int colIndex, int rowindex)
{
    return (rowindex * board.getCols()) + colIndex;
}

bool Rule::isAlive(const Board& board, int colIndex, int rowIndex)
{
    const auto pos = countCellPosition(board, colIndex, rowIndex);
    return board.getBoard()[pos];
}