#include "mainwindow12p.h"
#include "ui_mainwindow12p.h"

MainWindow12p::MainWindow12p(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow12p)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    //adquiriendo informacion para los combo box. se usa set para no repetir elementos
    set<QString> cursos;
    set<QString> carreras;
    set<QString> grupos;
    if(db.open())
    {
        QSqlQuery query;
        //adquiriendo los cursos
        if(query.exec("select curso from grupo"))
        {
            while(query.next())
            {
                cursos.insert(query.value(0).toString());
            }
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE CONSULTA","No se pudieron resolver los cursos");
        }
        //adquiriendo las carreras
        if(query.exec("select nombre from carrera"))
        {
            while(query.next())
            {
                carreras.insert(query.value(0).toString());
            }
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE CONSULTA","No se pudieron resolver las carreras");
        }
        //adquiriendo los nombre de grupos
        if(query.exec("select nombregrupo from grupo"))
        {
            while(query.next())
            {
                grupos.insert(query.value(0).toString());
            }
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE CONSULTA","No se pudieron resolver los nombres de los grupos");
        }
    }
    //mostrando datos en los combo box
    for(auto it : cursos) ui->comboBox->addItem(it);
    for(auto it : carreras) ui->comboBox_2->addItem(it);
    for(auto it : grupos) ui->comboBox_4->addItem(it);
}

MainWindow12p::~MainWindow12p()
{
    delete ui;
}

void MainWindow12p::on_pushButton_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow3 *m = new MainWindow3;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow12p::on_pushButton_2_clicked()
{
    QString curso = ui->comboBox->currentText();
    QString carrera = ui->comboBox_2->currentText();
    QString anno = ui->comboBox_3->currentText();
    QString grupo = ui->comboBox_4->currentText();
    QString asignatura = ui->comboBox_5->currentText();

    //Verificando que las opciones marcadas existan en la base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if(db.open())
    {
        QSqlQuery query;
        if(query.exec("select * from grupo, carrera where carrera.idcarrera = grupo.idcarrera and carrera.nombre='"+carrera+"' and anno='"+anno+"' and curso='"+curso+"' and asignatura='"+asignatura+"' and nombregrupo='"+grupo+"'"))
        {

            if(!query.next())
            {
                QMessageBox::critical(this,"ERROR DE SELECCION","No existe ningun registro con estos datos");
                return;
            }
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE SELECCION","No se pudo efectuar la busqueda en los registros");
            return;
        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE APERTURA","No se pudo acceder a los registros");
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
