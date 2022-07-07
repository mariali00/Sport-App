#ifndef MAINWINDOWBD_H
#define MAINWINDOWBD_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class MainWindowBD;
}

class MainWindowBD : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowBD(QWidget *parent = 0);
    ~MainWindowBD();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindowBD *ui;
};

#endif // MAINWINDOWBD_H
