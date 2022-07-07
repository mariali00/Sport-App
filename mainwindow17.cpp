#include "mainwindow17.h"
#include "ui_mainwindow17.h"

MainWindow17::MainWindow17(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow17)
{
    ui->setupUi(this);

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

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    //seleccionando alumnos del grupo dado
    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> carreras;
        // obteniendo todas las carreras
        if(query.exec("select distinct nombre from carrera"))
        {
            while(query.next())
                carreras.push_back(query.value(0).toString());
        }
        else
        {
            QMessageBox::critical(this,"ERROR DE DATOS","No fue posible hacer la consulta");
        }
        // Obtener cada dato por carreras
        for(int i = 0; i < carreras.size(); i++)
        {
            if(i == 2)
            {

            }

            // obtener id de estudiantes que pertenecen a carrera dada
            if(query.exec("select estudiante.idestudiante from grupo, estudiante, grupo_tiene_estudiante, carrera"
                          "where grupo.idgrupo=grupo_tiene_estudiante.idgrupo and grupo.idcarrera = carrera.idcarrera"
                          "grupo_tiene_estudiante.idestudiante=estudiante.idestudiante and "
                          "carrera.nombre='"+carreras.at(i) + "'"))
            {
                int hombresSAT = 0, hombresNOSAT = 0, hombresNoRea = 0;
                int mujeresSAT = 0, mujeresNOSAT = 0, mujeresNoRea = 0;
                while(query.next())
                {
                    QString idestudiante = query.value(0).toString();
                    // Hallar categoria del estudiante
                    QSqlQuery query2;
                    if(query2.exec("select * from estudiante where idestudiante="+idestudiante))
                    {
                        query2.first();
                        QString nombreTabla = query2.value(1).toString();
                        QString sexoTabla = query2.value(2).toString();
                        QString edadTabla = query2.value(3).toString();
                        QString alturaTabla = query2.value(4).toString();
                        QString cinturaTabla = query2.value(5).toString();
                        QString pesoTabla = query2.value(6).toString();
                        QString presion = query2.value(7).toString();
                        QString flexibilidadTabla = query2.value(8).toString();
                        QString planchasTabla = query2.value(9).toString();
                        QString abdominalesTabla = query2.value(10).toString();
                        QString saltoTabla = query2.value(11).toString();
                        QString velocidadTabla = query2.value(12).toString();
                        QString resistenciaTabla = query2.value(13).toString();


                        Eval e;

                        bool evaluacion = 1;

                        if(e.presionArt(presion) == "pre" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                            evaluacion = 0;
                        if(e.presionArt(presion) == "I" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                            evaluacion = 0;
                        if(e.presionArt(presion) == "II" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                            evaluacion = 0;
                        if(e.presionArt(presion) == "III" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                            evaluacion = 0;

                        double imcdat=e.IMC(pesoTabla.toDouble(),alturaTabla.toDouble());
                        if(e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Bajo Peso" && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "" )
                            evaluacion = 0;
                        if((e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Sobrepeso" || e.eval_IMC(imcdat,sexoTabla.toStdString(),edadTabla.toInt())=="Obesidad")  && sexoTabla != "" && edadTabla != "" && pesoTabla != "" && alturaTabla != "")
                            evaluacion = 0;

                        if(e.RCE(cinturaTabla.toDouble(),alturaTabla.toDouble())=="Necesita mejorar" && cinturaTabla != "" && alturaTabla != "")
                            evaluacion = 0;

                        if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                            evaluacion = 0;
                        if(e.flexibilidad(flexibilidadTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                            evaluacion = 0;

                        if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                            evaluacion = 0;
                        if(e.fuerza_brazo(planchasTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                            evaluacion = 0;

                        if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                            evaluacion = 0;
                        if(e.fuerza_abdominal(abdominalesTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                            evaluacion = 0;


                        if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Aceptable" && sexoTabla != "")
                            evaluacion = 0;
                        if(e.fuerza_piernas(saltoTabla.toDouble(),sexoTabla.toStdString())=="Necesita mejorar" && sexoTabla != "")
                            evaluacion = 0;


                        if(edadTabla != "" && sexoTabla != "" && velocidadTabla != "")
                        {
                            switch (e.CategoriaVelocidad(edadTabla,sexoTabla,velocidadTabla)) {
                            case 2: evaluacion = 0;
                                break;
                            case 3: evaluacion = 0;
                                break;
                            case 4: evaluacion = 0;
                                break;
                            }
                        }


                        if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Aceptable" && sexoTabla != "")
                            evaluacion = 0;
                        if(e.resistencia(sexoTabla.toStdString(),resistenciaTabla.toDouble())=="Necesita mejorar" && sexoTabla != "")
                            evaluacion = 0;


                        if(evaluacion)
                        {
                            if(sexoTabla == "F")
                            {
                                mujeresSAT++;
                            }
                            if(sexoTabla == "M")
                            {
                                hombresSAT++;
                            }
                        }
                        if(!evaluacion)
                        {
                            if(sexoTabla == "F")
                            {
                                mujeresNOSAT++;
                            }
                            if(sexoTabla == "M")
                            {
                                hombresNOSAT++;
                            }
                        }
                        // Se asume que si no hay edad, no se han introducido datos del estudiante y por tanto no ha hecho
                        // diagnostico
                        if(edadTabla == "")
                        {
                            if(sexoTabla == "F")
                            {
                                hombresNoRea++;
                            }
                            if(sexoTabla == "M")
                            {
                                mujeresNoRea++;
                            }
                        }
                    }
                }
                // Items para agregar a la tabla
                QTableWidgetItem *carrera = new QTableWidgetItem(carreras.at(i));

                QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(hombresSAT));
                QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(hombresNOSAT));
                QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(hombresNoRea));

                QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(mujeresSAT));
                QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(mujeresNOSAT));
                QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(mujeresNoRea));

                QTableWidgetItem *item7 = new QTableWidgetItem(QString::number(hombresSAT + mujeresSAT));
                QTableWidgetItem *item8 = new QTableWidgetItem(QString::number(hombresNOSAT + mujeresNOSAT));
                QTableWidgetItem *item9 = new QTableWidgetItem(QString::number(hombresNoRea + mujeresNoRea));

                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,carrera);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,item1);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,item2);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,item3);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,4,item4);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,5,item5);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,6,item6);

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,7,item7);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,8,item8);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,9,item9);
            }

        }
    }
    else
    {
        QMessageBox::critical(this,"ERROR DE DATOS","No fue posible hacer la conexion con los datos");
    }
}

