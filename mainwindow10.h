#ifndef MAINWINDOW10_H
#define MAINWINDOW10_H

#include <QMainWindow>
#include <mainwindow11.h>
#include <mainwindow3.h>
#include <QString>
#include <QMessageBox>

namespace Ui {
class MainWindow10;
}

class MainWindow10 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow10(QWidget *parent = 0);
    ~MainWindow10();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow10 *ui;
};

#endif // MAINWINDOW10_H
