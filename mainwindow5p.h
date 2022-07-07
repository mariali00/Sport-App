#ifndef MAINWINDOW5P_H
#define MAINWINDOW5P_H

#include <mainwindow4.h>
#include <peso.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QPalette>
#include <QColor>
#include <QWidget>
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
#include <iostream>
#include "util.h"

namespace Ui {
class MainWindow5p;
}

class MainWindow5p : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow5p(QWidget *,QString,QString,QString,QString,QString);
    explicit MainWindow5p(QWidget *parent = 0);
    ~MainWindow5p();
    QString getCarrera();
    QString getAnno();
    QString getCurso();
    QString getGrupo();
    QString getAsignatura();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_clicked(bool checked);

private:
    Ui::MainWindow5p *ui;
    QString carreraConsulta;
    QString annoConsulta;
    QString cursoConsulta;
    QString grupoConsulta;
    QString asignaturaConsulta;

};

#endif // MAINWINDOW5P_H
