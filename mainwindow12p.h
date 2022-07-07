#ifndef MAINWINDOW12P_H
#define MAINWINDOW12P_H

#include <QMainWindow>
#include <mainwindow3.h>
#include <mainwindow12.h>

namespace Ui {
class MainWindow12p;
}

class MainWindow12p : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow12p(QWidget *parent = 0);
    ~MainWindow12p();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow12p *ui;
};

#endif // MAINWINDOW12P_H
