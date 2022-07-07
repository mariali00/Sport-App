#include "mainwindow14.h"
#include "ui_mainwindow14.h"

MainWindow14::MainWindow14(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow14)
{
    ui->setupUi(this);

}

MainWindow14::~MainWindow14()
{
    delete ui;
}

void MainWindow14::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow12 *m = new MainWindow12;
    m->show();
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    //Cerrando esta ventana
    this->close();
}

void MainWindow14::on_pushButton_2_clicked()
{
    QString nombre = ui->comboBox->currentText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");


    QString idgrupo;
    QString idalumno;
    if(db.open())
    {
        QSqlQuery query;
        //obteniendo iddgrupo y idestudiante que se va a eliminar
        if(query.exec("SELECT ESTUDIANTE.idestudiante,grupo.idgrupo "
                      "FROM GRUPO,ESTUDIANTE,grupo_tiene_estudiante, carrera "
                      "WHERE GRUPO.idgrupo=grupo_tiene_estudiante.idgrupo AND  grupo.idcarrera=carrera.idcarrera and "
                      "estudiante.idestudiante=grupo_tiene_estudiante.idestudiante AND "
                      "CURSO='"+curso+"' AND CARRERA.nombre ='"+carrera+"' AND ANNO='"+anno+"' AND ASIGNATURA='"+asignatura+"'"
                      "AND NOMBREGRUPO='"+grupo+"' AND ESTUDIANTE.NOMBRE='"+nombre+"'"))
        {
            query.next();
            idalumno = query.value(0).toString();
            idgrupo = query.value(1).toString();
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo localizar a este estudiante");
        }
        if(!query.exec("delete from estudiante where idestudiante="+idalumno))
        {
            QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudo borrar de los registros a este estudiante");
            qDebug() << query.lastError();
        }
        if(!query.exec("delete from grupo_tiene_estudiante where idestudiante="+idalumno+" and idgrupo="+idgrupo))
        {
            QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudo borrar la matricula del estudiante en el grupo");
            qDebug() << query.lastError();
        }
        if(!query.exec("delete from estudiante_tiene_cf where idestudiante="+idalumno))
        {
            QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudieron borrar las  capacidades fisicas del estudiante");
            qDebug() << query.lastError();
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudieron abrir los registros");
    }

    //Abriendo la ventana siguiente
    MainWindow12 *m = new MainWindow12;
    m->show();
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    //Cerrando esta ventana
    this->close();
}

void MainWindow14::setAlumnos()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if(db.open())
    {
        QSqlQuery query;
        //mostrando los estudiantes que se pueden eliminar
        if(query.exec("select estudiante.nombre "
                      "from grupo, estudiante, grupo_tiene_estudiante, carrera "
                      "where carrera.idcarrera=grupo.idcarrera and estudiante.idestudiante=grupo_tiene_estudiante.idestudiante and grupo_tiene_estudiante.idgrupo=grupo.idgrupo and "
                      "carrera.nombre='"+carrera+"' and curso='"+curso+"' and anno='"+anno+"' and asignatura='"+asignatura+"' and nombregrupo='"+grupo+"'"))
        {
            while(query.next()) ui->comboBox->addItem(query.value(0).toString());
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudieron seleccionar los estudiantes");

        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudo abrir la lista de datos");
    }
    db.close();
}
