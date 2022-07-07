#include "mainwindow5p.h"
#include "ui_mainwindow5p.h"

using namespace std;



MainWindow5p::MainWindow5p(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow5p)
{
    ui->setupUi(this);

}

MainWindow5p::MainWindow5p(QWidget *parent, QString carrera, QString anno, QString curso,QString grupo,QString asignatura) :
    QMainWindow(parent),
    ui(new Ui::MainWindow5p),
    carreraConsulta(carrera),
    annoConsulta(anno),
    cursoConsulta(curso),
    grupoConsulta(grupo),
    asignaturaConsulta(asignatura)
{

    ui->setupUi(this);

    //Agregando titulo de esta ventana en los labels
    ui->label->setText("Educación Física "+getAsignatura());
    ui->label_2->setText(getCarrera() + " " + getAnno() + ", Grupo " + getGrupo() + ". Curso " + getCurso());
    //Insertando el estilo de esta ventana por error (1)
    ui->centralwidget->setStyleSheet(""
   "QPushButton"
   " {"
   "     border-radius:5px;"
   "     background-color: \"white\";"
   " }"
    "QPushButton:hover { background-color: rgb(200,200,200)}"
   " #centralwidget"
   " {"
    "border-image: url(:/images/fondo.jpg);"
   " });");
    bool evaluacion = 1; //cambia cuando el color de una celda es otro que no sea verde
    int CantidadEstudiantesSatisfactorios = 0;
    int CantidadEstudiantesNoSatisfactorios = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    //seleccionando alumnos del grupo dado
    if(db.open())
    {
        QSqlQuery query,other;
        //mostrando los alumnos del grupo
        if(query.exec("select estudiante.nombre, sexo, edad, altura, presion, cintura, peso"
                      "from grupo, estudiante, grupo_tiene_estudiante "
                      "where estudiante.idestudiante=grupo_tiene_estudiante.idestudiante and grupo_tiene_estudiante.idgrupo=grupo.idgrupo and "
                      "carrera='"+getCarrera()+"' and curso='"+getCurso()+"' and anno='"+getAnno()+"' and asignatura='"+getAsignatura()+"' and nombregrupo='"+getGrupo()+"'"))
        {

            while(query.next())
            {

                //Una aproximacion para nombres de mas de 45 caracteres, se hace una nueva linea con el resto del nombre
                QString nombreTabla = query.value(0).toString();
                if(nombreTabla.size() > 45)
                {
                    QString aux1 = "";
                    QString aux2 = "";
                    for(int i{0}; i<nombreTabla.size(); i++)
                    {
                        if(i<45)
                            aux2+=nombreTabla[i];
                        else
                            aux1+=nombreTabla[i];
                    }
                    nombreTabla = aux1 + "\n" + aux2;
                }
                QString sexoTabla = query.value(1).toString();
                QString edadTabla = query.value(2).toString();
                QString alturaTabla = query.value(3).toString();
                QString presion = query.value(4).toString();
                QString cinturaTabla = query.value(5).toString();
                QString pesoTabla = query.value(6).toString();
                if(!other.exec("select valor"
                               "from estudiante, capacidad_fisica, estudiante_tiene_cf"
                               "where estudiante_tiene_cf.idestudiante = estudiante.idestudiante and"
                               "estudiante_tiene_cf.idCF = capacidad_fisica.idCF and"
                               "estudiante.nombre = '"+query.value(0).toString()+"' and capacidad_fisica.nombre='flexibilidad'"))
                {
                  qDebug()<< other.lastError();
                }

                QString flexibilidadTabla = other.value(0).toString();
                if(!other.exec("select valor"
                               "from estudiante, capacidad_fisica, estudiante_tiene_cf"
                               "where estudiante_tiene_cf.idestudiante = estudiante.idestudiante and"
                               "estudiante_tiene_cf.idCF = capacidad_fisica.idCF and"
                               "estudiante.nombre = '"+query.value(0).toString()+"' and capacidad_fisica.nombre='plancha'"))
                {
                  qDebug()<< other.lastError();
                }
                QString planchasTabla = other.value(0).toString();
                if(!other.exec("select valor"
                               "from estudiante, capacidad_fisica, estudiante_tiene_cf"
                               "where estudiante_tiene_cf.idestudiante = estudiante.idestudiante and"
                               "estudiante_tiene_cf.idCF = capacidad_fisica.idCF and"
                               "estudiante.nombre = '"+query.value(0).toString()+"' and capacidad_fisica.nombre='abdominales'"))
                {
                  qDebug()<< other.lastError();
                }
                QString abdominalesTabla = other.value(0).toString();
                if(!other.exec("select valor"
                               "from estudiante, capacidad_fisica, estudiante_tiene_cf"
                               "where estudiante_tiene_cf.idestudiante = estudiante.idestudiante and"
                               "estudiante_tiene_cf.idCF = capacidad_fisica.idCF and"
                               "estudiante.nombre = '"+query.value(0).toString()+"' and capacidad_fisica.nombre='salto'"))
                {
                  qDebug()<< other.lastError();
                }
                QString saltoTabla =other.value(0).toString();
                if(!other.exec("select valor"
                               "from estudiante, capacidad_fisica, estudiante_tiene_cf"
                               "where estudiante_tiene_cf.idestudiante = estudiante.idestudiante and"
                               "estudiante_tiene_cf.idCF = capacidad_fisica.idCF and"
                               "estudiante.nombre = '"+query.value(0).toString()+"' and capacidad_fisica.nombre='velocidad'"))
                {
                  qDebug()<< other.lastError();
                }
                QString velocidadTabla = other.value(0).toString();
                if(!other.exec("select valor"
                               "from estudiante, capacidad_fisica, estudiante_tiene_cf"
                               "where estudiante_tiene_cf.idestudiante = estudiante.idestudiante and"
                               "estudiante_tiene_cf.idCF = capacidad_fisica.idCF and"
                               "estudiante.nombre = '"+query.value(0).toString()+"' and capacidad_fisica.nombre='resistencia'"))
                {
                  qDebug()<< other.lastError();
                }
                QString resistenciaTabla = other.value(0).toString();
                QString evaluacionTabla = "";

                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

                QTableWidgetItem *nombreitem = new QTableWidgetItem(nombreTabla);
                QTableWidgetItem *sexoitem = new QTableWidgetItem(sexoTabla);
                QTableWidgetItem *edaditem = new QTableWidgetItem(edadTabla);
                QTableWidgetItem *pesoitem = new QTableWidgetItem(pesoTabla);
                QTableWidgetItem *alturaitem = new QTableWidgetItem(alturaTabla);
                QTableWidgetItem *cinturaitem = new QTableWidgetItem(cinturaTabla);
                QTableWidgetItem *presionitem= new QTableWidgetItem(presion);
                QTableWidgetItem *flexibilidaditem = new QTableWidgetItem(flexibilidadTabla);
                QTableWidgetItem *planchasitem = new QTableWidgetItem(planchasTabla);
                QTableWidgetItem *abdominalesitem = new QTableWidgetItem(abdominalesTabla);
                QTableWidgetItem *saltoitem = new QTableWidgetItem(saltoTabla);
                QTableWidgetItem *velocidaditem = new QTableWidgetItem(velocidadTabla);
                QTableWidgetItem *resistenciaitem = new QTableWidgetItem(resistenciaTabla);
                QTableWidgetItem *evaluacionitem = new QTableWidgetItem(evaluacionTabla);


                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,nombreitem);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,sexoitem);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,edaditem);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,alturaitem);

                Eval e;

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, presionitem);
                if(e.presionArt(presion) == "normal" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1, 6)->setBackground(Qt::green);
                if(e.presionArt(presion) == "pre" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1, 6)->setBackground(Qt::yellow);
                if(e.presionArt(presion) == "I" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1, 6)->setBackground(Qt::red);
                if(e.presionArt(presion) == "II" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1, 6)->setBackground(Qt::red);
                if(e.presionArt(presion) == "III" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1, 6)->setBackground(Qt::red);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,pesoitem);
                double imcdat=e.IMC(pesoTabla.toDouble(),alturaTabla.toDouble());
                if(e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Bajo Peso" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,4)->setBackground(Qt::yellow),evaluacion=0;
                if((e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Sobrepeso" || e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Obesidad")  && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,4)->setBackground(Qt::red),evaluacion=0;
                if(e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Normal" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,4)->setBackground(Qt::green);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,cinturaitem);
                if(e.RCE(cinturaTabla.toDouble(),alturaTabla.toDouble())=="Aceptable" && cinturaTabla != "" && alturaTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)->setBackground(Qt::green);
                if(e.RCE(cinturaTabla.toDouble(),alturaTabla.toDouble())=="Necesita mejorar" && cinturaTabla != "" && alturaTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,5)->setBackground(Qt::red),evaluacion=0;

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,flexibilidaditem);
                if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,7)->setBackground(Qt::yellow),evaluacion=0;
                if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,7)->setBackground(Qt::red),evaluacion=0;
                if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,7)->setBackground(Qt::green);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8,planchasitem);
                if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,8)->setBackground(Qt::yellow),evaluacion=0;
                if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,8)->setBackground(Qt::red),evaluacion=0;
                if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,8)->setBackground(Qt::green);


                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,9,abdominalesitem);
                if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,9)->setBackground(Qt::yellow),evaluacion=0;
                if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,9)->setBackground(Qt::red),evaluacion=0;
                if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,9)->setBackground(Qt::green);


                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,10,saltoitem);
                if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,10)->setBackground(Qt::yellow),evaluacion=0;
                if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,10)->setBackground(Qt::red),evaluacion=0;
                if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Destacado" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,10)->setBackground(Qt::green);


                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,11,velocidaditem);
                if(edadTabla != "" && sexoTabla != "" && velocidadTabla != "")
                {
                    switch (e.CategoriaVelocidad(edadTabla,sexoTabla,velocidadTabla)) {
                    case 1: ui->tableWidget->item(ui->tableWidget->rowCount()-1,11)->setBackground(Qt::green);
                        break;
                    case 2: ui->tableWidget->item(ui->tableWidget->rowCount()-1,11)->setBackground(Qt::blue),evaluacion=0;
                        break;
                    case 3: ui->tableWidget->item(ui->tableWidget->rowCount()-1,11)->setBackground(Qt::yellow),evaluacion=0;
                        break;
                    case 4: ui->tableWidget->item(ui->tableWidget->rowCount()-1,11)->setBackground(Qt::red),evaluacion=0;
                        break;
                    }
                }


                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,12,resistenciaitem);
                if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Aceptable" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,12)->setBackground(Qt::yellow),evaluacion=0;
                if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Necesita mejorar" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,12)->setBackground(Qt::red),evaluacion=0;
                if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Destacado" && sexoTabla != "")
                    ui->tableWidget->item(ui->tableWidget->rowCount()-1,12)->setBackground(Qt::green);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,13,evaluacionitem);

                /*** garantizando que la tabla no este vacia, o sea, que se haya creado pero no se hallan agregado datos
                 * Se garantiza que siempre que el valor edad este vacio, signifique que no se hallan guardado datos
                 * en la tabla
                 */
                if(edadTabla != "")
                {
                    if(evaluacion)
                        ui->tableWidget->item(ui->tableWidget->rowCount()-1,13)->setBackground(Qt::green), ui->tableWidget->item(ui->tableWidget->rowCount()-1,13)->setText("SATISFACTORIO"), CantidadEstudiantesSatisfactorios++;
                    else
                        ui->tableWidget->item(ui->tableWidget->rowCount()-1,13)->setBackground(Qt::red), ui->tableWidget->item(ui->tableWidget->rowCount()-1,13)->setText("NO SATISFACTORIO"), CantidadEstudiantesNoSatisfactorios++;
                }


                evaluacion = 1;
            }
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE DATOS","No fue posible hacer la conexion con los datos (2)");
        }
    }

}

