#ifndef MAINWINDOW6_H
#define MAINWINDOW6_H

#include <QMainWindow>
#include <mainwindow7.h>
#include <mainwindow8.h>
#include <mainwindow5p.h>

namespace Ui {
class MainWindow6;
}

class MainWindow6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow6(QWidget *parent = 0);
    ~MainWindow6();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow6 *ui;
};

#endif // MAINWINDOW6_H
