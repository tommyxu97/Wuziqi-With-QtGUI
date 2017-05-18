#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QMessageBox>
#include "chessboard.h"
#include "player.h"

class MainWindow: public QMainWindow
{
private:
    int count = 0;
public:
    player m_player;
    chessboard m_board;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // MAINWINDOW_H
