#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"


#include <QDebug>

MainWindow::MainWindow(QWidget *parent, double comp1, double comp2, double  (*action)(double, double), bool operation) :
    QMainWindow(parent),
    comp1(comp1),
    comp2(comp2),
    action(action),
    operation(operation),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){
//    QPushButton *b = new QPushButton;
//    b->setText("jajajajjajjajjajajajja");
//    b->show();
//    b->setGeometry();

    qDebug() << "test_digit_pressed()";

    QPushButton *button = (QPushButton *) sender();
    double number;
    QString newLabel;

    if(operation){   //jesli w pamieci jest nowa operacja
        number = button->text().toDouble();     //to liczba jest czytana tylko z przycisku
    } else {
        number = (ui->label->text() + button->text()).toDouble(); //to liczba z przycisku jest dodawana do tej juz wyswietlanej
    }

    newLabel = QString::number(number,'g',15);
    ui->label->setText(newLabel);
    operation = false;

}

void MainWindow::plus_pressed(){
    qDebug() << "test_plus_pressed()";
    QPushButton *button = (QPushButton *)sender();

    if(!operation){   //jezeli nie ma operacji w pamieci
        comp1 = ui->label->text().toDouble();
    }
    action = &add;

    ui->label->setText(button->text());
    operation = true;
}

void MainWindow::minus_pressed(){
    qDebug() << "test_minus_pressed()";
    QPushButton *button = (QPushButton *)sender();
    if(!operation){   //jezeli nie ma operacji w pamieci
        comp1 = ui->label->text().toDouble();
    }
    action = &subtract;

    ui->label->setText(button->text());
    operation = true;
}

void MainWindow::star_pressed(){
    qDebug() << "test_star_pressed()";
    QPushButton *button = (QPushButton *)sender();
    if(!operation){   //jezeli nie ma operacji w pamieci
        comp1 = ui->label->text().toDouble();
    }
    action = &multiply;

    ui->label->setText(button->text());
    operation = true;
}

void MainWindow::backslash_pressed(){
    qDebug() << "test_backslash_pressed()";
    QPushButton *button = (QPushButton *)sender();
    if(!operation){   //jezeli nie ma operacji w pamieci
        comp1 = ui->label->text().toDouble();
    }
    action = &divide;

    ui->label->setText(button->text());
    operation = true;
}

void MainWindow::equals_pressed(){
    qDebug() << "test_equals_pressed()";

    QString newLabel;

    comp2 = ui->label->text().toDouble();   //wpisanie aktualnie wyswietlanej liczby do 'comp2'
    comp1 = action(comp1, comp2);   //wykonanie odpowiedniego dzialania

    newLabel = QString::number(comp1, 'g', 15);
    ui->label->setText(newLabel);

}
