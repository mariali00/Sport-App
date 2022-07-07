#ifndef PRUEBAS_H
#define PRUEBAS_H


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QPalette>
#include <QColor>
#include <QWidget>
//*******nuevas bibliotecas incluidas************
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
class pruebas;
}

class pruebas : public QMainWindow
{
    Q_OBJECT

public:
    explicit pruebas(QWidget *parent = 0);
    ~pruebas();

private:
    Ui::pruebas *ui;
};

#endif // PRUEBAS_H
