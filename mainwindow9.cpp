#include "mainwindow9.h"
#include "ui_mainwindow9.h"

MainWindow9::MainWindow9(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow9)
{
    ui->setupUi(this);
}

MainWindow9::~MainWindow9()
{
    delete ui;
}

void MainWindow9::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow6 *m = new MainWindow6;
    m->show();
    //Cerrando esta ventana
    this->close();
}
