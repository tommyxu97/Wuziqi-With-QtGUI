#include "chessboard.h"

chessboard::chessboard()
{
    for(int i = 0; i <= 15; i++)
    {
        for(int j = 0; j <= 15; j++)
        {
            board[i][j] = 0;
        }
    }
}
