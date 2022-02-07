#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPropertyAnimation>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    QPropertyAnimation *animation2;
      QPropertyAnimation *animation3;
};
#endif // MAINWINDOW_H
