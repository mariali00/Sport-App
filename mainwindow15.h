#ifndef MAINWINDOW15_H
#define MAINWINDOW15_H

#include <QMainWindow>
#include <mainwindow12.h>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class MainWindow15;
}

class MainWindow15 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow15(QWidget *parent = 0);
    ~MainWindow15();
    QString curso;
    QString carrera;
    QString anno;
    QString grupo;
    QString asignatura;
    void setAlumnos();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow15 *ui;
};

#endif // MAINWINDOW15_H
