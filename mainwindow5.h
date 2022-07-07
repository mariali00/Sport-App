#ifndef MAINWINDOW5_H
#define MAINWINDOW5_H

//#include <QMainWindow>
#include <mainwindow6.h>
#include <mainwindow4.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
//#include <QMessageBox>
#include <QDebug>
//#include <QTableWidgetItem>
#include <QString>
#include <QPalette>
#include <QColor>
#include <QWidget>
//#include <QPdfWriter>
//#include <QPainter>
//*******nuevas bibliotecas incluidas************
#include <QMainWindow>
#include <QPdfWriter>
#include <QPainter>
#include <QPaintEngine>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextTable>
#include <QTextCursor>
#include <QPrinter>
#include <QDate>
#include <QTableWidget>
#include <QTableWidgetItem>


namespace Ui {
class MainWindow5;
}

class MainWindow5 : public QMainWindow
{
    Q_OBJECT 
public:
    MainWindow5(QWidget *,QString,QString,QString,QString);
    explicit MainWindow5(QWidget *parent = 0);
    ~MainWindow5();
    QString getCarrera();
    QString getAnno();
    QString getCurso();
    QString getGrupo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow5 *ui;
    QString carreraConsulta;
    QString annoConsulta;
    QString cursoConsulta;
    QString grupoConsulta;

};
#endif // MAINWINDOW5_H
