/********************************************************************************
** Form generated from reading UI file 'mainwindow16.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW16_H
#define UI_MAINWINDOW16_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow16
{
public:
    QAction *actionRestaurar_ajustes_predeterminados;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuAjustes;

    void setupUi(QMainWindow *MainWindow16)
    {
        if (MainWindow16->objectName().isEmpty())
            MainWindow16->setObjectName(QStringLiteral("MainWindow16"));
        MainWindow16->resize(750, 420);
        MainWindow16->setMinimumSize(QSize(750, 420));
        MainWindow16->setMaximumSize(QSize(750, 420));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow16->setWindowIcon(icon);
        MainWindow16->setStyleSheet(QLatin1String("QPushButton \n"
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
        actionRestaurar_ajustes_predeterminados = new QAction(MainWindow16);
        actionRestaurar_ajustes_predeterminados->setObjectName(QStringLiteral("actionRestaurar_ajustes_predeterminados"));
        centralwidget = new QWidget(MainWindow16);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 360, 131, 25));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 0, 601, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 50, 421, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 360, 141, 25));
        pushButton_2->setFont(font);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 330, 141, 23));
        checkBox->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 20, 30, 30));
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu Condensed"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_3->setFont(font3);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/atras.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(25, 25));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font4);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font4);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font4);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font4);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font4);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font4);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font4);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 90, 711, 231));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial"));
        font5.setBold(true);
        font5.setWeight(75);
        tableWidget->setFont(font5);
        MainWindow16->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow16);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        menuAjustes = new QMenu(menuBar);
        menuAjustes->setObjectName(QStringLiteral("menuAjustes"));
        MainWindow16->setMenuBar(menuBar);

        menuBar->addAction(menuAjustes->menuAction());
        menuAjustes->addAction(actionRestaurar_ajustes_predeterminados);

        retranslateUi(MainWindow16);

        QMetaObject::connectSlotsByName(MainWindow16);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow16)
    {
        MainWindow16->setWindowTitle(QApplication::translate("MainWindow16", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
        actionRestaurar_ajustes_predeterminados->setText(QApplication::translate("MainWindow16", "Restaurar ajustes predeterminados", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow16", "Agregar entrada", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow16", "REGISTRO PARA AUTOEVALUACION", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow16", "Estudiante", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow16", "Eliminar entrada", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow16", "Control Parcial", Q_NULLPTR));
        pushButton_3->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow16", "Fecha", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow16", "Fuerza de brazos", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow16", "Flexibilidad", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow16", "Fuerza abdominal", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow16", "Fuerza explosiva\n"
"de piernas", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow16", "Velocidad", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow16", "Resistencia", Q_NULLPTR));
        menuAjustes->setTitle(QApplication::translate("MainWindow16", "Ajustes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow16: public Ui_MainWindow16 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW16_H
