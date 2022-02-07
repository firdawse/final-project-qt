#include "dialog.h"
#include "ui_dialog.h"
#include "game2.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    emit this->quit();
    this->hide();
}


void Dialog::on_pushButton_2_clicked()
{
    emit this->continuee();
    this->hide();
}

