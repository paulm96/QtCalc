#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, double comp1 = 0, double comp2 = 0,
                        double (*action)(double, double) = 0, bool operation = false);
    ~MainWindow();

private:
    double comp1;
    double comp2;
    double (*action)(double, double);
    bool operation;
    Ui::MainWindow *ui;
    double memory;



private slots:
    void digit_pressed();
    void plus_pressed();
    void minus_pressed();
    void star_pressed();
    void backslash_pressed();
    void equals_pressed();

};

#endif // MAINWINDOW_H
