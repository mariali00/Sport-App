#ifndef MAINWINDOW13_H
#define MAINWINDOW13_H

#include <QMainWindow>
#include <mainwindow12.h>

namespace Ui {
class MainWindow13;
}

class MainWindow13 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow13(QWidget *parent = 0);
    ~MainWindow13();
    QString curso;
    QString carrera;
    QString anno;
    QString grupo;
    QString asignatura;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow13 *ui;
};

#endif // MAINWINDOW13_H
