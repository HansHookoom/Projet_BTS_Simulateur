#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MAX 9680

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDir>
#include <QDateTime>
#include <QtSql>
#include <QMessageBox>

#include "ModBusTCP.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void acquisition_temp_clone();

    void acquisition_niveau_clone();

    void acquisition_temp_cam();

    void heure();

    void enregistrement_csv();

    void on_connexion_clicked();

    void on_deconnexion_clicked();

    void on_ventilateurs_on_clicked();

    void on_ventilateurs_off_clicked();

    void on_extracteurs_on_clicked();

    void on_extracteurs_off_clicked();

    void on_pluie_on_clicked();

    void on_pluie_off_clicked();

    void on_natte_on_clicked();

    void on_natte_off_clicked();

    void on_ir_on_clicked();

    void on_ir_off_clicked();

    void on_uv_on_clicked();

    void on_uv_off_clicked();

    void on_depart_clicked();

    void on_arret_clicked();

    void on_port_button_clicked();

    void on_camera_button_clicked();

    void on_balance_button_clicked();

    void on_port_button_close_clicked();

    void on_bdd_archivage_clicked();

private:
    Ui::MainWindow *ui;

    int err_port;
    int j;
    int k;
    unsigned short temp, niveau;
    bool connection_api;

    // Délaration objet dynamique
    ModBusTCP *clientTCP;
    QTimer *timer_clone_temp;
    QTimer *timer_clone_niveau;
    QTimer *timer_csv;
    QTimer *timer_heure;
    QTimer *timer_temp;

    // Délaration objet statiques
    QString current_time, nameFile;
    QMessageBox msg_err;
    QTime time;
    QByteArray temp_cam, poids;
    QSqlDatabase db;

    //Liaison série :
    QSerialPort serie;
    QSerialPortInfo info;
    QString nomPort; // Le nom du port
    QList <QSerialPortInfo> portList;
};
#endif // MAINWINDOW_H
