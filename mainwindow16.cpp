#include "mainwindow16.h"
#include "ui_mainwindow16.h"
#include "util.h"
using namespace std;

MainWindow16::MainWindow16(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow16)
{

    ui->setupUi(this);


    ifstream fin("dry.txt");
    if(fin)
    {
        QFile file("dry.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

            QTextStream in(&file);
            QString nombre = in.readLine();
            sexoTabla = in.readLine();
            edadTabla = in.readLine();
            ui->label_2->setText(nombre);
            //disminuyendo el tamanno de la fuente empleada en el QLabel
            QFont F("Ubuntu Condensed",22,75,0);
            ui->label_2->setFont(F);
        }
        else
        {
            QMessageBox::critical(this,"ERROR","Error en la autenticacion");
        }
    }
    else
    {
        //Mostrando la ventana del perfil del estudiante
        MainWindow16p *m = new MainWindow16p;
        m->show();
        //Cerrando esta ventana
        this->close();
    }


    //LLenando la tabla
    actualizarTabla();
    //obteniendo fecha
    QString fecha="";
    QDate date = QDate::currentDate();
    fecha+=date.toString("dd.MM.yyyy");

    //si la ultima fecha es la actual deshabilitar el boton de agregar entrada
    if(ui->tableWidget->rowCount()!=0 && ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->text() != "" && ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->text() == fecha)
        ui->pushButton->setEnabled(false);

    if(ui->tableWidget->rowCount() == 0)
        ui->pushButton_2->setEnabled(false);
}

MainWindow16::~MainWindow16()
{
    delete ui;
}

void MainWindow16::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::EnterKeyDone)
    {
        QMessageBox::information(this,"TECLA PRESIONADA","ENTER PRESIONADO");
    }
    if(event->key() == Qt::BackButton)
    {
        QMessageBox::information(this,"TECLA PRESIONADA","BACK PRESIONADO");
    }
    if(event->key() == Qt::UpArrow)
    {
        QMessageBox::information(this,"TECLA PRESIONADA","FLECHA ARRIBA PRESIONADO");
    }
}

void MainWindow16::actualizarTabla()
{
    qDebug() << "actualizar tabla";
    //Limpiando la tabla
    ui->tableWidget->clearContents();
    while(ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);
    }

    //creando una conexion a la base datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //aqui se le dice la direccion de la base de datos a crear o cargar
    db.setDatabaseName("data.db");

    if(db.open())
    {
        QSqlQuery query;
        if(query.exec("select * from autoevaluacion"))
        {
            while(query.next())
            {
                  QString fechaTabla = query.value(0).toString();
                  QString flexibilidadTabla = query.value(1).toString();
                  QString planchasTabla = query.value(2).toString();
                  QString abdominalesTabla = query.value(3).toString();
                  QString saltoTabla = query.value(4).toString();
                  QString velocidadTabla = query.value(5).toString();
                  QString resistenciaTabla = query.value(6).toString();
                  QString control = query.value(7).toString();

                  ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

                  QTableWidgetItem *fechaitem = new QTableWidgetItem(fechaTabla);
                  QTableWidgetItem *flexibilidaditem = new QTableWidgetItem(flexibilidadTabla);
                  QTableWidgetItem *planchasitem = new QTableWidgetItem(planchasTabla);
                  QTableWidgetItem *abdominalesitem = new QTableWidgetItem(abdominalesTabla);
                  QTableWidgetItem *saltoitem = new QTableWidgetItem(saltoTabla);
                  QTableWidgetItem *velocidaditem = new QTableWidgetItem(velocidadTabla);
                  QTableWidgetItem *resistenciaitem = new QTableWidgetItem(resistenciaTabla);

                  CambiandoCelda = 0;



                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,fechaitem);
                  if(control == "SI")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setBackground(Qt::magenta);

                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,planchasitem);
                  Eval e;
                  if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && planchasTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->setBackground(Qt::yellow);
                  if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && planchasTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->setBackground(Qt::red);
                  if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && planchasTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->setBackground(Qt::green);

                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,flexibilidaditem);
                  if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && flexibilidadTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->setBackground(Qt::yellow);
                  if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && flexibilidadTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->setBackground(Qt::red);
                  if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && flexibilidadTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->setBackground(Qt::green);

                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,abdominalesitem);
                  if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && abdominalesTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->setBackground(Qt::yellow);
                  if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && abdominalesTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->setBackground(Qt::red);
                  if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && abdominalesTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->setBackground(Qt::green);

                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,saltoitem);
                  if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && saltoTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,4)->setBackground(Qt::yellow);
                  if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && saltoTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,4)->setBackground(Qt::red);
                  if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && saltoTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,4)->setBackground(Qt::green);

                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,velocidaditem);
                  if(edadTabla != "" && sexoTabla != "" && velocidadTabla != "")
                  {
                      switch (e.CategoriaVelocidad(edadTabla,sexoTabla,velocidadTabla)) {
                      case 1: ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)->setBackground(Qt::green);
                          break;
                      case 2: ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)->setBackground(Qt::blue);
                          break;
                      case 3: ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)->setBackground(Qt::yellow);
                          break;
                      case 4: ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)->setBackground(Qt::red);
                          break;
                      }
                  }

                  ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,resistenciaitem);
                  if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Aceptable" && resistenciaTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,6)->setBackground(Qt::yellow);
                  if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Necesita mejorar" && resistenciaTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,6)->setBackground(Qt::red);
                  if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Destacado" && resistenciaTabla != "")
                      ui->tableWidget->item(ui->tableWidget->rowCount()-1,6)->setBackground(Qt::green);


                  CambiandoCelda = 1;
            }
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No pudieron resolverse los datos necesarios (1)");
            qDebug() << query.lastError();
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudieron abrir los registros");
    }
    db.close();
}

