#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Adquiriendo Perfil del Profesor
    ifstream fin("wet.txt");
    if(fin)
    {
        QFile file("wet.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QString nombre = in.readLine();
            QString mensaje = "BIENVENIDO \n" + nombre;
            ui->label->setText(mensaje);
            //disminuyendo el tamanno de la fuente empleada en el QLabel
            QFont F("Ubuntu Condensed",22,75,0);
            ui->label->setFont(F);
        }
        else
        {
            QMessageBox::critical(this,"ERROR","Error en la autenticacion");
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR","No se pudo cargar la configuracion de la autenticacion");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::on_pushButton_clicked()
{
    //adquiriendo contrassenna real
    QString pass;
    QFile file("wet.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        pass = in.readLine();
        pass = in.readLine();
    }
    else
    {
         QMessageBox::critical(this,"ERROR","Error en la autenticacion");
         return;
    }

    //adquiriendo entrada de contrasenna del ususario
    QString pass_entry = ui->lineEdit->text();


    //QString Qpass(pass);
     //QMessageBox::information(this,"pass",Qpass);


    if(pass_entry == pass)
    {
        //creando una conexion a la base datos
        db = QSqlDatabase::addDatabase("QSQLITE");
        //aqui se le dice la direccion de la base de datos a crear o cargar
        db.setDatabaseName("data.db");
        if(db.open())
        {
            QSqlQuery query;
            //creando tablas de la base de datos si no estan definidas
            if(!query.exec("create table if not exists estudiante("
                           "idestudiante integer primary key autoincrement,"
                           "nombre text,"
                           "sexo text,"
                           "edad integer,"
                           "peso real,"
                           "altura real,"
                           "cintura real"


                           ");") && query.exec("create table if not exists grupo("
                                               "idgrupo integer primary key autoincrement, "
                                               "nombregrupo text,"
                                               "idcarrera integer,"
                                               "curso text,"
                                               "asignatura text,"
                                               "anno text);")
                                   && query.exec("create table if not exists carrera("
                                                "idcarrera integer primary key autoincrement,"
                                                 "nombre text"
                                                 ");")
                                    && query.exec("create table if not exists grupo_tiene_est("
                                                  "idgrupo integer primary key,"
                                                  "idestudiante integer primary key"
                                                   ");")
                                    && query.exec("create table if not exists capacidad_fisica("
                                                  "idCF integer primary key autoincrement,"
                                                   "nombre text "
                                                   ");")
                                    && query.exec("create table if not exists estudiante_tiene_cf("
                                                  "idCF integer primary key,"
                                                   "idestudiante integer primary key, "
                                                   "valor real,"
                                                   "presion text,"
                                                   "periodo text"
                                                   ");")

                    )

            {
                //caso de que no se puedan crear las tablas se finaliza la ejecucion del programa
                QMessageBox::critical(this,"Error","No se pudieron crear las tablas");
                this->close();
                return;
            }
        }
        else
        {
            QMessageBox::critical(this,"Error","No se pudo abrir o crear la base de datos");
        }
        //Abriendo la ventana siguiente
        MainWindow3 *m = new MainWindow3;
        m->show();
        //Cerrando esta ventana
        this->close();
    }
    else
    {
        QMessageBox::critical(this,"CLAVE INCORRECTA","La clave ingresada no es la correcta");
        ui->lineEdit->setText("");
    }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::information(this,"Acerca de",""
                                              "Educación Física UO\n"
                                              "Creadores:\n"
                                              "Mariali Guzmán Adán\n"
                                              "Carlos Alberto Rodríguez Losada\n"
                                              "Version 1.0\n"
                                              "Fecha de lanzamiento: 1/3/2020\n"
                                              "\n"
                                              "Aplicación creada para la gestión de las\n"
                                              "capacidades física de los estudiantes de la\n"
                                              "Universidad de Oriente. Está orientada\n"
                                              "a profesores de Educación Física.\n"
                                              "\n"
                                              "Página de la Universidad de Oriente:\n"
                                              "http://uo.edu.cu");
}



