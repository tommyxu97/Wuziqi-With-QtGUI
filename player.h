#ifndef PLAYER_H
#define PLAYER_H
#include "chessboard.h"

class player
{
private:
    char m_name[30];
    chessboard *board;
public:
    player();
    //void setPlayerInfo();
    bool isPlayerWin(int x, int y);
    char returnWinnerName();
    void attachToBoard(chessboard &Board);
    bool judge1(int x, int y);
    bool judge2(int x, int y);
    bool judge3(int x, int y);
    bool judge4(int x, int y);
};

#endif // PLAYER_H
