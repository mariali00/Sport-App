#include "peso.h"
#include "ui_peso.h"

peso::peso(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::peso)
{
    ui->setupUi(this);

}

peso::~peso()
{
    delete ui;
}

