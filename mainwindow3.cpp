#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);


    //deshabilitando el boton de ir a grupo verificando si la tabla grupo contiene entradas
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if(db.open())
    {
        QSqlQuery query;
        if(query.exec("select * from grupo"))
        {
            if(query.next())
            {
                ui->pushButton->setDisabled(0);
            }
            else
            {
                ui->pushButton->setDisabled(1);
            }
        }
        else
        {
            QMessageBox::critical(this,"","no se ejecuto query (1)");
        }
    }
    else
    {
        QMessageBox::critical(this,"","no se abrio la base de datos");
    }
    db.close();
}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow4 *m = new MainWindow4;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow3::on_pushButton_2_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow10 *m = new MainWindow10;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow3::on_pushButton_4_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow12p *m = new MainWindow12p;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow3::on_pushButton_3_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow *m = new MainWindow;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow3::on_pushButton_5_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow17 *m = new MainWindow17;
    m->show();
    //Cerrando esta ventana
    this->close();
}
