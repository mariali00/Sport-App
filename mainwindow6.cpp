#include "mainwindow6.h"
#include "ui_mainwindow6.h"

MainWindow6::MainWindow6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow6)
{
    ui->setupUi(this);
}

MainWindow6::~MainWindow6()
{
    delete ui;
}

void MainWindow6::on_pushButton_2_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow7 *m = new MainWindow7;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow6::on_pushButton_3_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow8 *m = new MainWindow8;
    m->show();
    //Cerrando esta ventana
    this->close();
}