MainWindow5p::~MainWindow5p()
{
    delete ui;
}

void MainWindow5p::on_pushButton_3_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow4 *m = new MainWindow4;
    m->show();
    //Cerrando esta ventana
    this->close();
}

QString MainWindow5p::getCarrera()
{
    return carreraConsulta;
}

QString MainWindow5p::getAnno()
{
    return annoConsulta;
}

QString MainWindow5p::getCurso()
{
    return cursoConsulta;
}

QString MainWindow5p::getGrupo()
{
    return grupoConsulta;
}

QString MainWindow5p::getAsignatura()
{
    return asignaturaConsulta;
}

void MainWindow5p::on_pushButton_2_clicked()
{

    ui->centralwidget->setStyleSheet("");
        QStringList a = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
        QString prefix = a.at(0);
        QString fullPath = prefix + "/" +getCarrera()+" "+getAnno()+", grupo "+getGrupo()+", curso "+getCurso()+", Educación Física "+getAsignatura()+".pdf";

        QPdfWriter pdf(fullPath);
           pdf.setTitle("Universidad de Oriente\nDepartamento de Educacion Fisica\n");
           pdf.setPageSize(QPagedPaintDevice::A4);
           pdf.setPageMargins(QMargins(30,30,30,30));


           QPainter *painter= new QPainter(&pdf);
           painter->setPen(Qt::black);
           painter->setFont(QFont("Ubuntu Condensed",15));

           QRect r = painter->viewport();



           QString fecha = "";
           QDate date = QDate::currentDate();
           fecha += date.toString("dd.MM.yyyy");
           painter->setFont(QFont("Arial Negrita",8));
           painter->drawText(r, Qt::AlignRight, fecha);
           QString encabezado = "Universidad de Oriente\nDepartamento de Educación Física"
                                "\nAsignatura: Educación Física "+getAsignatura()+
                                "\nCurso: "+getCurso()+
                                "\nCarrera: "+getCarrera() +
                                "\nAño: "+getAnno()+
                                "\nGrupo: "+getGrupo();
           painter->drawText(r,Qt::AlignTop,encabezado);


           QTableWidget *table = ui->tableWidget;
           table->setFont(QFont("Arial Negrita",80));

           int c = 0;
           int b = 0;

           //se deben agregar los nombres de las columnas como una fila mas ya que no funciona de otra manera
           table->horizontalHeader()->setVisible(false);
           table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
           table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
           table->insertRow(0);
           QTableWidgetItem *nombre = new QTableWidgetItem(QString("Nombre"));
           QTableWidgetItem *sexo = new QTableWidgetItem(QString("Sexo"));
           QTableWidgetItem *edad = new QTableWidgetItem(QString("Edad"));
           QTableWidgetItem *altura = new QTableWidgetItem(QString("Altura"));
           QTableWidgetItem *peso = new QTableWidgetItem(QString("Peso"));
           QTableWidgetItem *cintura = new QTableWidgetItem(QString("Perimetro\nCintura"));
           QTableWidgetItem *presion = new QTableWidgetItem(QString("Presion\nArterial"));
           QTableWidgetItem *flexibilidad = new QTableWidgetItem(QString("Flexibilidad"));
           QTableWidgetItem *planchas = new QTableWidgetItem(QString("Fuerza\nde brazos"));
           QTableWidgetItem *abdominales = new QTableWidgetItem(QString("Abdominales"));
           QTableWidgetItem *salto = new QTableWidgetItem(QString("Salto"));
           QTableWidgetItem *velocidad = new QTableWidgetItem(QString("Velocidad"));
           QTableWidgetItem *resistencia = new QTableWidgetItem(QString("Resistencia"));
           QTableWidgetItem *evaluacion = new QTableWidgetItem(QString("Evaluacion   "));


           table->setItem(0,0,nombre);
           table->setItem(0,1,sexo);
           table->setItem(0,2,edad);
           table->setItem(0,3,altura);
           table->setItem(0,4,peso);
           table->setItem(0,5,cintura);
           table->setItem(0,6,presion);
           table->setItem(0,7,flexibilidad);
           table->setItem(0,8,planchas);
           table->setItem(0,9,abdominales);
           table->setItem(0,10,salto);
           table->setItem(0,11,velocidad);
           table->setItem(0,12,resistencia);
           table->setItem(0,13,evaluacion);



           table->resizeColumnsToContents();
           table->resizeRowsToContents();

           for( int i = 0; i < table->columnCount() ; i++ )
               c += table->columnWidth(i);

           for( int i = 0; i < table->rowCount() ; i++ )
               b += table->rowHeight(i);



         table->setFixedSize(c,b);
         table->render(painter,QPoint(20,1500));
         this->close();
         painter->end();

         MainWindow5p *m = new MainWindow5p(0,getCarrera(),getAnno(),getCurso(),getGrupo(),getAsignatura());
         m->show();
         QMessageBox::information(m,"EXPORTAR IMAGEN A PDF","El documento fue guardado en " + prefix);
         this->close();


}



void MainWindow5p::on_pushButton_clicked(bool checked)
{

        peso* p;
         p = new peso();

        p->show();
}
