#ifndef G3_H
#define G3_H

#include <QDialog>

namespace Ui {
class g3;
}

class g3 : public QDialog
{
    Q_OBJECT

public:
    explicit g3(QWidget *parent = nullptr);
    ~g3();
   bool isaccepted();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::g3 *ui;
    bool play;
};

#endif // G3_H
