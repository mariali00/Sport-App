/********************************************************************************
** Form generated from reading UI file 'mainwindow11.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW11_H
#define UI_MAINWINDOW11_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow11
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow11)
    {
        if (MainWindow11->objectName().isEmpty())
            MainWindow11->setObjectName(QStringLiteral("MainWindow11"));
        MainWindow11->resize(850, 400);
        MainWindow11->setMinimumSize(QSize(850, 400));
        MainWindow11->setMaximumSize(QSize(850, 400));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow11->setWindowIcon(icon);
        MainWindow11->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow11);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 340, 89, 25));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 251, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 30, 30));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgenes/imgenes/atras - copia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 50, 500, 271));
        tableWidget->setMinimumSize(QSize(500, 0));
        tableWidget->setMaximumSize(QSize(500, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        tableWidget->setFont(font2);
        tableWidget->setFrameShape(QFrame::Panel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setMidLineWidth(1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 60, 311, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(540, 110, 301, 25));
        lineEdit->setFont(font3);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(540, 160, 89, 25));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_3->setFont(font4);
        MainWindow11->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow11);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 21));
        MainWindow11->setMenuBar(menubar);

        retranslateUi(MainWindow11);

        QMetaObject::connectSlotsByName(MainWindow11);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow11)
    {
        MainWindow11->setWindowTitle(QApplication::translate("MainWindow11", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow11", "OK", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow11", "CREAR GRUPO", Q_NULLPTR));
        pushButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow11", "Nombre", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow11", "Inserte el nombre del estudiante", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow11", "Insertar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow11: public Ui_MainWindow11 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW11_H
