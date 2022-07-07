#include "mainwindow13.h"
#include "ui_mainwindow13.h"

MainWindow13::MainWindow13(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow13)
{
    ui->setupUi(this);
}

MainWindow13::~MainWindow13()
{
    delete ui;
}

void MainWindow13::on_pushButton_2_clicked()
{
    //adquiriendo dato
    QString nombre = ui->lineEdit->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if(db.open())
    {
        QSqlQuery query;
        //calculando el id del grupo donde se debe insertar el alumno
        QString idgrupo;
        if(query.exec("select idgrupo from grupo,carrera "
                      "where grupo.idcarrera= carrera.idcarrera and carrera.nombre='"+carrera+"' and anno='"+anno+"' and curso = '"+curso+"' and asignatura='"+asignatura+"' and nombregrupo='"+grupo+"'"))
        {
            query.next();
            idgrupo = query.value(0).toString();
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo resolver la informacion del grupo");
        }
        //insertando estudiante en su tabla
        if(!query.exec("insert into estudiante(nombre) values('"+nombre+"')"))
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo resolver la informacion del estudiante");
        }
        //buscando el id de ese estudiante
        QString idalumno;
        if(query.exec("select idestudiante from estudiante"))
        {
            while(query.next()) idalumno = query.value(0).toString();
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo seleccionar al ultimo estudiante de la lista");
        }
        //insertando la informacion en la tabla grupo_tiene_estudiante
        qDebug() << idgrupo << " " << idalumno;
        if(!query.exec("insert into grupo_tiene_estudiante(idgrupo,idestudiante) values("+idgrupo+","+idalumno+")"))
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo insertar el dato en el registro");
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudo obtener el registro");
    }




    //Abriendo la ventana siguiente
    MainWindow12 *m = new MainWindow12;
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    m->setTitleGrupo();
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow13::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow12 *m = new MainWindow12;
    m->curso = curso;
    m->carrera = carrera;
    m->anno = anno;
    m->grupo = grupo;
    m->asignatura = asignatura;
    m->setTitleGrupo();
    m->show();
    //Cerrando esta ventana
    this->close();
}
