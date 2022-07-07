#include "mainwindow8.h"
#include "ui_mainwindow8.h"

MainWindow8::MainWindow8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow8)
{
    ui->setupUi(this);
}

MainWindow8::~MainWindow8()
{
    delete ui;
}

void MainWindow8::on_pushButton_2_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow9 *m = new MainWindow9;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow8::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow6 *m = new MainWindow6;
    m->show();
    //Cerrando esta ventana
    this->close();
}
