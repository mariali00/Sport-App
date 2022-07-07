#ifndef MAINWINDOW16P_H
#define MAINWINDOW16P_H

#include <QMainWindow>
#include <fstream>
#include <QMessageBox>
#include "mainwindow16.h"
#include "mainwindow.h"
#include <iostream>


namespace Ui {
class MainWindow16p;
}

class MainWindow16p : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow16p(QWidget *parent = 0);
    ~MainWindow16p();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow16p *ui;
};

#endif // MAINWINDOW16P_H
