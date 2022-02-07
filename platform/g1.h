#ifndef G1_H
#define G1_H

#include <QDialog>

namespace Ui {
class g1;
}

class g1 : public QDialog
{
    Q_OBJECT

public:
    explicit g1(QWidget *parent = nullptr);
    ~g1();

   bool isaccepted();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::g1 *ui;
      bool play;
};

#endif // G1_H
