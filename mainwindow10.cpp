#include "mainwindow10.h"
#include "ui_mainwindow10.h"

MainWindow10::MainWindow10(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow10)
{
    ui->setupUi(this);

}

MainWindow10::~MainWindow10()
{
    delete ui;
}

void MainWindow10::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "" ||
       ui->lineEdit_4->text() == "" ||
       ui->lineEdit_4->text() == "")
    {
        QMessageBox::critical(this,"ERROR DE ENTRADA","No pueden haber campos sin rellenar");
        return;
    }

    //obteniendo datos para insertar
    QString carrera = ui->lineEdit_2->text();
    QString anno = ui->comboBox->currentText();
    QString curso = ui->lineEdit_4->text();
    QString grupo = ui->lineEdit->text();
    QString asignatura = ui->comboBox_2->currentText();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    QString ultima_carrera="";
    QString ultimo_grupo="";

    if(db.open())
    {

        QSqlQuery query;
        //tabla carrera
        if(query.exec("insert into carrera(nombre) values('"+carrera+ "' )"))
        {
            if(query.exec("select grupo.idgrupo from grupo"))
            {
                while(query.next())
                {
                    ultima_carrera = query.value(0).toString();
                     qDebug() <<"ultima carrera"<< ultima_carrera;
                }
            }
            else
            {
                QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo guardar esta informacion1.");
            }
        }
        else
        {
            QMessageBox::critical(this,"OPERACION NO COMPLETADA","No se pudieron insertar estos datos2");
            return;
         }
        QString idc;
        query.exec("select idcarrera from carrera where nombre = '" + carrera+ "';");
        qDebug() <<"select idcarrera from carrera where nombre = '" + carrera+ "';";
        if(query.first())
        {
            idc=query.value(0).toString();
            qDebug() <<"idc"<< idc;
        }
         //agregando a la tabla grupo el grupo
        qDebug() << "insert into grupo(nombregrupo,idcarrera,curso,asignatura,anno) values('"+grupo +"',"+idc + ",'"+curso+"','"+asignatura+  "','" +anno+ "')";
        if(query.exec("insert into grupo(nombregrupo,idcarrera,curso,asignatura,anno) values('"+grupo +"',"+idc + ",'"+curso+"','"+asignatura+  "','" +anno+ "');"))
        {
            //hallando el indice del grupo que se ha insertado
            if(query.exec("select grupo.idgrupo from grupo"))
            {
                while(query.next())
                {
                    ultimo_grupo = query.value(0).toString();
                }
            }
            else
            {
                QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo guardar esta informacion3.");
            }
        }
        else
        {
            QMessageBox::critical(this,"OPERACION NO COMPLETADA","No se pudieron insertar estos datos4");
            qDebug() << query.lastError();
            return;
        }


    }
    else
    {
        QMessageBox::critical(this,"BASE DE DATOS NO ABIERTA","La base de datos no pudo ser abierta5");
        return;
    }



    //Abriendo la ventana siguiente
    MainWindow11 *m = new MainWindow11();
    m->idgrupo = ultimo_grupo;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow10::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow3 *m = new MainWindow3;
    m->show();
    //Cerrando esta ventana
    this->close();
}
