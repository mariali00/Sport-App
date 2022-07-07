#ifndef MAINWINDOW7_H
#define MAINWINDOW7_H

#include <QMainWindow>
#include <mainwindow6.h>


namespace Ui {
class MainWindow7;
}

class MainWindow7 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow7(QWidget *parent = 0);
    ~MainWindow7();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow7 *ui;
};

#endif // MAINWINDOW7_H
