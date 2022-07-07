#ifndef MAINWINDOW11_H
#define MAINWINDOW11_H

#include <QMainWindow>
#include <mainwindow10.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow11;
}

class MainWindow11 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow11(QWidget *parent = 0);
    ~MainWindow11();
    QString idgrupo;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow11 *ui;
};

#endif // MAINWINDOW11_H
