/********************************************************************************
** Form generated from reading UI file 'mainwindow10.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW10_H
#define UI_MAINWINDOW10_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow10
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow10)
    {
        if (MainWindow10->objectName().isEmpty())
            MainWindow10->setObjectName(QStringLiteral("MainWindow10"));
        MainWindow10->resize(400, 350);
        MainWindow10->setMinimumSize(QSize(400, 350));
        MainWindow10->setMaximumSize(QSize(400, 350));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow10->setWindowIcon(icon);
        MainWindow10->setStyleSheet(QLatin1String("QPushButton \n"
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
        centralwidget = new QWidget(MainWindow10);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 30, 30));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgenes/imgenes/atras - copia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 251, 31));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 290, 89, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 371, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMaximumSize(QSize(200, 16777215));
        lineEdit_2->setFont(font1);

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(100, 16777215));
        lineEdit_4->setFont(font1);

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(100, 16777215));
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(70, 0));
        comboBox->setMaximumSize(QSize(70, 16777215));
        comboBox->setFont(font1);

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(70, 0));
        comboBox_2->setMaximumSize(QSize(70, 16777215));
        comboBox_2->setFont(font1);

        horizontalLayout_5->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow10->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow10);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow10->setMenuBar(menubar);
        QWidget::setTabOrder(lineEdit_2, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit);
        QWidget::setTabOrder(lineEdit, comboBox);
        QWidget::setTabOrder(comboBox, comboBox_2);
        QWidget::setTabOrder(comboBox_2, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);

        retranslateUi(MainWindow10);

        QMetaObject::connectSlotsByName(MainWindow10);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow10)
    {
        MainWindow10->setWindowTitle(QApplication::translate("MainWindow10", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("MainWindow10", "CREAR GRUPO", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow10", "OK", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow10", "Carrera: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow10", "Curso", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow10", "Grupo   ", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow10", "A\303\261o", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow10", "1ERO", Q_NULLPTR)
         << QApplication::translate("MainWindow10", "2DO", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("MainWindow10", "Educaci\303\263n F\303\255sica", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow10", "I", Q_NULLPTR)
         << QApplication::translate("MainWindow10", "II", Q_NULLPTR)
         << QApplication::translate("MainWindow10", "III", Q_NULLPTR)
         << QApplication::translate("MainWindow10", "IV", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow10: public Ui_MainWindow10 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW10_H
