/********************************************************************************
** Form generated from reading UI file 'mainwindow12.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW12_H
#define UI_MAINWINDOW12_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow12
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_4;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow12)
    {
        if (MainWindow12->objectName().isEmpty())
            MainWindow12->setObjectName(QStringLiteral("MainWindow12"));
        MainWindow12->resize(300, 250);
        MainWindow12->setMinimumSize(QSize(300, 250));
        MainWindow12->setMaximumSize(QSize(300, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow12->setWindowIcon(icon);
        MainWindow12->setStyleSheet(QLatin1String("QPushButton \n"
"{\n"
"	border-radius:5px;\n"
"	background-color: \"white\";\n"
"}\n"
"\n"
"QPushButton:hover { background-color: rgb(200,200,200)}\n"
"\n"
"#centralwidget\n"
"{\n"
"border-image: url(:/images/fondo.jpg);\n"
"}"));
        centralwidget = new QWidget(MainWindow12);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 150, 241, 25));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        pushButton_4->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 0, 241, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 70, 241, 25));
        pushButton_2->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 30, 30));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgenes/imgenes/atras - copia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 110, 241, 25));
        pushButton_3->setFont(font);
        MainWindow12->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow12);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 21));
        MainWindow12->setMenuBar(menubar);

        retranslateUi(MainWindow12);

        QMetaObject::connectSlotsByName(MainWindow12);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow12)
    {
        MainWindow12->setWindowTitle(QApplication::translate("MainWindow12", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow12", "Modificar datos de Alumno", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow12", "Carrera y Grupo", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow12", "Agregar Alumno", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow12", "Eliminar Alumno", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow12: public Ui_MainWindow12 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW12_H
