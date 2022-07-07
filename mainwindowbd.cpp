#include "mainwindowbd.h"
#include "ui_mainwindowbd.h"

MainWindowBD::MainWindowBD(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowBD)
{
    ui->setupUi(this);

    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("PRUEBAS.DB");

    if(DB.open())
    {
        QSqlQuery Q;

        if(Q.exec("CREATE TABLE `alumno` (`nombre`	TEXT,`edad`	INTEGER,`sexo`	TEXT,PRIMARY KEY(`nombre`));"))
        {
            QMessageBox::information(this,"OKOKOKOKOKOK","GOOD GOOD!!!");
        }
        else
        {
            QMessageBox::warning(this,"TABLE NOT CREATED","TABLE HAVE NOT BEEN CREATED!!!");
        }

    }
    else
    {
        QMessageBox::warning(this,"NOT CONNECTED","THE CONECTION HAVE NOT BEEN ESTABLISHED!!!");
    }
}

MainWindowBD::~MainWindowBD()
{
    delete ui;
}

void MainWindowBD::on_pushButton_clicked()
{

}
