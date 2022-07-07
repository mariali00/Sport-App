#include "mainwindow_prueba.h"
#include "ui_mainwindow_prueba.h"

MainWindow_prueba::MainWindow_prueba(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_prueba)
{
    ui->setupUi(this);
}

MainWindow_prueba::~MainWindow_prueba()
{
    delete ui;
}

void MainWindow_prueba::on_pushButton_clicked()
{
    for(int i=0; i<10; i++)
    {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

        QTableWidgetItem *nombre = new QTableWidgetItem("Carlos Alberto");
        QTableWidgetItem *apellidos = new QTableWidgetItem("Rodriguez");
        QTableWidgetItem *edad = new QTableWidgetItem("20");
        QTableWidgetItem *sexo = new QTableWidgetItem("M");

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,nombre);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,apellidos);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,edad);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,sexo);

    }





    QPdfWriter pdf("/home/carlos/Desktop/inflador.pdf");
       pdf.setPageSize(QPagedPaintDevice::A4);
       pdf.setPageMargins(QMargins(30,30,30,30));


       QPainter *painter= new QPainter(&pdf);
       painter->setPen(Qt::black);
       painter->setFont(QFont("Ubuntu Condensed",20));

       QRect r = painter->viewport();
       painter->drawText(r,"Tabla de los estudiantes");


       QTableWidget *table = ui->tableWidget;
       table->setFont(QFont("Ubuntu Condensed",200));

       int c = 0;
       int b = 0;

       table->resizeColumnsToContents();
       table->resizeRowsToContents();

       for( int i = 0; i < 7 ; i++ )
           c += table->columnWidth(i);

       for( int i = 0; i < 100 ; i++ )
           b += table->rowHeight(i);

     table->setFixedSize(c+70,b+155);
     table->render(painter,QPoint(1000,1000));
     //QMessageBox::critical(this,"test","yeah");
     painter->end();
}
