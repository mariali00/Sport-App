/********************************************************************************
** Form generated from reading UI file 'mainwindow3.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW3_H
#define UI_MAINWINDOW3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow3
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;

    void setupUi(QMainWindow *MainWindow3)
    {
        if (MainWindow3->objectName().isEmpty())
            MainWindow3->setObjectName(QStringLiteral("MainWindow3"));
        MainWindow3->resize(300, 250);
        MainWindow3->setMinimumSize(QSize(300, 250));
        MainWindow3->setMaximumSize(QSize(300, 250));
        MainWindow3->setSizeIncrement(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow3->setWindowIcon(icon);
        MainWindow3->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow3);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(10, 10, 30, 30));
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/atras.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(25, 30));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 140, 239, 25));
        pushButton_4->setMinimumSize(QSize(0, 25));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton_4->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 100, 239, 25));
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(40, 60, 239, 25));
        pushButton->setMinimumSize(QSize(0, 25));
        pushButton->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 180, 239, 25));
        pushButton_5->setMinimumSize(QSize(0, 25));
        pushButton_5->setFont(font);
        MainWindow3->setCentralWidget(centralwidget);

        retranslateUi(MainWindow3);

        QMetaObject::connectSlotsByName(MainWindow3);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow3)
    {
        MainWindow3->setWindowTitle(QApplication::translate("MainWindow3", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_4->setText(QApplication::translate("MainWindow3", "Modificar Grupo", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow3", "Crear Grupo", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow3", "Ir a Grupo", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow3", "Obtener Reporte General", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow3: public Ui_MainWindow3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW3_H
