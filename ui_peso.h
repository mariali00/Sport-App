/********************************************************************************
** Form generated from reading UI file 'peso.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PESO_H
#define UI_PESO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_peso
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *peso)
    {
        if (peso->objectName().isEmpty())
            peso->setObjectName(QStringLiteral("peso"));
        peso->resize(800, 600);
        centralwidget = new QWidget(peso);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, -10, 621, 271));
        label->setStyleSheet(QStringLiteral("background-image: url(:/imgenes/imgenes/imc.png);"));
        peso->setCentralWidget(centralwidget);
        menubar = new QMenuBar(peso);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        peso->setMenuBar(menubar);
        statusbar = new QStatusBar(peso);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        peso->setStatusBar(statusbar);

        retranslateUi(peso);

        QMetaObject::connectSlotsByName(peso);
    } // setupUi

    void retranslateUi(QMainWindow *peso)
    {
        peso->setWindowTitle(QApplication::translate("peso", "Indice de masa corporal", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class peso: public Ui_peso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PESO_H
