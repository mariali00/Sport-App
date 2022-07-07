#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainwindow3.h>
#include <mainwindow2.h>
#include <mainwindow16p.h>
#include <util.h>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <fstream>
#include <QFile>
#include <QFont>
#include <fstream>
#include <QString>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:


    void on_pushButton_clicked();

    void on_actionAcerca_de_triggered();

    void on_actionRestaurar_ajustes_predeterminados_triggered();

    void on_actionHerramienta_de_autoevaluacion_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString pass;
    QString pass_entry;
};

#endif // MAINWINDOW_H
