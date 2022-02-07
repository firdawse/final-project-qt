#include "cell.h"
#include <QtGui>
#include <iostream>
#include "state.h"
#include <QMouseEvent>


cell::cell(bool bomb, QWidget * parent) : QPushButton(parent)
{
    bombCount=0;
    flagged=false;
    boxState=BoxState::unclicked;
    setBomb(bomb);
    update();

}
void cell::flag(){
    if(boxState==BoxState::unclicked){
        setText(flagged?"":"X");
    }
}
void cell::setBomb(bool b){
    bomb=b;
}
void cell::setBombCount(int c){
    if(c!=0)setText(QString::number(c));
}
bool cell::isClicked(){
    return (boxState==BoxState::clicked);
}
bool cell::boxClicked(){


    if(bomb){
        boxState=BoxState::exploded;
    }else{
        boxState=BoxState::clicked;
    }
    update();
    return bomb;
}
void cell::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton && !flagged)
        emit clicked();
}
bool cell::boxRightClicked(){
  if(!flagged){
    setStyleSheet("QPushButton {image: url(:/flag.png);}");
    flagged=true;
    return bomb;}
  else{
            boxState=BoxState::unclicked;
            update();
          flagged=false;
          return bomb;
  }
}
void cell::update(){
    QString style="";
    if(boxState==BoxState::unclicked){

       style+="QPushButton { image: url(:/box.png);border-style: inset;border:0px;}";
        setText("");
    }else if(boxState==BoxState::clicked){
        style+="QPushButton {background-color: rgb(220,220,220);  border-style: solid  ;  border-width: 2px  ;  border-color: blue; border-radius:1px;}";
        setEnabled(false);
    }else if(boxState==BoxState::exploded){
         style+="QPushButton {image: url(:/bomb.png);border-style: inset;}";
        setEnabled(false);
    }
    setStyleSheet(style);

}
