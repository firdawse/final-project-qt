#include "g3.h"
#include "ui_g3.h"

g3::g3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g3)
{
    ui->setupUi(this);
}

g3::~g3()
{
    delete ui;
}

void g3::on_buttonBox_accepted()
{
    play=true;
}


bool g3::isaccepted(){
    return play;
}










