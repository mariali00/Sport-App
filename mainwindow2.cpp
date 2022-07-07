#include "mainwindow2.h"
#include "ui_mainwindow2.h"
using namespace std;

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
    db.close();
}

void MainWindow2::on_pushButton_clicked()
{
    if(ui->lineEdit_3->text() == "" ||  ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
    {
        QMessageBox::critical(this,"Campos vacios","No pueden haber campos vacios");
    }

    if(ui->lineEdit_3->text() != ui->lineEdit_4->text())
    {
        QMessageBox::critical(this,"CONTRASENNA INCORRECTA","La confirmacion de contrasenna no coincide con la contrasenna");
        return ;
    }

    //Guardando configuracion de perfil
    string nombre = ui->lineEdit->text().toStdString() + " " + ui->lineEdit_2->text().toStdString();
    string contrasenna = ui->lineEdit_3->text().toStdString();
    string correo = ui->lineEdit_5->text().toStdString();
    ofstream fout("wet.txt");

    fout << nombre << endl << contrasenna << endl << correo;

    fout.close();



    //Abriendo la ventana siguiente
    MainWindow3 *m = new MainWindow3;
    m->show();
    //Cerrando esta ventana
    this->close();
}
