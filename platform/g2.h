#ifndef G2_H
#define G2_H

#include <QDialog>

namespace Ui {
class g2;
}

class g2 : public QDialog
{
    Q_OBJECT

public:
    explicit g2(QWidget *parent = nullptr);
    ~g2();
   bool isaccepted();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::g2 *ui;
    bool play;
};

#endif // G2_H
