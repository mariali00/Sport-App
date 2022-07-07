#ifndef MAINWINDOW16_H
#define MAINWINDOW16_H

#include "mainwindow16p.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QFont>
#include <QKeyEvent>

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

namespace Ui {
class MainWindow16;
}

class MainWindow16 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow16(QWidget *parent = 0);
    ~MainWindow16();
    QString sexoTabla;
    QString edadTabla;

    void keyPressEvent(QKeyEvent *event);

    QString nombre;
    QString sexo;
    QString edad;
    QString peso;
    QString altura;
    QString cintura;
    bool CambiandoCelda = 1;

    void actualizarTabla();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_actionRestaurar_ajustes_predeterminados_triggered();

    void on_pushButton_2_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::MainWindow16 *ui;
};

#endif // MAINWINDOW16_H
