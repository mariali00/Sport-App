/********************************************************************************
** Form generated from reading UI file 'mainwindow13.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW13_H
#define UI_MAINWINDOW13_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow13
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow13)
    {
        if (MainWindow13->objectName().isEmpty())
            MainWindow13->setObjectName(QStringLiteral("MainWindow13"));
        MainWindow13->resize(450, 200);
        MainWindow13->setMinimumSize(QSize(450, 200));
        MainWindow13->setMaximumSize(QSize(450, 200));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow13->setWindowIcon(icon);
        MainWindow13->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow13);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 70, 411, 31));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        horizontalLayoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 0, 331, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 30, 30));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgenes/imgenes/atras - copia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 120, 89, 25));
        pushButton_2->setFont(font);
        MainWindow13->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow13);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 21));
        MainWindow13->setMenuBar(menubar);

        retranslateUi(MainWindow13);

        QMetaObject::connectSlotsByName(MainWindow13);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow13)
    {
        MainWindow13->setWindowTitle(QApplication::translate("MainWindow13", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow13", "Nombre:          ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow13", "AGREGAR ALUMNO", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow13", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow13: public Ui_MainWindow13 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW13_H