void MainWindow16::on_pushButton_3_clicked()
{
    //Mostrando la ventana anterior
    MainWindow *m = new MainWindow;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow16::on_pushButton_clicked()
{
    //adquiriendo fecha actual
    QString fecha = "";
    QDate date = QDate::currentDate();
    fecha += date.toString("dd.MM.yyyy");

    //creando una conexion a la base datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //aqui se le dice la direccion de la base de datos a crear o cargar
    db.setDatabaseName("data.db");
    if(db.open())
    {
        QSqlQuery query;
        if(ui->checkBox->isChecked())
        {
            if(!query.exec("insert into autoevaluacion values('"+fecha+"','','','','','','','SI')"))
                QMessageBox::critical(this,"ERROR DE INSERCION","No se pudieron acceder a los registros (1)");
        }
        else
        {
            if(!query.exec("insert into autoevaluacion values('"+fecha+"','','','','','','','NO')"))
                QMessageBox::critical(this,"ERROR DE INSERCION","No se pudieron acceder a los registros (2)");
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudieron abrir los registros");
    }

    db.close();
    actualizarTabla();

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void MainWindow16::on_pushButton_2_clicked()
{

    //creando una conexion a la base datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //aqui se le dice la direccion de la base de datos a crear o cargar
    db.setDatabaseName("data.db");
    if(db.open())
    {
        QSqlQuery query;
        //obteniendo la ultima fecha registrada
        QString fecha;
        if(query.exec("select fecha from autoevaluacion"))
        {
            while(query.next()){}
            query.previous();
            fecha = query.value(0).toString();
        }
        else
        {
             QMessageBox::critical(this,"ERROR DE INSERCION","No se pudieron acceder a los registros");
        }
        //eliminando registro
        if(!query.exec("delete from autoevaluacion where fecha='"+fecha+"'"))
        {
               QMessageBox::critical(this,"ERROR DE ELIMINACION","No se pudo eliminar la entrada");
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudieron abrir los registros");
    }

    ui->tableWidget->removeRow(ui->tableWidget->rowCount()-1);

    db.close();

    ui->pushButton->setEnabled(true);
    if(ui->tableWidget->rowCount() == 0) ui->pushButton_2->setEnabled(false);
}


void MainWindow16::on_actionRestaurar_ajustes_predeterminados_triggered()
{
    QMessageBox::StandardButton confirmacion;
    confirmacion = QMessageBox::question(this,"ELIMINAR CONFIGURACION","Esta seguro de restaurar los ajustes predeterminados?", QMessageBox::Yes | QMessageBox::No);
    if(confirmacion == QMessageBox::No)
        return;

    //eliminando archivo del perfil
    if(remove("dry.txt")!=0)
    {
        QMessageBox::critical(this,"AJUSTES PREDETERMINADOS","No se pueden restablecer los ajustes\n"
                                                             "de la aplicacion. Si sigue teniendo\n"
                                                             "este mensaje puede probar con copiar\n"
                                                             "la aplicacion de nuevo");
    }

    //elimando datos de la tabla de autoevaluacion

    //creando una conexion a la base datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //aqui se le dice la direccion de la base de datos a crear o cargar
    db.setDatabaseName("data.db");
    if(db.open())
    {
        QSqlQuery query;
        if(!query.exec("delete from autoevaluacion"))
        {
            QMessageBox::critical(this,"AJUSTES PREDETERMINADOS","No se pueden restablecer los ajustes\n"
                                                                 "de la aplicacion. Si sigue teniendo\n"
                                                                 "este mensaje puede probar con copiar\n"
                                                                 "la aplicacion de nuevo");
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudieron abrir los registros");
    }


    //Creando la Base de Datos nuevamente
    DB database;
    if(!database.createDB())
    {
        QMessageBox::critical(this,"AJUSTES PREDETERMINADOS","No se pudieron crear los registros");
    }
    //Abriendo la ventana siguiente
    MainWindow16p *m = new MainWindow16p;
    m->show();
    //Cerrando esta ventana
    this->close();
    db.close();
}


void MainWindow16::on_tableWidget_cellChanged(int row, int column)
{
    if(CambiandoCelda)
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        //aqui se le dice la direccion de la base de datos a crear o cargar
        db.setDatabaseName("data.db");

        QString actualizacion = ui->tableWidget->item(row,column)->data(0).toString();

        if(db.open())
        {
            QSqlQuery query;
            QString fecha = ui->tableWidget->item(row,0)->data(0).toString();;

            switch (column) {
            case 1:
                if(!query.exec("update autoevaluacion set planchas=" + actualizacion + " where fecha='"+fecha+"'"))
                {
                    QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No se pudo actualizar esta tabla");
                }
                break;
            case 2:
                query.exec("update autoevaluacion set flexibilidad=" + actualizacion + " where fecha='"+fecha+"'");
                break;
            case 3:
                query.exec("update autoevaluacion set abdominales=" + actualizacion + " where fecha='"+fecha+"'");
                break;
            case 4:
                query.exec("update autoevaluacion set salto=" + actualizacion + " where fecha='"+fecha+"'");
                break;
            case 5:
                query.exec("update autoevaluacion set velocidad=" + actualizacion + " where fecha='"+fecha+"'");
                break;
            case 6:
                query.exec("update autoevaluacion set resistencia=" + actualizacion + " where fecha='"+fecha+"'");
                break;
            default:
                break;
            }
            actualizarTabla();

        }
        else
        {
            QMessageBox::critical(this,"ERROR DE ACTUALIZACION","No se pudieron actulizar estos datos (2)");
        }
    }

}
