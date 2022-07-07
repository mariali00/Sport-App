/********************************************************************************
** Form generated from reading UI file 'mainwindow12p.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW12P_H
#define UI_MAINWINDOW12P_H

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

class Ui_MainWindow12p
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow12p)
    {
        if (MainWindow12p->objectName().isEmpty())
            MainWindow12p->setObjectName(QStringLiteral("MainWindow12p"));
        MainWindow12p->resize(300, 350);
        MainWindow12p->setMinimumSize(QSize(300, 350));
        MainWindow12p->setMaximumSize(QSize(300, 350));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow12p->setWindowIcon(icon);
        MainWindow12p->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow12p);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 50, 271, 31));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        horizontalLayoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        horizontalLayout->addWidget(comboBox);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 90, 271, 31));
        horizontalLayoutWidget_2->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(horizontalLayoutWidget_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setFont(font);

        horizontalLayout_2->addWidget(comboBox_2);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 170, 271, 31));
        horizontalLayoutWidget_3->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        comboBox_4 = new QComboBox(horizontalLayoutWidget_3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setFont(font);

        horizontalLayout_3->addWidget(comboBox_4);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 290, 89, 25));
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
        icon1.addFile(QStringLiteral(":/imgenes/imgenes/atras - copia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 0, 241, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 130, 271, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        comboBox_3 = new QComboBox(horizontalLayoutWidget_4);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setFont(font);

        horizontalLayout_4->addWidget(comboBox_3);

        horizontalLayoutWidget_5 = new QWidget(centralwidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 210, 271, 31));
        horizontalLayoutWidget_5->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        comboBox_5 = new QComboBox(horizontalLayoutWidget_5);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setFont(font);

        horizontalLayout_5->addWidget(comboBox_5);

        MainWindow12p->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow12p);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 21));
        MainWindow12p->setMenuBar(menubar);

        retranslateUi(MainWindow12p);

        QMetaObject::connectSlotsByName(MainWindow12p);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow12p)
    {
        MainWindow12p->setWindowTitle(QApplication::translate("MainWindow12p", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow12p", "Curso:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow12p", "Carrera: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow12p", "Grupo: ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow12p", "OK", Q_NULLPTR));
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("MainWindow12p", "MODIFICAR GRUPO", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow12p", "A\303\261o:", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow12p", "1ERO", Q_NULLPTR)
         << QApplication::translate("MainWindow12p", "2DO", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("MainWindow12p", "Asignatura: ", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow12p", "I", Q_NULLPTR)
         << QApplication::translate("MainWindow12p", "II", Q_NULLPTR)
         << QApplication::translate("MainWindow12p", "III", Q_NULLPTR)
         << QApplication::translate("MainWindow12p", "IV", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow12p: public Ui_MainWindow12p {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW12P_H
