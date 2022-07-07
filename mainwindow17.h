#ifndef MAINWINDOW17_H
#define MAINWINDOW17_H

#include <QMainWindow>
#include <mainwindow3.h>
#include <util.h>

namespace Ui {
class MainWindow17;
}

class MainWindow17 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow17(QWidget *parent = 0);
    ~MainWindow17();

private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow17 *ui;
};

#endif // MAINWINDOW17_H
