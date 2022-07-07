#ifndef MAINWINDOW12_H
#define MAINWINDOW12_H

#include <QMainWindow>
#include <mainwindow13.h>
#include <mainwindow14.h>
#include <mainwindow15.h>
#include <mainwindow12p.h>
#include <QString>

namespace Ui {
class MainWindow12;
}

class MainWindow12 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow12(QWidget *parent = 0);
    ~MainWindow12();
    QString curso;
    QString carrera;
    QString anno;
    QString grupo;
    QString asignatura;
    void setTitleGrupo();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow12 *ui;
};

#endif // MAINWINDOW12_H
