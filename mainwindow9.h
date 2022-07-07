#ifndef MAINWINDOW9_H
#define MAINWINDOW9_H

#include <QMainWindow>
#include <mainwindow8.h>

namespace Ui {
class MainWindow9;
}

class MainWindow9 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow9(QWidget *parent = 0);
    ~MainWindow9();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow9 *ui;
};

#endif // MAINWINDOW9_H
