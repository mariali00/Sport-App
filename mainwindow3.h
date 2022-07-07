#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <mainwindow4.h>
#include <mainwindow10.h>
#include <mainwindow12p.h>
#include <mainwindow.h>
#include <mainwindow17.h>
#include <QPropertyAnimation>


namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = 0);
    ~MainWindow3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow3 *ui;
};

#endif // MAINWINDOW3_H
