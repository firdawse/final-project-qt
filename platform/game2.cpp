#include "game2.h"
#include "ui_game2.h"
#include <QKeyEvent>
#include <QDebug>
#include <QString>
#include "game.h"
#include <QMessageBox>
#include <QLabel>
#include <mainwindow.h>

game2::game2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game2)
{
    ui->setupUi(this);
    this->setFocus();
    game.Restart();
    this->SHOW();
    dialog =new Dialog(this);
    dialog->setModal(true);
    dialog->setWindowTitle("2048");
    dialog->hide();
    lab=new QLabel(dialog);
    lab->move(70,20);
    connect(dialog,SIGNAL(quit()),this,SLOT(quit()));
    connect(dialog,SIGNAL(continuee()),this,SLOT(continuee()));
}

game2::~game2()
{
    delete ui;
}



void game2::SHOW()
{
    for (auto i=0;i<4;i++) {
        for (auto j=0;j<4;j++) {
            int coordinates=i*4+j;
            QGraphicsView *gv=nullptr;
            switch (coordinates) {
            case 0: gv=ui->p1;break;
            case 1: gv=ui->p2;break;
            case 2: gv=ui->p3;break;
            case 3: gv=ui->p4;break;
            case 4: gv=ui->p5;break;
            case 5: gv=ui->p6;break;
            case 6: gv=ui->p7;break;
            case 7: gv=ui->p8;break;
            case 8: gv=ui->p9;break;
            case 9: gv=ui->p10;break;
            case 10: gv=ui->p11;break;
            case 11: gv=ui->p12;break;
            case 12: gv=ui->p13;break;
            case 13: gv=ui->p14;break;
            case 14: gv=ui->p15;break;
            case 15: gv=ui->p16;break;
            default:break;
            }
            switch(game.gridboard[i][j])
            {
            case 0:gv->setStyleSheet("border-image:url(:/0.png)");break;
            case 2:gv->setStyleSheet("border-image:url(:/2.png)");break;
            case 4:gv->setStyleSheet("border-image:url(:/4.png)");break;
            case 8:gv->setStyleSheet("border-image:url(:/8.png)");break;
            case 16:gv->setStyleSheet("border-image:url(:/16.png)");break;
            case 32:gv->setStyleSheet("border-image:url(:/32.png)");break;
            case 64:gv->setStyleSheet("border-image:url(:/64.png)");break;
            case 128:gv->setStyleSheet("border-image:url(:/128.png)");break;
            case 256:gv->setStyleSheet("border-image:url(:/256.png)");break;
            case 512:gv->setStyleSheet("border-image:url(:/512.png)");break;
            case 1024:gv->setStyleSheet("border-image:url(:/1024.png)");break;
            case 2048:gv->setStyleSheet("border-image:url(:/2048.png)");break;
            default:break;
            }
        }
    }
    ui->label_2->setText(QString::number(game.score));
}

void game2::continuee()
{
    game.Restart();
    this->SHOW();
}
void game2::quit()
{
    this->close();
}

void game2::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        this->close();
    }
    if(event->key()==Qt::Key_R)
    {

        game.Restart();

    }
    if(event->key()==Qt::Key_Up)
    {
        game.Up();

    }
    if(event->key()==Qt::Key_Left)
    {
        game.Left();
    }
    if(event->key()==Qt::Key_Right)
    {
        game.Right();
    }
    if(event->key()==Qt::Key_Down)
    {
        game.Down();
    }
    if(game.LOSE())
    {
        lab->setText("You lost, wanna continue");
        dialog->show();
     }
    if(game.WIN())
    {
        lab->setText("you win, wanna continue？");
        dialog->show();
    }
    this->SHOW();
}



void game2::on_pushButton_3_clicked()
{
    auto w = new MainWindow();
    this->hide();
    w->show();
}

