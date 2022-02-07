#include "g1.h"
#include "ui_g1.h"

g1::g1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g1)
{
    ui->setupUi(this);
}

g1::~g1()
{
    delete ui;
}


void g1::on_buttonBox_accepted()
{

    play=true;
}


bool g1::isaccepted(){
    return play;
}

