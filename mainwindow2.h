#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <mainwindow.h>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <fstream>
#include <QString>



namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow2 *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW2_H