MainWindow17::~MainWindow17()
{
    delete ui;
}

void MainWindow17::on_pushButton_3_clicked()
{
    //Abriendo la ventana siguiente
    MainWindow3 *m = new MainWindow3;
    m->show();
    //Cerrando esta ventana
    this->close();
}

void MainWindow17::on_pushButton_clicked()
{
    ui->centralwidget->setStyleSheet("");
        QStringList a = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
        QString prefix = a.at(0);
        QString fullPath = prefix + "/Reporte General.pdf";

        QPdfWriter pdf(fullPath);
           pdf.setTitle("Reporte General");
           pdf.setPageSize(QPagedPaintDevice::A4);
           pdf.setPageMargins(QMargins(30,30,30,30));


           QPainter *painter= new QPainter(&pdf);
           painter->setPen(Qt::black);
           painter->setFont(QFont("Ubuntu Condensed",15));

           QRect r = painter->viewport();


           QString nombre = "";
           QString correo = "";
           QFile file("wet.txt");
           if (file.open(QIODevice::ReadOnly | QIODevice::Text))
           {
               QTextStream in(&file);
               nombre = in.readLine();
               correo = in.readLine();
               correo = in.readLine();
           }
           QString fecha = "";
           QDate date = QDate::currentDate();
           fecha += date.toString("dd.MM.yyyy");
           painter->setFont(QFont("Arial Negrita",8));
           painter->drawText(r, Qt::AlignRight, fecha);
           // Determinando el curso escolar
           int curso = fecha.mid(6).toInt();
           // Comienza el curso escolar en septiembre
           QString cursoString = QString::number(curso-1) + "-" + QString::number(curso);
           if(fecha.mid(4,5) == 9)
               cursoString += QString::number(curso) + "-" + QString::number(curso);

           QString encabezado = "DIAGNOSTICO DE LA CONDICION FISICA DE LOS ESTUDIANTES UNIVERSITARIOS"
                                "\nUniversidad de Oriente Sede Antonio Maceo"
                                "\nCurso: " + cursoString+
                                "\nProvincia Santiago de Cuba"
                                "\nProfesor " + nombre+
                                "\nCorreo " + correo;

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
           QTableWidgetItem *carr = new QTableWidgetItem(QString("Carrera"));
           QTableWidgetItem *hs = new QTableWidgetItem(QString("Hombres\nSatisfactorio  "));
           QTableWidgetItem *hns = new QTableWidgetItem(QString("Hombres\nNo Satisfactorio  "));
           QTableWidgetItem *hnr = new QTableWidgetItem(QString("Hombres\nNo realizó  "));
           QTableWidgetItem *ms = new QTableWidgetItem(QString("Mujeres\nSatisfactorio  "));
           QTableWidgetItem *mns = new QTableWidgetItem(QString("Mujeres\nNo Satisfactorio  "));
           QTableWidgetItem *mnr = new QTableWidgetItem(QString("Mujeres\nNo realizó  "));
           QTableWidgetItem *ts = new QTableWidgetItem(QString("Total\nSatisfactorio  "));
           QTableWidgetItem *tns = new QTableWidgetItem(QString("Total\n No Satisfactorio  "));
           QTableWidgetItem *tnr = new QTableWidgetItem(QString("Total\n No realizó  "));


           table->setItem(0,0,carr);
           table->setItem(0,1,hs);
           table->setItem(0,2,hns);
           table->setItem(0,3,hnr);
           table->setItem(0,4,ms);
           table->setItem(0,5,mns);
           table->setItem(0,6,mnr);
           table->setItem(0,7,ts);
           table->setItem(0,8,tns);
           table->setItem(0,9,tnr);


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

         MainWindow17 *m = new MainWindow17();
         m->show();
         QMessageBox::information(m,"EXPORTAR IMAGEN A PDF","El documento fue guardado en " + prefix);
         this->close();

}
