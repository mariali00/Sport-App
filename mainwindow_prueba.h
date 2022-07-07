#ifndef MAINWINDOW_PRUEBA_H
#define MAINWINDOW_PRUEBA_H

#include <QMainWindow>


#include <QMainWindow>
#include <QPdfWriter>
#include <QPainter>
#include <QPaintEngine>
#include <QMessageBox>

#include <QTextDocument>
#include <QTextTable>
#include <QTextCursor>

#include <QPrinter>

#include <QDate>


#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow_prueba;
}

class MainWindow_prueba : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_prueba(QWidget *parent = 0);
    ~MainWindow_prueba();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow_prueba *ui;
};

#endif // MAINWINDOW_PRUEBA_H
