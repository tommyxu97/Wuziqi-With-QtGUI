#include "mainwindow.h"
#include "chessboard.h"
#include "player.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_player.attachToBoard(m_board);
    resize(640, 640);
    memset(m_board.board, 0, 15 * 15 * sizeof(int));
    count = 0;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //画出棋盘（画横线和竖线）
    QPainter paint;
    paint.setRenderHint(QPainter::Antialiasing, true);
    
    for (int i = 0; i < 16; i++)
    {
        paint.drawLine(20, 20 + i * 40, 620, 20 + i * 40);
        paint.drawLine(20 + i * 40, 20, 20 + i * 40, 620);
    }

    //画出棋子，当board数组里的数字为1则画黑，2则画白，0为留白
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (m_board.board[i][j] == 1)
            {
                brush.setColor(Qt::black);
                paint.setBrush(brush);
                paint.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
            }
            else if (m_board.board[i][j] == 2)
            {
                brush.setColor(Qt::white);
                paint.setBrush(brush);
                paint.drawEllipse(QPoint((i + 1) * 40, (j + 1) * 40), 15, 15);
            }
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int x, y;
    if ( !(e->x() > 20 & e->y() < 620 & e->y() > 20 & e->y() < 620) )
    {
        QMessageBox::information(this, "Out of the chessboard!", "Out of the chessboard!", QMessageBox::Ok);
        //如果指针区域在棋盘外则报错
    }
    
    x = (e->x() - 20) / 40;
    y = (e->y() - 20) / 40;
    //鼠标指针所在的格子坐标点
    
    if (m_board.board[x][y]==0)
    {
        m_board.board[x][y] = count++ % 2 + 1;
        //当该处没有棋子，按照黑子1，白子2的顺序填入board数组
    }
    else
    {
        QMessageBox::information(this, "Error", "Error", QMessageBox::Ok);
        //当此处是有棋子的话，则弹出对话框报错
    }
    if(m_player.isPlayerWin(x, y))
    {
        update();
        setEnabled(false);
        QMessageBox::information(this, "Win", "Win", QMessageBox::Ok);
        //当玩家胜利时，弹出对话框表示游戏结束
        //此处为实现的一个功能是用对话框弹出赢家的名字，实现方法为QMessageBox和player类里面定义的returnWinnerGame函数，生成一个string字符串如"XXX Win！"并交给对话框显示
    }
    
    update();
}


