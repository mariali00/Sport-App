/********************************************************************************
** Form generated from reading UI file 'mainwindow14.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW14_H
#define UI_MAINWINDOW14_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow14
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow14)
    {
        if (MainWindow14->objectName().isEmpty())
            MainWindow14->setObjectName(QStringLiteral("MainWindow14"));
        MainWindow14->resize(450, 200);
        MainWindow14->setMinimumSize(QSize(450, 200));
        MainWindow14->setMaximumSize(QSize(450, 200));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow14->setWindowIcon(icon);
        MainWindow14->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow14);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 10, 321, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 30, 30));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgenes/imgenes/atras - copia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 130, 89, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 70, 411, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu Condensed"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        horizontalLayoutWidget->setFont(font2);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_3->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_3);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font3);

        horizontalLayout->addWidget(comboBox);

        MainWindow14->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow14);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 21));
        MainWindow14->setMenuBar(menubar);

        retranslateUi(MainWindow14);

        QMetaObject::connectSlotsByName(MainWindow14);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow14)
    {
        MainWindow14->setWindowTitle(QApplication::translate("MainWindow14", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow14", "ELIMINAR ALUMNO", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow14", "OK", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow14", "Nombre:    ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow14: public Ui_MainWindow14 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW14_H
