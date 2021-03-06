#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include "calc.h"
#include <QLayout>


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    calc.isDigitOnDisplay = true;
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(plus_pressed()));
    connect(ui->pushButton_subtract, SIGNAL(released()), this, SLOT(minus_pressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(star_pressed()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(backslash_pressed()));
    connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(equals_pressed()));

    connect(ui->pushButton_dot, SIGNAL(released()), this, SLOT(dot_pressed()));
    connect(ui->pushButton_percent, SIGNAL(released()), this, SLOT(percent_pressed()));
    connect(ui->pushButton_plusMinus, SIGNAL(released()), this, SLOT(plusMinus_pressed()));
    connect(ui->pushButton_C, SIGNAL(released()), this, SLOT(C_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){
    qDebug() << "test_digit_pressed()";
    QPushButton *button = (QPushButton *) sender();
    double number;
    QString newLabel;

    if(calc.isDigitOnDisplay){   //jesli na wyswietlaczu jest liczba
        number = (ui->label->text() + button->text()).toDouble(); //to liczba z przycisku jest dodawana do tej juz wyswietlanej
    } else {
        number = button->text().toDouble();     //to liczba jest czytana tylko z przycisku
    }

    calc.comp2 = number;   //wpisanie aktualnie wyswietlanej liczby do 'comp2'
    newLabel = QString::number(number,'g',10);
    ui->label->setText(newLabel);
    calc.isDigitOnDisplay = true;
}

void MainWindow::dot_pressed(){
    qDebug() << "test_dot_pressed";
    if(calc.isDigitOnDisplay){   //jesli na wyswietlaczu jest liczba
        if(!(calc.isDotUsed)){
            ui->label->setText(ui->label->text() + (QString) ".");
            calc.isDigitOnDisplay = true;
            calc.isDotUsed = true;
        }
    }
}

void MainWindow::percent_pressed(){
    qDebug() << "test_percent_pressed()";
    QPushButton *button = (QPushButton *)sender();

    if(calc.isDigitOnDisplay){   //jezeli na ekranie jest liczba
        calc.comp1 = ui->label->text().toDouble();
    }
    calc.action = &percent;

    ui->label->setText(button->text());
    calc.isDigitOnDisplay = false;
    calc.isDotUsed = false;
}

void MainWindow::plusMinus_pressed(){
    qDebug() << "test_plusMinus_pressed()";
    if(calc.isDigitOnDisplay){
        double number = ui->label->text().toDouble();
        qDebug() << number;
        QString newLabel;
        calc.comp2 = number * (-1);

        newLabel = QString::number(calc.comp2, 'g', 10);
        ui->label->setText(newLabel);
    }
}

void MainWindow::C_pressed(){
    qDebug() << "test_C_pressed";
    ui->label->setText("");
    calc.isDigitOnDisplay = false;
    calc.isDotUsed = false;
    calc.comp1 = 0;
    calc.comp2 = 0;
    calc.action = 0;
}

void MainWindow::plus_pressed(){
    qDebug() << "test_plus_pressed()";
    QPushButton *button = (QPushButton *)sender();

    if(calc.isDigitOnDisplay){   //jezeli na ekranie jest liczba
        calc.comp1 = ui->label->text().toDouble();
    }
    calc.action = &add;

    ui->label->setText(button->text());
    calc.isDigitOnDisplay = false;
    calc.isDotUsed = false;
}

void MainWindow::minus_pressed(){
    qDebug() << "test_minus_pressed()";
    QPushButton *button = (QPushButton *)sender();
    if(calc.isDigitOnDisplay){   //jezeli na ekranie jest liczba
        calc.comp1 = ui->label->text().toDouble();
    }
    calc.action = &subtract;

    ui->label->setText(button->text());
    calc.isDigitOnDisplay = false;
    calc.isDotUsed = false;
}

void MainWindow::star_pressed(){
    qDebug() << "test_star_pressed()";
    QPushButton *button = (QPushButton *)sender();
    if(calc.isDigitOnDisplay){   //jezeli na ekranie jest liczba
        calc.comp1 = ui->label->text().toDouble();
    }
    calc.action = &multiply;

    ui->label->setText(button->text());
    calc.isDigitOnDisplay = false;
    calc.isDotUsed = false;
}

void MainWindow::backslash_pressed(){
    qDebug() << "test_backslash_pressed()";
    QPushButton *button = (QPushButton *)sender();

    if(calc.isDigitOnDisplay){   //jezeli na ekranie jest liczba
        calc.comp1 = ui->label->text().toDouble();
    }
    calc.action = &divide;

    ui->label->setText(button->text());
    calc.isDigitOnDisplay = false;
    calc.isDotUsed = false;
}

void MainWindow::equals_pressed(){
    //QPushButton *but = new QPushButton(ui->widget);   //tak stworzylem dynamicznie widget
//    but->show();                                      //
   // QPushButton *but = new QPushButton(this->centralWidget());
   // but->setVisible(true);

    qDebug() << "test_equals_pressed()";
    QString newLabel;
    if(calc.isDigitOnDisplay){     //jesli na ekranie jest liczba

        if(calc.action){  //jezeli jest zapisana jakas akcja
            calc.comp1 = calc.action(calc.comp1, calc.comp2);   //wykonanie odpowiedniego dzialania
            newLabel = QString::number(calc.comp1, 'g', 10);
            ui->label->setText(newLabel);
            calc.isDotUsed = false;
        }
    }
}
