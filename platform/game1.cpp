#include "game1.h"
#include "ui_game1.h"
#include "mainwindow.h"
#include "state.h"
#include<iostream>
int r = 0;
int t = 0;
bool a=1;
game1::game1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::game1)
{
    ui->setupUi(this);
    setupContainer();
    isGameOngoing=true;
    QPixmap bkgnd(":/back.png");
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

       ui->pp1->setStyleSheet("QPushButton { image: url(:/sound.png);background: transparent;}");
       ui->pp->setStyleSheet("QPushButton { image: url(:/smile.png);background: transparent;}");
       connect(timer, &QTimer::timeout, this, &game1::showTime);
       connect(ui->pp,SIGNAL(clicked()),this,SLOT(newg()));
       connect(ui->pp1,SIGNAL(clicked()),this,SLOT(cms()));
       sing.setMedia(QUrl("qrc:/classic.mp3"));
       click.setMedia(QUrl("qrc:/click.mp3"));
       lost.setMedia(QUrl("qrc:/lost.mp3"));
       sing.play();
}
void game1::cms(){
    a= !a;
    if(a){
        sing.play();
        ui->pp1->setStyleSheet("QPushButton { image: url(:/sound.png);background: transparent;}");
    }else{
        sing.stop();
        ui->pp1->setStyleSheet("QPushButton { image: url(:/mute.png);background: transparent;}");
    }
}
void game1::newg(){
     lost.setMedia(QUrl("qrc:/lost.mp3"));
    timer->stop();
    r=0;
    t=0;
    ui->pp->setStyleSheet("QPushButton { image: url(:/smile.png);background: transparent;}");

    setupContainer();
    isGameOngoing=true;
}
game1::~game1()
{
    delete ui;
}
bool game1::randbool(int w){
    return (rand()%w)==0;
}
void game1::setupContainer(){

    QSignalMapper *Left;
    QSignalMapper *Right;
    Left = new QSignalMapper(this);
   Right = new QSignalMapper(this);
    connect(Left, SIGNAL(mapped(int)),this, SLOT(boxL(int)));
    connect(Right, SIGNAL(mapped(int)),this, SLOT(boxR(int)));
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
          bool bomb=randbool(5);
            grid[i][j] = new cell(bomb);
            auto bobo = grid[i][j];
            if(bobo->bomb){
                r++;
            }
             bobo->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
              bobo->setFocusPolicy(Qt::NoFocus);
              bobo->setMinimumSize(40,40);
              bobo->setContentsMargins(0,0,0,0);
              bobo->setMaximumSize(40,40);
            QFont f =bobo->font();
            f.setPointSize(19);
            bobo->setFont(f);
            ui->container->addWidget(bobo,i,j);
            Left->setMapping(bobo,(i*1000)+j);
            Right->setMapping(bobo,(i*1000)+j);
            connect(bobo,SIGNAL(clicked()),Left,SLOT(map()));
            connect(bobo,SIGNAL(rightClicked()),Right,SLOT(map()));
        }
    }
}
void game1::showTime()
{
    t++;
    ui->lcdNumber_2->display(t);
}
void game1::boxL(int i){
    click.play();
    if(t==0)
        timer->start(1000);
    if(!isGameOngoing)return;
    int p[2];
    p[0]=i/1000;
    p[1]=i%1000;

    cell* bobo=grid[p[0]][p[1]];
    if(bobo->bomb){
        bigbang();
        bobo->boxClicked();
        return;
    }
    bobo->boxClicked();
    clear(p[0],p[1]);
    winCheck();

}
void game1::boxR(int id){
    click.play();
    if(t==0)
        timer->start(1000);
    if(!isGameOngoing)return;
    int p[2];
    p[0]=id/1000;
    p[1]=id%1000;

    cell* b=grid[p[0]][p[1]];
    b->boxRightClicked();
    winCheck();
}
void game1::clear(int x,int y){
    grid[x][y]->boxClicked();
    grid[x][y]->setBombCount(findBombCount(x,y));
    if(findBombCount(x,y)==0){
        for(int i=-1;i<=1;i++){
            if(x+i<0 || x+i>10-1)continue;
            for(int j=-1;j<=1;j++){
                if(y+j<0 || y+j>10-1 || (i==0 && j==0))continue;
                if(!grid[x+i][y+j]->isClicked()){
                    clear(x+i,y+j);
                }
            }
        }

    }else{
        return;
    }
}
int game1::findBombCount(int x,int y){
    int count=0;
    for(int i=-1;i<=1;i++){
        if(x+i<0 || x+i>9)
            continue;
        for(int j=-1;j<=1;j++){
            if(y+j<0 || y+j>9 || (i==0 && j==0))
                continue;

            cell* cell=grid[x+i][y+j];
            if(cell->bomb)count++;
        }
    }
    return count;
}


void game1::bigbang(){
    lost.play();
    ui->pp->setStyleSheet("QPushButton { image: url(:/dead.png);background: transparent;}");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cell *bobo=grid[i][j];
            if(bobo->bomb){
                bobo->boxClicked();
            }
        }
    }
    timer->stop();
    isGameOngoing=false;
}

bool game1::winCheck(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cell *bobo=grid[i][j];

            if(!bobo->bomb && !bobo->isClicked())return false;
            if(!bobo->bomb && bobo->flagged)return false;
        }
    }
 lost.setMedia(QUrl("qrc:/w.mp3"));
 lost.play();
    isGameOngoing=false;
    return true;
}

void game1::on_actionback_triggered()
{
    auto w = new MainWindow();
    this->hide();
    w->show();
}


void game1::on_pushButton_3_clicked()
{
    auto w = new MainWindow();
    this->hide();
    w->show();
}

