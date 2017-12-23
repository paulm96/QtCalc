#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calc.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Calc calc;



private slots:
    void digit_pressed();
    void plus_pressed();
    void minus_pressed();
    void star_pressed();
    void backslash_pressed();
    void equals_pressed();
    void dot_pressed();
    void C_pressed();
    void plusMinus_pressed();
    void percent_pressed();

};

#endif // MAINWINDOW_H
