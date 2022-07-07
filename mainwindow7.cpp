#include "mainwindow7.h"
#include "ui_mainwindow7.h"

MainWindow7::MainWindow7(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow7)
{
    ui->setupUi(this);
}

MainWindow7::~MainWindow7()
{
    delete ui;
}

void MainWindow7::on_pushButton_2_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow9 *m = new MainWindow9;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow7::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow6 *m = new MainWindow6;
    m->show();
    //Cerrando esta ventana
    this->close();
}
