#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game1.h"
#include "g2.h"
#include "game2.h"
#include "g3.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    animation2 = new QPropertyAnimation(ui->pushButton_2,"geometry");
    animation2->setDuration(600);
     animation2->setStartValue(ui->pushButton->geometry());
     animation2->setEndValue(QRect(200,350,200,100));
     animation2->start();

     animation = new QPropertyAnimation(ui->pushButton,"geometry");
     animation->setDuration(600);
      animation->setStartValue(ui->pushButton->geometry());
      animation->setEndValue(QRect(600,350,200,100));
      animation->start();

      animation3 = new QPropertyAnimation(ui->label, "opacity");
      animation3->setDuration(3000);
      animation3->setStartValue(0.0);
      animation3->setEndValue(1.0);
      animation3->setEasingCurve(QEasingCurve::OutQuad);
      animation3->start(QAbstractAnimation::DeleteWhenStopped);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   g2 game ;
   auto reply = game.exec();
     if(reply == g2::Accepted)
     {
        auto d = game.isaccepted();
         if(d==1){
         auto game = new game2();
         this->hide();
         game->show();
       }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    g3 game ;
    auto reply = game.exec();
      if(reply == g3::Accepted)
      {
         auto d = game.isaccepted();
          if(d==1){
          auto game = new game1();
          this->hide();
          game->show();
        }
     }
}

