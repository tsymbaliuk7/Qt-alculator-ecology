#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Калькулятор викидів речовин");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double Q, S, n1, n2, b;
    QString Q_s = ui->lineEdit_2->text();
    Q = Q_s.toDouble();
    QString S_s = ui->lineEdit->text();
    S = S_s.toDouble();
    QString N1_s = ui->lineEdit_3->text();
    n1 = N1_s.toDouble();
    QString N2_s = ui->lineEdit_4->text();
    n2 = N2_s.toDouble();
    QString B_s = ui->lineEdit_5->text();
    b = B_s.toDouble();
    if(Q==0 && S==0 && n1==0 && n2==0 && b==0){
        ui->label_9->setText("Ведіть потрібні дані");
    }

    else if(S > 100){
         ui->label_9->setText("Неправильне значення відсотка");
    }
    else if(n1 > 1 || n2 > 1){
         ui->label_9->setText("Неправильне значення коефіцієнту");
    }
    else {
        double res = (double(pow(10, 6))/Q)*((2*S)/100)*(1-n1)*(1-n2*b);
        ui->label_9->setText(QString::number(res));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    double C, Q, e, k;
    QString C_s = ui->lineEdit_6->text();
    C = C_s.toDouble();
    QString Q_s = ui->lineEdit_7->text();
    Q = Q_s.toDouble();
    QString E_s = ui->lineEdit_8->text();
    e = E_s.toDouble();
    QString K_s = ui->lineEdit_10->text();
    k = K_s.toDouble();
    if(k==0 && C==0 && Q==0 && e==0){
        ui->label_17->setText("Ведіть потрібні дані");
    }
    else if(C > 100 || e>100){
         ui->label_17->setText("Неправильне значення відсотка");
    }
    else if(k!=0 && e!=0){
        double res = 3.67*k*e;
        ui->label_17->setText(QString::number(res));
    }
    else{
        double res = (double(44)/12)*((C)/100)*(double(pow(10, 6))/Q)*e;
        ui->label_17->setText(QString::number(res));
    }
}
