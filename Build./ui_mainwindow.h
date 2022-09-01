/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelVitesse;
    QLabel *labelRegime;
    QLabel *labelBoite;
    QLabel *labelEtat;
    QLabel *labelTempEau;
    QLabel *labelCapEau;
    QLabel *labelCapHuile;
    QLabel *labelCapAir;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *demarre;
    QPushButton *arreter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelVitesse = new QLabel(centralwidget);
        labelVitesse->setObjectName(QString::fromUtf8("labelVitesse"));
        labelVitesse->setGeometry(QRect(340, 10, 261, 41));
        labelRegime = new QLabel(centralwidget);
        labelRegime->setObjectName(QString::fromUtf8("labelRegime"));
        labelRegime->setGeometry(QRect(340, 60, 191, 41));
        labelBoite = new QLabel(centralwidget);
        labelBoite->setObjectName(QString::fromUtf8("labelBoite"));
        labelBoite->setGeometry(QRect(340, 110, 151, 41));
        labelEtat = new QLabel(centralwidget);
        labelEtat->setObjectName(QString::fromUtf8("labelEtat"));
        labelEtat->setGeometry(QRect(340, 170, 171, 41));
        labelTempEau = new QLabel(centralwidget);
        labelTempEau->setObjectName(QString::fromUtf8("labelTempEau"));
        labelTempEau->setGeometry(QRect(340, 230, 71, 21));
        labelCapEau = new QLabel(centralwidget);
        labelCapEau->setObjectName(QString::fromUtf8("labelCapEau"));
        labelCapEau->setGeometry(QRect(340, 270, 171, 41));
        labelCapHuile = new QLabel(centralwidget);
        labelCapHuile->setObjectName(QString::fromUtf8("labelCapHuile"));
        labelCapHuile->setGeometry(QRect(340, 330, 161, 41));
        labelCapAir = new QLabel(centralwidget);
        labelCapAir->setObjectName(QString::fromUtf8("labelCapAir"));
        labelCapAir->setGeometry(QRect(340, 370, 251, 61));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 20, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 80, 91, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 120, 101, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 180, 101, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 230, 151, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 280, 101, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 330, 91, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(210, 380, 101, 31));
        demarre = new QPushButton(centralwidget);
        demarre->setObjectName(QString::fromUtf8("demarre"));
        demarre->setGeometry(QRect(560, 40, 101, 31));
        arreter = new QPushButton(centralwidget);
        arreter->setObjectName(QString::fromUtf8("arreter"));
        arreter->setGeometry(QRect(560, 80, 101, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labelVitesse->setText(QApplication::translate("MainWindow", "XVitesse", nullptr));
        labelRegime->setText(QApplication::translate("MainWindow", "XRegime", nullptr));
        labelBoite->setText(QApplication::translate("MainWindow", "XBV", nullptr));
        labelEtat->setText(QApplication::translate("MainWindow", "XEtat Moteur", nullptr));
        labelTempEau->setText(QApplication::translate("MainWindow", "XTE", nullptr));
        labelCapEau->setText(QApplication::translate("MainWindow", "XCap Eau", nullptr));
        labelCapHuile->setText(QApplication::translate("MainWindow", "XCap Huile", nullptr));
        labelCapAir->setText(QApplication::translate("MainWindow", "XCap Air", nullptr));
        label->setText(QApplication::translate("MainWindow", "Vitesse(km/h)", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Regime(tr/min)", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Boite de vitesse", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Etat Moteur", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Temp\303\251rature d'eau(\302\260C)", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Capteur D'eau", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Capteur D'huile", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Capteur D'air", nullptr));
        demarre->setText(QApplication::translate("MainWindow", "D\303\251marrer", nullptr));
        arreter->setText(QApplication::translate("MainWindow", "Arr\303\252ter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
