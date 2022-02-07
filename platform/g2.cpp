#include "g2.h"
#include "ui_g2.h"

g2::g2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g2)
{
    ui->setupUi(this);
}

g2::~g2()
{
    delete ui;
}

void g2::on_buttonBox_accepted()
{
    play=true;
}


bool g2::isaccepted(){
    return play;
}

