#ifndef PESO_H
#define PESO_H

#include <QMainWindow>
#include <mainwindow5p.h>
namespace Ui {
class peso;
}

class peso : public QMainWindow
{
    Q_OBJECT

public:
    explicit peso(QWidget *parent = 0);
    ~peso();


private:
    Ui::peso *ui;

};

#endif // PESO_H
