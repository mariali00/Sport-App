#include "test.h"
#include "ui_test.h"

#include <QStringList>
#include <QStandardPaths>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QDate>


test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);

    QStringList a = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    QString prefix = a.at(0);
    QString fullPath = prefix + "/tabla.pdf";

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
                            "\nAsignatura: Educación Física "
                            "\nCurso: "
                            "\nCarrera: "
                            "\nAño: "
                            "\nGrupo: ";
      // painter->drawText(r,Qt::AlignTop,encabezado);


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
     //table->render(painter,QPoint(20,1500));
     this->close();
     painter->end();

}

test::~test()
{
    delete ui;
}
