/*
 
 用QT实现简单的五子棋游戏
 徐昊天 2017/05

*/


#include <QApplication>
#include "mainwindow.h"
#include "player.h"
#include "chessboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
