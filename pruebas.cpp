#include "pruebas.h"
#include "ui_pruebas.h"

pruebas::pruebas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pruebas)
{
    ui->setupUi(this);


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    //seleccionando alumnos del grupo dado
    if(db.open())
    {
        QSqlQuery query;
        if(query.exec("select * from alumnos"))
        {
            while(query.next())
            {
                QString id = query.value(0).toString();
                QString nombre = query.value(2).toString();
                QString sexo = query.value(3).toString();

                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

                QTableWidgetItem *iditem = new QTableWidgetItem(id);
                QTableWidgetItem *nombreitem = new QTableWidgetItem(nombre);
                QTableWidgetItem *sexoitem = new QTableWidgetItem(sexo);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,iditem);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,nombreitem);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,sexoitem);
            }
        }
    }
}

pruebas::~pruebas()
{
    delete ui;
}
