#include "player.h"
#include "chessboard.h"

player::player()
{
    char m_name[30]="Null_Name";
}

void player::attachToBoard(chessboard &Board)
{
    board = &Board;
}

bool player::isPlayerWin(int x,int y)
{
    bool judge = (judge1(x,y)||judge2(x,y)||judge3(x,y)||judge4(x,y));
    return judge;
}

//void player::setPlayerInfo(){}
//这个功能要使用Qt的对话框，来读取玩家的姓名，暂时还没有完成。

char player::returnWinnerName()
{
    return player.m_name;
}

bool player::judge1(int x, int y)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(y - i >= 0 && y + 4 - i <= 15 &&
           board->board[x][y - i] == board->board[x][y + 1 - i] &&
           board->board[x][y - i] == board->board[x][y + 2 - i] &&
           board->board[x][y - i] == board->board[x][y + 3 - i] &&
           board->board[x][y - i] == board->board[x][y + 4 - i])
        return true;
    }
}

bool player::judge2(int x, int y)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(x - i >= 0 && x + 4 - i <= 15 &&
           board->board[x - i][y] == board->board[x + 1 - i][y] &&
           board->board[x - i][y] == board->board[x + 2 - i][y] &&
           board->board[x - i][y] == board->board[x + 3 - i][y] &&
           board->board[x - i][y] == board->board[x + 4 - i][y])
         return true;
    };
}

bool player::judge3(int x, int y)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(x - i >= 0 && y - i >= 0 && x + 4 - i <= 15 && y + 4 - i <= 15 &&
           board->board[x - i][y - i] == board->board[x + 1 - i][y + 1 - i] &&
           board->board[x - i][y - i] == board->board[x + 2 - i][y + 2 - i] &&
           board->board[x - i][y - i] == board->board[x + 3 - i][y + 3 - i] &&
           board->board[x - i][y - i] == board->board[x + 4 - i][y + 4 - i])
        return true;
    }
}

bool player::judge4(int x, int y)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if(x + i <= 15 && y - i >= 0 && x - 4 + i >= 0 && y + 4 - i <= 15 &&
           board->board[x + i][y - i] == board->board[x - 1 + i][y + 1 - i] &&
           board->board[x + i][y - i] == board->board[x - 2 + i][y + 2 - i] &&
           board->board[x + i][y - i] == board->board[x - 3 + i][y + 3 - i] &&
           board->board[x + i][y - i] == board->board[x - 4 + i][y + 4 - i])
        return true;
    }
}
