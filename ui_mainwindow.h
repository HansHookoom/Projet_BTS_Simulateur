/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titre;
    QPushButton *connexion;
    QPushButton *ventilateurs_on;
    QTextEdit *textEdit;
    QLabel *titre_2;
    QPushButton *deconnexion;
    QLabel *titre_3;
    QTextEdit *textEdit_2;
    QLabel *titre_4;
    QPushButton *ventilateurs_off;
    QPushButton *extracteurs_off;
    QPushButton *extracteurs_on;
    QLabel *titre_5;
    QPushButton *pluie_off;
    QPushButton *pluie_on;
    QLabel *titre_6;
    QLabel *titre_7;
    QPushButton *natte_on;
    QPushButton *natte_off;
    QLabel *titre_8;
    QPushButton *ir_on;
    QPushButton *ir_off;
    QLabel *titre_9;
    QPushButton *uv_on;
    QPushButton *uv_off;
    QPushButton *depart;
    QPushButton *arret;
    QTextEdit *textEdit_3;
    QLCDNumber *lcdNumber;
    QComboBox *comboBox;
    QPushButton *port_button;
    QPushButton *camera_button;
    QPushButton *balance_button;
    QPushButton *port_button_close;
    QTextEdit *textEdit_cam;
    QTextEdit *textEdit_balance;
    QLabel *label_etat_timer;
    QPushButton *bdd_archivage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1102, 718);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(157, 157, 157, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(236, 236, 236, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(196, 196, 196, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(78, 78, 78, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(105, 105, 105, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(206, 206, 206, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titre = new QLabel(centralwidget);
        titre->setObjectName(QString::fromUtf8("titre"));
        titre->setGeometry(QRect(210, 30, 371, 31));
        titre->setStyleSheet(QString::fromUtf8("font:24px;\n"
"color: rgb(0, 85, 255);"));
        connexion = new QPushButton(centralwidget);
        connexion->setObjectName(QString::fromUtf8("connexion"));
        connexion->setGeometry(QRect(40, 20, 111, 51));
        ventilateurs_on = new QPushButton(centralwidget);
        ventilateurs_on->setObjectName(QString::fromUtf8("ventilateurs_on"));
        ventilateurs_on->setGeometry(QRect(130, 90, 71, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(920, 240, 141, 71));
        textEdit->setStyleSheet(QString::fromUtf8("font:24px;\n"
"color: rgb(255, 0, 0);"));
        titre_2 = new QLabel(centralwidget);
        titre_2->setObjectName(QString::fromUtf8("titre_2"));
        titre_2->setGeometry(QRect(920, 200, 151, 31));
        titre_2->setStyleSheet(QString::fromUtf8("font:24px;\n"
"color: rgb(0, 85, 255);"));
        deconnexion = new QPushButton(centralwidget);
        deconnexion->setObjectName(QString::fromUtf8("deconnexion"));
        deconnexion->setGeometry(QRect(650, 20, 111, 51));
        titre_3 = new QLabel(centralwidget);
        titre_3->setObjectName(QString::fromUtf8("titre_3"));
        titre_3->setGeometry(QRect(920, 340, 91, 31));
        titre_3->setStyleSheet(QString::fromUtf8("font:24px;\n"
"color: rgb(0, 85, 255);"));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(920, 370, 141, 71));
        textEdit_2->setStyleSheet(QString::fromUtf8("font:24px;\n"
"color: rgb(255, 0, 0);"));
        titre_4 = new QLabel(centralwidget);
        titre_4->setObjectName(QString::fromUtf8("titre_4"));
        titre_4->setGeometry(QRect(20, 90, 111, 41));
        titre_4->setStyleSheet(QString::fromUtf8("font:18px;"));
        ventilateurs_off = new QPushButton(centralwidget);
        ventilateurs_off->setObjectName(QString::fromUtf8("ventilateurs_off"));
        ventilateurs_off->setGeometry(QRect(210, 90, 71, 41));
        extracteurs_off = new QPushButton(centralwidget);
        extracteurs_off->setObjectName(QString::fromUtf8("extracteurs_off"));
        extracteurs_off->setGeometry(QRect(210, 160, 71, 41));
        extracteurs_on = new QPushButton(centralwidget);
        extracteurs_on->setObjectName(QString::fromUtf8("extracteurs_on"));
        extracteurs_on->setGeometry(QRect(130, 160, 71, 41));
        titre_5 = new QLabel(centralwidget);
        titre_5->setObjectName(QString::fromUtf8("titre_5"));
        titre_5->setGeometry(QRect(20, 160, 111, 41));
        titre_5->setStyleSheet(QString::fromUtf8("font:18px;"));
        pluie_off = new QPushButton(centralwidget);
        pluie_off->setObjectName(QString::fromUtf8("pluie_off"));
        pluie_off->setGeometry(QRect(210, 230, 71, 41));
        pluie_on = new QPushButton(centralwidget);
        pluie_on->setObjectName(QString::fromUtf8("pluie_on"));
        pluie_on->setGeometry(QRect(130, 230, 71, 41));
        titre_6 = new QLabel(centralwidget);
        titre_6->setObjectName(QString::fromUtf8("titre_6"));
        titre_6->setGeometry(QRect(20, 230, 111, 41));
        titre_6->setStyleSheet(QString::fromUtf8("font:18px;"));
        titre_7 = new QLabel(centralwidget);
        titre_7->setObjectName(QString::fromUtf8("titre_7"));
        titre_7->setGeometry(QRect(20, 300, 111, 41));
        titre_7->setStyleSheet(QString::fromUtf8("font:18px;"));
        natte_on = new QPushButton(centralwidget);
        natte_on->setObjectName(QString::fromUtf8("natte_on"));
        natte_on->setGeometry(QRect(130, 300, 71, 41));
        natte_off = new QPushButton(centralwidget);
        natte_off->setObjectName(QString::fromUtf8("natte_off"));
        natte_off->setGeometry(QRect(210, 300, 71, 41));
        titre_8 = new QLabel(centralwidget);
        titre_8->setObjectName(QString::fromUtf8("titre_8"));
        titre_8->setGeometry(QRect(20, 370, 111, 41));
        titre_8->setStyleSheet(QString::fromUtf8("font:18px;"));
        ir_on = new QPushButton(centralwidget);
        ir_on->setObjectName(QString::fromUtf8("ir_on"));
        ir_on->setGeometry(QRect(130, 370, 71, 41));
        ir_off = new QPushButton(centralwidget);
        ir_off->setObjectName(QString::fromUtf8("ir_off"));
        ir_off->setGeometry(QRect(210, 370, 71, 41));
        titre_9 = new QLabel(centralwidget);
        titre_9->setObjectName(QString::fromUtf8("titre_9"));
        titre_9->setGeometry(QRect(20, 440, 111, 41));
        titre_9->setStyleSheet(QString::fromUtf8("font:18px;"));
        uv_on = new QPushButton(centralwidget);
        uv_on->setObjectName(QString::fromUtf8("uv_on"));
        uv_on->setGeometry(QRect(130, 440, 71, 41));
        uv_off = new QPushButton(centralwidget);
        uv_off->setObjectName(QString::fromUtf8("uv_off"));
        uv_off->setGeometry(QRect(210, 440, 71, 41));
        depart = new QPushButton(centralwidget);
        depart->setObjectName(QString::fromUtf8("depart"));
        depart->setGeometry(QRect(790, 240, 111, 51));
        arret = new QPushButton(centralwidget);
        arret->setObjectName(QString::fromUtf8("arret"));
        arret->setGeometry(QRect(790, 300, 111, 51));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(810, 20, 271, 70));
        textEdit_3->setStyleSheet(QString::fromUtf8("font:16px;\n"
"color: rgb(255, 0, 0);"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(810, 120, 271, 71));
        lcdNumber->setDigitCount(8);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(890, 480, 171, 41));
        port_button = new QPushButton(centralwidget);
        port_button->setObjectName(QString::fromUtf8("port_button"));
        port_button->setGeometry(QRect(920, 540, 141, 51));
        camera_button = new QPushButton(centralwidget);
        camera_button->setObjectName(QString::fromUtf8("camera_button"));
        camera_button->setGeometry(QRect(40, 520, 111, 31));
        balance_button = new QPushButton(centralwidget);
        balance_button->setObjectName(QString::fromUtf8("balance_button"));
        balance_button->setGeometry(QRect(170, 520, 111, 31));
        port_button_close = new QPushButton(centralwidget);
        port_button_close->setObjectName(QString::fromUtf8("port_button_close"));
        port_button_close->setGeometry(QRect(920, 610, 141, 51));
        textEdit_cam = new QTextEdit(centralwidget);
        textEdit_cam->setObjectName(QString::fromUtf8("textEdit_cam"));
        textEdit_cam->setGeometry(QRect(40, 570, 111, 51));
        textEdit_cam->setStyleSheet(QString::fromUtf8("font:16px;\n"
"color: rgb(255, 0, 0);"));
        textEdit_balance = new QTextEdit(centralwidget);
        textEdit_balance->setObjectName(QString::fromUtf8("textEdit_balance"));
        textEdit_balance->setGeometry(QRect(170, 570, 111, 51));
        textEdit_balance->setStyleSheet(QString::fromUtf8("font:16px;\n"
"color: rgb(255, 0, 0);"));
        label_etat_timer = new QLabel(centralwidget);
        label_etat_timer->setObjectName(QString::fromUtf8("label_etat_timer"));
        label_etat_timer->setGeometry(QRect(790, 200, 121, 41));
        label_etat_timer->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 12px;"));
        bdd_archivage = new QPushButton(centralwidget);
        bdd_archivage->setObjectName(QString::fromUtf8("bdd_archivage"));
        bdd_archivage->setGeometry(QRect(790, 370, 111, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1102, 20));
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
        titre->setText(QApplication::translate("MainWindow", "Test unitaire de la classe ModBus", nullptr));
        connexion->setText(QApplication::translate("MainWindow", "Connexion", nullptr));
        ventilateurs_on->setText(QApplication::translate("MainWindow", "ON", nullptr));
        titre_2->setText(QApplication::translate("MainWindow", "Temp\303\251rature", nullptr));
        deconnexion->setText(QApplication::translate("MainWindow", "D\303\251connexion", nullptr));
        titre_3->setText(QApplication::translate("MainWindow", "Niveau", nullptr));
        titre_4->setText(QApplication::translate("MainWindow", "Ventilateurs :", nullptr));
        ventilateurs_off->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        extracteurs_off->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        extracteurs_on->setText(QApplication::translate("MainWindow", "ON", nullptr));
        titre_5->setText(QApplication::translate("MainWindow", "Extracteurs :", nullptr));
        pluie_off->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        pluie_on->setText(QApplication::translate("MainWindow", "ON", nullptr));
        titre_6->setText(QApplication::translate("MainWindow", "Pluie", nullptr));
        titre_7->setText(QApplication::translate("MainWindow", "Natte", nullptr));
        natte_on->setText(QApplication::translate("MainWindow", "ON", nullptr));
        natte_off->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        titre_8->setText(QApplication::translate("MainWindow", "Lampe IR", nullptr));
        ir_on->setText(QApplication::translate("MainWindow", "ON", nullptr));
        ir_off->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        titre_9->setText(QApplication::translate("MainWindow", "Lampe UV", nullptr));
        uv_on->setText(QApplication::translate("MainWindow", "ON", nullptr));
        uv_off->setText(QApplication::translate("MainWindow", "OFF", nullptr));
        depart->setText(QApplication::translate("MainWindow", "D\303\251part Cycle", nullptr));
        arret->setText(QApplication::translate("MainWindow", "Arret Cycle", nullptr));
        textEdit_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:16px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:16px;\">172.16.150.3</span></p></body></html>", nullptr));
        port_button->setText(QApplication::translate("MainWindow", "Valider port", nullptr));
        camera_button->setText(QApplication::translate("MainWindow", "Cam\303\251ra", nullptr));
        balance_button->setText(QApplication::translate("MainWindow", "Balance", nullptr));
        port_button_close->setText(QApplication::translate("MainWindow", "Fermer port", nullptr));
        label_etat_timer->setText(QApplication::translate("MainWindow", "Etat Timer :", nullptr));
        bdd_archivage->setText(QApplication::translate("MainWindow", "BDD MySQL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
