#include "mainwindow11.h"
#include "ui_mainwindow11.h"

MainWindow11::MainWindow11(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow11)
{
    ui->setupUi(this);

}

MainWindow11::~MainWindow11()
{
    delete ui;
}

void MainWindow11::on_pushButton_2_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow3 *m = new MainWindow3;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow11::on_pushButton_clicked()
{
    QMessageBox::StandardButton confirmacion;
    confirmacion = QMessageBox::question(this,"GRUPO NO GUARDADO","El grupo no se ha guardado y se perderán sus datos,\nestá seguro de ir a la ventanta anterior ?", QMessageBox::Yes | QMessageBox::No);
    if(confirmacion == QMessageBox::No)
        return;

    //si se oprime este boton solo puede significar que el usuario ya no quiere crear el grupo
    //se debe borrar la tabla que se acabo de insertar con todos sus estudiantes si tiene

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if(db.open())
    {
        QSqlQuery query;
        //eliminando el grupo
        if(!query.exec("delete from grupo where idgrupo="+idgrupo))
        {
            QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudo eliminar el grupo");
            qDebug() << query.lastError();
        }
        //obteniendo el id de los estudiantes de ese grupo
        list<QString> id;
        if(query.exec("select idestudiante from grupo_tiene_estudiante where idgrupo="+idgrupo))
        {
            while(query.next()) id.push_back(query.value(0).toString());
        }
        //eliminando esta relacion
        if(!query.exec("delete from grupo_tiene_estudiante where idgrupo="+idgrupo))
        {
            QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudo eliminar la relacion del grupo con los estudiantes");
        }
        //eliminando a los estudiantes
        for(auto it : id) if(!query.exec("delete from estudiante where idestudiante="+it)) QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudieron eliminar los estudiantes");
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudo acceder al registro para borrarlo");
    }


    //Abriendo la ventana siguiente
    MainWindow10 *m = new MainWindow10;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow11::on_pushButton_3_clicked()
{
    QString nombre = ui->lineEdit->text();


    //agregando datos a la base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if(db.open())
    {
        QSqlQuery query;
        //agregando dato a la tabla estudiante
        if(!query.exec("insert into estudiante(nombre) values('"+nombre+"');"))
        {
            QMessageBox::critical(this,"OPERACION NO COMPLETADA","El dato que intenta insertar no fue insertado en el grupo");
        }
        //buscando id de ese estudiante que se agrego
        QString ultimoidestudiante = "";
        if(query.exec("select idestudiante from estudiante"))
        {
            while(query.next())
            {
                ultimoidestudiante = query.value(0).toString();
            }
        }
        else
        {
            qDebug() << "No se pudo encontrar el id del estudiante insertado";
        }
        //QDate actual= QDate::currentDate();
        //QString fecha= actual.toString("dd/MM/yyyy");
        //agregando dato a la tabla grupotienealumnos
        if(!query.exec("insert into grupo_tiene_estudiante(idgrupo,idestudiante) values("+idgrupo+","+ultimoidestudiante+")"))
        {
           qDebug() << query.lastError();
            QMessageBox::critical(this,"ERROR EN LA INSERCION","No se pudo guardar la relacion grupo tiene estudiante");
        }
        //Mostrando el grupo en el QTableView
        //haciendo una consulta para tener el ultimo id de estudiante
        if(!query.exec("select idestudiante from grupo_tiene_estudiante"))
        {
            QMessageBox::critical(this,"PROBLEMA DE VISUALIZACION","No se puede mostrar informacion del grupo");
        }
        QString idultimoalumno = "";
        while(query.next())
        {
            idultimoalumno = query.value(0).toString();
        }
        if(query.exec("select nombre from estudiante where idestudiante="+idultimoalumno))
        {
            query.next();
            QString nombreTabla = query.value(0).toString();
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            QTableWidgetItem *item = new QTableWidgetItem(nombreTabla);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,item);
            ui->lineEdit->setText("");
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo seleccionar el ultimo alumno insertado");
        }

    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudieron abrir los registros");
    }
}
