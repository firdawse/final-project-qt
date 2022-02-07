#ifndef GAME1_H
#define GAME1_H

#include <QMainWindow>

#include "cell.h"
#include "state.h"
#include <QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class game1; }
QT_END_NAMESPACE


namespace Ui {
class game1;
}

class game1 : public QMainWindow
{
    Q_OBJECT

public:
    game1(QWidget *parent = nullptr);
    ~game1();
    cell * grid[10][10];
    void setupContainer(); // to setup the grid in the gui

    int findBombCount(int x,int y);
    bool randbool(int w);
    void clear(int x,int y);
    void bigbang();
    bool winCheck();
    QTimer *timer = new QTimer(this);
    QMediaPlayer sing;
    QMediaPlayer click;
    QMediaPlayer lost;

    bool isGameOngoing;

public slots:
    void boxL(int x);
    void cms();
    void boxR(int id);
    void showTime();
    void newg();
private slots:
    void on_actionback_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::game1 *ui;
};

#endif // GAME1_H



