#ifndef GAME2_H
#define GAME2_H

#include <QMainWindow>

#include "game.h"
#include <QWidget>
#include <QKeyEvent>
#include "dialog.h"
#include <QLabel>
#include <QPainter>


namespace Ui {
class game2;
}

class game2 : public QMainWindow
{
    Q_OBJECT

public:
      Game game;
    explicit game2(QWidget *parent = nullptr);
    ~game2();
    void SHOW();

 public slots:
    void continuee();
    void quit();
private slots:
    void on_pushButton_3_clicked();

private:
    void keyPressEvent(QKeyEvent *event);
     QLabel *lab;

     Dialog *dialog;

private:
     Ui::game2 *ui;
};

#endif // GAME2_H
