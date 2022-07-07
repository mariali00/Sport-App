#ifndef MAINWINDOW8_H
#define MAINWINDOW8_H

#include <QMainWindow>
#include <mainwindow9.h>
#include <mainwindow6.h>

namespace Ui {
class MainWindow8;
}

class MainWindow8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow8(QWidget *parent = 0);
    ~MainWindow8();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow8 *ui;
};

#endif // MAINWINDOW8_H
