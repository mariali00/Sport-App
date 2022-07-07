#include "mainwindow12.h"
#include "ui_mainwindow12.h"

MainWindow12::MainWindow12(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow12)
{
    ui->setupUi(this);
}

MainWindow12::~MainWindow12()
{
    delete ui;
}

void MainWindow12::on_pushButton_2_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow13 *m = new MainWindow13;
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow12::on_pushButton_3_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow14 *m = new MainWindow14;
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    m->setAlumnos();
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow12::on_pushButton_4_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow15 *m = new MainWindow15;
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    m->setAlumnos();
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow12::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow3 *m = new MainWindow3;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow12::setTitleGrupo()
{
    ui->label->setText(carrera + ", " + grupo);
}
