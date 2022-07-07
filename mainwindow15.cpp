#include "mainwindow15.h"
#include "ui_mainwindow15.h"

MainWindow15::MainWindow15(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow15)
{
    ui->setupUi(this);
}

MainWindow15::~MainWindow15()
{
    delete ui;
}

void MainWindow15::on_pushButton_clicked()
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

void MainWindow15::on_pushButton_2_clicked()
{
    if(ui->comboBox_2->currentText() == "" ||
       ui->lineEdit_2->text() == "" ||
       ui->lineEdit_3->text() == "" ||
       ui->lineEdit_4->text() == "" ||
       ui->lineEdit_5->text() == "" ||
       ui->lineEdit_6->text() == "" ||
       ui->lineEdit_7->text() == "" ||
       ui->lineEdit_8->text() == "" ||
       ui->lineEdit_9->text() == "" ||
       ui->lineEdit_10->text() == "" ||
       ui->lineEdit_11->text() == "" ||
       ui->lineEdit_12->text() == ""
            )
    {
        QMessageBox::information(this,"Campos sin rellenar","No pueden haber campos sin rellenar");
        return;
    }
    else
    {

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("data.db");
        QString nombre = ui->comboBox->currentText();
        QString sexo = ui->comboBox_2->currentText();
        QString edad = ui->lineEdit_11->text();
        QString peso = ui->lineEdit_2->text();
        QString altura = ui->lineEdit_3->text();
        QString perimetro_cintura = ui->lineEdit_4->text();
        QString flexibilidad = ui->lineEdit_5->text();
        QString fuerza_de_brazo = ui->lineEdit_6->text();
        QString fuerza_abdominal = ui->lineEdit_7->text();
        QString fuerza_explosiva_piernas = ui->lineEdit_8->text();
        QString velocidad = ui->lineEdit_9->text();
        QString resistencia = ui->lineEdit_10->text();
        QString presion = ui->lineEdit_12->text();

        QString idalumno;

        //actualizando la tabla
        if(db.open())
        {
            QSqlQuery query;
            //obteniendo iddgrupo y idestudiante que se va a actualizar
            if(query.exec("SELECT ESTUDIANTE.idestudiante "
                          "FROM GRUPO,ESTUDIANTE,grupo_tiene_estudiante,carrera "
                          "WHERE GRUPO.idgrupo=grupo_tiene_estudiante.idgrupo AND "
                          "estudiante.idestudiante=grupo_tiene_estudiante.idestudiante AND carrera.idcarrera=grupo.idcarrera and "
                          "CURSO='"+curso+"' AND CARRERA.nombre='"+carrera+"' AND ANNO='"+anno+"' AND "
                          "ASIGNATURA='"+asignatura+"' AND NOMBREGRUPO='"+grupo+"' AND ESTUDIANTE.NOMBRE='"+nombre+"'"))
            {
                query.next();
                idalumno = query.value(0).toString();
            }
            if(!query.exec("update estudiante set sexo='"+sexo+"',edad="+edad+",peso='"+peso+"',altura='"+altura+"', cintura='"+perimetro_cintura+ "',presion='" + presion + "'"
                           "where idestudiante='"+idalumno+"'"))
            {
                QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                return;
            }
            //, flexibilidad="+flexibilidad+", planchas="+fuerza_de_brazo+", abdominales="+fuerza_abdominal+", salto='"+fuerza_explosiva_piernas+"',
            //velocidad='"+velocidad+"', resistencia='"+resistencia+"' "
            //"where idestudiante='"+idalumno+"'"
            int ctdad;
            bool inserccion=1;
            if(query.exec("select count(idestudiante) from estudiante_tiene_cf "))
            {
                 ctdad= query.value(0).toInt();
            }
            if(!query.exec("select idestudiante from estudiante_tiene_cf "))
            {

                for(int i=0;i<ctdad;i++)
                {
                    if(query.value(i)== idalumno)
                    {
                        inserccion=0;
                        break;
                    }
                }
            }
            QDate actual= QDate::currentDate();
            QString fecha= actual.toString("dd/MM/yyyy");
            if(inserccion)
            {

                if(!query.exec("insert into estudiante_tiene_cf(idCF,idestudiante,valor,periodo) values(1,"+idalumno+", "+flexibilidad+",'"+fecha+"')"))
                {
                    qDebug()<< query.lastError();
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la inserccion.");
                    return;
                }
                 if(!query.exec("insert into estudiante_tiene_cf(idCF,idestudiante,valor,periodo) values(2,"+idalumno+", "+fuerza_de_brazo+",'"+fecha+"')"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la inserccion.");
                    qDebug()<< query.lastError();
                    return;
                }
                 if(!query.exec("insert into estudiante_tiene_cf(idCF,idestudiante,valor,periodo) values(3,"+idalumno+", "+fuerza_abdominal+",'"+fecha+"')"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la inserccion.");
                    qDebug()<< query.lastError();
                    return;
                }
                 if(!query.exec("insert into estudiante_tiene_cf(idCF,idestudiante,valor,periodo) values(4,"+idalumno+", "+fuerza_explosiva_piernas+",'"+fecha+"')"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la inserccion.");
                    qDebug()<< query.lastError();
                    return;
                }
                 if(!query.exec("insert into estudiante_tiene_cf(idCF,idestudiante,valor,periodo) values(5,"+idalumno+", "+velocidad+",'"+fecha+"')"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la inserccion.");
                    qDebug()<< query.lastError();
                    return;
                }
                 if(!query.exec("insert into estudiante_tiene_cf(idCF,idestudiante,valor,periodo) values(6,"+idalumno+", "+resistencia+",'"+fecha+"')"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la inserccion.");
                    qDebug()<< query.lastError();
                    return;
                }
            }
            else {
                if(!query.exec("update estudiante_tiene_cf set valor = '"+ flexibilidad+"'"
                           "where idestudiante = '"+idalumno+"' and idCF = 1"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                    qDebug()<< query.lastError();
                    return;
                }
                if(!query.exec("update estudiante_tiene_cf set valor = '"+ fuerza_de_brazo+"'"
                               "where idestudiante = '"+idalumno+"' and idCF = 2"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                    return;
                }
                if(!query.exec("update estudiante_tiene_cf set valor = '"+ fuerza_abdominal+"'"
                               "where idestudiante = '"+idalumno+"' and idCF = 3"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                    return;
                }
                if(!query.exec("update estudiante_tiene_cf set valor = '"+ fuerza_explosiva_piernas+"'"
                               "where idestudiante = '"+idalumno+"' and idCF = 4"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                    return;
                }
                if(!query.exec("update estudiante_tiene_cf set valor = '"+ velocidad+"'"
                               "where idestudiante = '"+idalumno+"' and idCF = 5"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                    return;
                }
                if(!query.exec("update estudiante_tiene_cf set valor = '"+ resistencia+"'"
                               "where idestudiante = '"+idalumno+"' and idCF = 6"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No fue posible efectuar la actualizacion.");
                    return;
                }
            }
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE APERTURA","No se pudo acceder a los datos requeridos");
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
}

void MainWindow15::setAlumnos()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if(db.open())
    {
        QSqlQuery query;
        //mostrando los alumnos del grupo
        if(query.exec("select estudiante.nombre "
                      "from grupo, estudiante, grupo_tiene_estudiante, carrera "
                      "where estudiante.idestudiante=grupo_tiene_estudiante.idestudiante and grupo_tiene_estudiante.idgrupo=grupo.idgrupo and grupo.idcarrera= carrera.idcarrera and "
                      "carrera.nombre='"+carrera+"' and curso='"+curso+"' and anno='"+anno+"' and asignatura='"+asignatura+"' and nombregrupo='"+grupo+"'"))
        {

            while(query.next())
            {
                ui->comboBox->addItem(query.value(0).toString());
            }
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudieron localizar los datos");
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudo abrir la lista de datos");
    }

    db.close();
}
