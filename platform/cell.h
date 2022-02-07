#ifndef CELL_H
#define CELL_H

#include <QMainWindow>

#include <QObject>
#include<QtGui>
#include <QPushButton>

#include "state.h"


class cell : public QPushButton
{
    Q_OBJECT

        public:
            cell(bool bomb, QWidget * parent = 0);
            int bombCount;
            bool bomb;
            bool flagged;
            void flag();
            void setBomb(bool b);
            bool boxClicked();
            bool boxRightClicked();
            bool isClicked();
            void update();
                    void setBombCount(int c);

        private:
            BoxState boxState;
        signals:
                void rightClicked();

        public slots:
                void mousePressEvent(QMouseEvent *e);


};


#endif // CELL_H
