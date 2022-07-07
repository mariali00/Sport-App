/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHerramienta_de_autoevaluacion;
    QAction *actionRestaurar_ajustes_predeterminados;
    QAction *actionAcerca_de;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(400, 250);
        MainWindow->setMinimumSize(QSize(400, 250));
        MainWindow->setMaximumSize(QSize(400, 250));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/res/registro2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolTipDuration(-1);
        MainWindow->setStyleSheet(QLatin1String("QPushButton \n"
"{\n"
"	border-radius:5px;\n"
"	background-color: \"white\";\n"
"}\n"
"\n"
"QPushButton:hover { background-color: rgb(200,200,200)}\n"
"\n"
"#centralWidget\n"
"{\n"
"border-image: url(:/images/fondo.jpg);\n"
"}\n"
""));
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionHerramienta_de_autoevaluacion = new QAction(MainWindow);
        actionHerramienta_de_autoevaluacion->setObjectName(QStringLiteral("actionHerramienta_de_autoevaluacion"));
        actionRestaurar_ajustes_predeterminados = new QAction(MainWindow);
        actionRestaurar_ajustes_predeterminados->setObjectName(QStringLiteral("actionRestaurar_ajustes_predeterminados"));
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 371, 81));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color=\"red\""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 120, 101, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 120, 141, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setBold(false);
        font2.setWeight(50);
        lineEdit->setFont(font2);
        lineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 120, 89, 25));
        pushButton->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QStringLiteral("menuInfo"));
        MainWindow->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(pushButton);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuInfo->menuAction());
        menuInfo->addAction(actionAcerca_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Educaci\303\263n F\303\255sica UO", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        actionHerramienta_de_autoevaluacion->setText(QApplication::translate("MainWindow", "Herramienta de autoevaluacion", Q_NULLPTR));
        actionRestaurar_ajustes_predeterminados->setText(QApplication::translate("MainWindow", "Restaurar ajustes predeterminados", Q_NULLPTR));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de ...", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "BIENVENIDO", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Contrase\303\261a:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>password</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "Entrar", Q_NULLPTR));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
