/********************************************************************************
** Form generated from reading UI file 'mainwindow4.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW4_H
#define UI_MAINWINDOW4_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow4
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow4)
    {
        if (MainWindow4->objectName().isEmpty())
            MainWindow4->setObjectName(QStringLiteral("MainWindow4"));
        MainWindow4->resize(370, 350);
        MainWindow4->setMinimumSize(QSize(370, 350));
        MainWindow4->setMaximumSize(QSize(370, 350));
        MainWindow4->setSizeIncrement(QSize(300, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow4->setWindowIcon(icon);
        MainWindow4->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow4);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 290, 89, 25));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(10, 10, 30, 30));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/atras.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 10, 171, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 351, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        comboBox_4 = new QComboBox(verticalLayoutWidget);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setFont(font);

        horizontalLayout_4->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        comboBox_3 = new QComboBox(verticalLayoutWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setFont(font);

        horizontalLayout_3->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setFont(font);

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        comboBox_5 = new QComboBox(verticalLayoutWidget);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setFont(font);

        horizontalLayout_5->addWidget(comboBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow4->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow4);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 370, 21));
        MainWindow4->setMenuBar(menubar);

        retranslateUi(MainWindow4);

        QMetaObject::connectSlotsByName(MainWindow4);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow4)
    {
        MainWindow4->setWindowTitle(QApplication::translate("MainWindow4", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow4", "OK", Q_NULLPTR));
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("MainWindow4", "IR A GRUPO", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow4", "Grupo:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow4", "Anno: ", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow4", "1ERO", Q_NULLPTR)
         << QApplication::translate("MainWindow4", "2DO", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow4", "Curso", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow4", "Carrera: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow4", "Educacion Fisica", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow4", "I", Q_NULLPTR)
         << QApplication::translate("MainWindow4", "II", Q_NULLPTR)
         << QApplication::translate("MainWindow4", "III", Q_NULLPTR)
         << QApplication::translate("MainWindow4", "IV", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow4: public Ui_MainWindow4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW4_H
