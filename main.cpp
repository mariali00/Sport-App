#include "mainwindow.h"
#include "mainwindow2.h"
#include <QApplication>
#include <QDebug>
#include <util.h>
#include "test.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DB database;
    //creando o cargando base de datos
    database.createDB();
    //verificando que la base de datos no esta vacia
    //base de datos con contenido

    if(database.EmptyProfile())
    {
        MainWindow2 v;
        v.show();
        return a.exec();
    }
    else
    {
        MainWindow w;
        w.show();
        return a.exec();
    }

}
