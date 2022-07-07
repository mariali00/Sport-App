#ifndef MAINWINDOW14_H
#define MAINWINDOW14_H

#include <QMainWindow>
#include <mainwindow12.h>

namespace Ui {
class MainWindow14;
}

class MainWindow14 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow14(QWidget *parent = 0);
    ~MainWindow14();
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
    Ui::MainWindow14 *ui;
};

#endif // MAINWINDOW14_H
