#include "mainwindow16p.h"
#include "ui_mainwindow16p.h"
using namespace std;

MainWindow16p::MainWindow16p(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow16p)
{
    ui->setupUi(this);
}

MainWindow16p::~MainWindow16p()
{
    delete ui;
}

void MainWindow16p::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "" ||
       ui->lineEdit_2->text() == "" ||
       ui->lineEdit_3->text() == "" ||
       ui->lineEdit_5->text() == "" ||
       ui->lineEdit_6->text() == "" ||
       ui->lineEdit_7->text() == "" ||
       ui->comboBox->currentText() == "" )
    {
        QMessageBox::information(this,"CAMPOS VACIOS","No pueden haber campos incompletos");
        return;
    }
    else
    {
        ofstream fout("dry.txt");
        fout << ui->lineEdit->text().toStdString() << " " << ui->lineEdit_2->text().toStdString() <<"\n"
             << ui->comboBox->currentText().toStdString() << "\n"
             << ui->lineEdit_3->text().toStdString() << "\n"
             << ui->lineEdit_5->text().toStdString() << "\n"
             << ui->lineEdit_6->text().toStdString() << "\n"
             << ui->lineEdit_7->text().toStdString() << "\n";
        fout.close();

        //Mostrando la ventana anterior
        MainWindow16 *m = new MainWindow16;
        m->show();
        //Cerrando esta ventana
        this->close();

    }
}

void MainWindow16p::on_pushButton_clicked()
{
    //Mostrando la ventana anterior
    MainWindow16 *m = new MainWindow16;
    m->show();
    //Cerrando esta ventana
    this->close();
}
