#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // Constructeur
{
    ui->setupUi(this);
    // Création des objets dynamiques et initialisation des attributs

    //clientTCP = new ModBusTCP("172.16.150.3", 0x01);
    timer_clone_temp = new QTimer(this);
    connect(timer_clone_temp, &QTimer::timeout, this, &MainWindow::acquisition_temp_clone);

    timer_clone_niveau = new QTimer(this);
    connect(timer_clone_niveau, &QTimer::timeout, this, &MainWindow::acquisition_niveau_clone);

    timer_csv = new QTimer(this);
    connect(timer_csv, &QTimer::timeout, this, &MainWindow::enregistrement_csv);

    timer_heure = new QTimer(this);
    connect(timer_heure, &QTimer::timeout, this, &MainWindow::heure);

    timer_temp = new QTimer(this);
    connect(timer_temp, &QTimer::timeout, this, &MainWindow::acquisition_temp_cam);

    connection_api = false;
    ui->label_etat_timer->setText("Etat Timer : OFF");

    int i;
    j =0;
    k = 0;
    //temp = 0;
    //niveau = 0;

    // Afficher la liste de PORTS disponibles
    portList = info.availablePorts();

    for (i = 0; i < portList.size(); ++i) {
        ui->comboBox->addItem(portList[i].portName());
    }

    timer_heure -> start(1000);
}

MainWindow::~MainWindow() // Destructeur
{
    timer_clone_temp -> stop();
    timer_clone_niveau -> stop();
    timer_csv->stop();
    timer_temp->stop();
    serie.close();
    delete ui;
}

//----------------------- API CONNEXION / DECONNEXION -----------------------//

void MainWindow::on_connexion_clicked() // Connexion à l'API
{
    // Connection à l'API en modeBusTCP

    QString ip;
    ip = ui->textEdit_3->toPlainText();
    QByteArray tabIp= ip.toLatin1();
    clientTCP = new ModBusTCP(tabIp.data(), 0x01);

    int erreur;
    erreur = clientTCP->Connect();
    qDebug () << erreur;

    if (erreur == -1)
    {
        msg_err.setText("Attention : erreur de connection à l'API");
        msg_err.exec();
    }
    else
    {
        msg_err.setText("Connection à l'API réussie");
        msg_err.exec();
        connection_api = true;
    }
}

void MainWindow::on_deconnexion_clicked() // Déconnexion à l'API
{
    timer_clone_temp -> stop();
    timer_clone_niveau -> stop();

    int erreur = clientTCP->DisConnect();
    qDebug () << erreur;
    connection_api = false;
    msg_err.setText("Déconnexion à l'API réussie");
    msg_err.exec();

    // Remise à 0 de tous les textEdit
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

//----------------------- TIMER -----------------------//

void MainWindow::on_depart_clicked() // --- Départ autorisé seulement si il y a connexion à l'API
{
    if (connection_api == false)
    {
        ui->label_etat_timer->setText("Etat Timer : OFF");
        msg_err.setText("Attention : erreur de connection à l'API, aucun CSV ne sera créé ...");
        msg_err.exec();
    }
    else
    {
        timer_clone_temp -> start(1000);
        timer_clone_niveau -> start(1000);
        timer_csv -> start(5000); // Enregistrement en CSV toutes les 5 secondes
        ui->label_etat_timer->setText("Etat Timer : ON");
    }
}

void MainWindow::on_arret_clicked() // Arrêt des timers
{
    timer_clone_temp -> stop();
    timer_clone_niveau -> stop();
    timer_csv -> stop();
    timer_temp->stop();
    ui->label_etat_timer->setText("Etat Timer : OFF");

    //msg_err.setText("Fichier CSV créé !");
    //msg_err.exec();
}

void MainWindow::heure() // Timer Heure courante
{
    time = QTime::currentTime();
    current_time = time.toString("hh:mm:ss");

    ui->lcdNumber->display(current_time);
}

//----------------------- LIAISON SERIE -----------------------//

void MainWindow::on_port_button_clicked() // Ouvrir le port
{
    nomPort = ui->comboBox->currentText(); // ------------- CHOISIR LE COM DU XBEE COORDINATEUR !! -------------

    serie.setPortName(nomPort);
    serie.setBaudRate(QSerialPort::Baud9600);
    serie.setDataBits(QSerialPort::Data8);
    serie.setStopBits(QSerialPort::OneStop);
    serie.setParity(QSerialPort::NoParity);
    serie.setFlowControl(QSerialPort::NoFlowControl);

    msg_err.setText("Port de connexion sélectionnée : "+ nomPort);
    msg_err.exec();

    serie.open(serie.ReadWrite);
    //err_port = serie.isOpen();
}

void MainWindow::on_camera_button_clicked() // Timer caméra
{
    timer_temp->start(60000); // Acquisition températures toutes les minutes
}

void MainWindow::acquisition_temp_cam() // Récupération température caméra depuis le timer caméra
{
    //Entrée

    temp_cam.clear();
    serie.write("+++"); // Commande pour interrogation
    serie.flush();
    while (serie.waitForBytesWritten(500));
    while (serie.waitForReadyRead(3000));
    qDebug() << serie.readAll();

    // Traitement

    serie.write("ATDL 41E4D09E\r\n"); // Xbee Caméra
    serie.flush();
    while (serie.waitForBytesWritten(10000));
    while (serie.waitForReadyRead(10000)); // Attente 10 secondes avant d'envoyer la demande de température
    qDebug() << serie.readAll();

    serie.write("?T(2)\r\n");
    //serie.flush();
    while (serie.waitForBytesWritten(500));
    while (serie.waitForReadyRead(500));
    temp_cam = serie.readLine();
    qDebug() << temp_cam;
    temp_cam = temp_cam.mid(6, 4);
    j++;
    qDebug() << "température numéro " << j << " envoyée :" << temp_cam << " °C";

    // Sortie
    ui->textEdit_cam->setText(temp_cam);
}

void MainWindow::on_balance_button_clicked() // Récupérer poids de la balance
{
    //Entrée

    poids.clear();
    serie.write("+++"); // Commande pour interrogation
    serie.flush();
    while (serie.waitForBytesWritten(500));
    while (serie.waitForReadyRead(3000));
    qDebug() << serie.readAll();

    // Traitement

    serie.write("ATDL 41E4CCB1\r"); // Xbee Balance
    serie.flush();
    while (serie.waitForBytesWritten(10000));
    while (serie.waitForReadyRead(10000)); // Attente 10 secondes avant d'envoyer la demande du poids
    qDebug() << serie.readAll();

    serie.write("s");
    //serie.flush();
    while (serie.waitForBytesWritten(500));
    while (serie.waitForReadyRead(500));
    poids = serie.readAll();
    //poids = poids.mid(6, 4);
    k++;
    qDebug() << "poids numéro " << k << " envoyé :" << poids << " g";

    // Sortie
    ui->textEdit_balance->setText(poids);
}

void MainWindow::on_port_button_close_clicked() // Fermer le port
{
    serie.close();
}

//----------------------- CAPTEURS TOR -----------------------//

void MainWindow::on_ventilateurs_on_clicked() // Allumé Ventilateurs
{
    // Test de la fonction d'écriture f3 sur le registre 0x0064
    int erreur = clientTCP->SendRequete_Fct6(0x0064, 0x01);
    qDebug () << erreur;
}

void MainWindow::on_ventilateurs_off_clicked() // Eteindre Ventilateurs
{
    // Test de la fonction d'écriture f3 sur le registre 0x0064
    int erreur = clientTCP->SendRequete_Fct6(0x0064, 0x00);
    qDebug () << erreur;
}

void MainWindow::on_extracteurs_on_clicked() // Allumé Extracteurs
{
    // Test de la fonction d'écriture f6 sur le registre 0x0065
    int erreur = clientTCP->SendRequete_Fct6(0x0065, 0x01);
    qDebug () << erreur;
}

void MainWindow::on_extracteurs_off_clicked() // Eteindre Extracteurs
{
    int erreur = clientTCP->SendRequete_Fct6(0x0065, 0x00);
    qDebug () << erreur;
}

void MainWindow::on_pluie_on_clicked() // Allumé Pluie
{
    // Test de la fonction d'écriture f6 sur le registre 0x0066
    int erreur = clientTCP->SendRequete_Fct6(0x0066, 0x01);
    qDebug () << erreur;
}

void MainWindow::on_pluie_off_clicked() // Eteindre Pluie
{
    // Test de la fonction d'écriture f6 sur le registre 0x0066
    int erreur = clientTCP->SendRequete_Fct6(0x0066, 0x00);
    qDebug () << erreur;
}

void MainWindow::on_natte_on_clicked() // Allumé natte chauffante
{
    int erreur = clientTCP->SendRequete_Fct6(0x0067, 0x01);
    qDebug () << erreur;
}

void MainWindow::on_natte_off_clicked() // Eteindre natte chauffante
{
    int erreur = clientTCP->SendRequete_Fct6(0x0067, 0x00);
    qDebug () << erreur;
}

void MainWindow::on_ir_on_clicked() // Allumé Infra-rouge
{
    int erreur = clientTCP->SendRequete_Fct6(0x0068, 0x01);
    qDebug () << erreur;
}

void MainWindow::on_ir_off_clicked() // Eteindre Infra-rouge
{
    int erreur = clientTCP->SendRequete_Fct6(0x0068, 0x00);
    qDebug () << erreur;
}

void MainWindow::on_uv_on_clicked() // Allumé Ultra violet
{
    int erreur = clientTCP->SendRequete_Fct6(0x0069, 0x01);
    qDebug () << erreur;
}

void MainWindow::on_uv_off_clicked() // Eteindre Ultra violet
{
    int erreur = clientTCP->SendRequete_Fct6(0x0069, 0x00);
    qDebug () << erreur;
}

//----------------------- CAPTEURS ANALOGIQUES -----------------------//

void MainWindow::acquisition_temp_clone() // Acquisition température du clone
{
    clientTCP->SendRequete_Fct3(0x006A, 0x01);
    int nb=0;

    unsigned short tab_temp[2];
    temp = 0;

    clientTCP -> ReceiveData(tab_temp, &nb);

    if (nb != 0)
    {
        //temp = (tab[0]*100/32767);
        temp = tab_temp[0] * 40/MAX;
        ui->textEdit->setText(QString::number(temp)+"°");
    }
    qDebug () << "température eau" << temp;
}

void MainWindow::acquisition_niveau_clone() // Acquisition niveau du clone
{
    clientTCP->SendRequete_Fct3(0x006B, 0x01);
    int nb=0;

    unsigned short tab_niveau[2];
    niveau = 0;

    clientTCP -> ReceiveData(tab_niveau, &nb);

    if (nb != 0)
    {
        //temp = (tab[0]*100/32767);
        niveau = tab_niveau[0] * 100/MAX;
        ui->textEdit_2->setText(QString::number(niveau)+"%");
    }
    qDebug () << "niveau eau :" << niveau;

}

//----------------------- ARCHIVAGE -----------------------//

void MainWindow::enregistrement_csv() // Enregistrement en fichier CSV des températures + niveau
{
    QString CurrentDir = QDir::currentPath();
    QString sDate = QDateTime::currentDateTime().toString("dd_MM_yy_");
    nameFile = sDate+"acquisition_clone.csv";
    QString pathFile = CurrentDir+"/log_simulateur/"+nameFile;
    qDebug() << "chemin :"<<pathFile;
    QFile file(pathFile); // Appel du constructeur de la classe QFile
    QFileInfo check_file(pathFile);

    if (check_file.exists() && check_file.isFile()) // Si l'objet pointé est un fichier existant
    {
        if (file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)) // Si l'ouverture du fichier en écriture à réussie
        {
            // écrire dans le fichier en utilisant un flux :
            QTextStream out(&file);
            out << current_time << ";" << temp << ";" << niveau << "\n";

            // Fermer le fichier
            file.close();
        }
    }
    else
    {
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) // Si le fichier n'existait pas auparavant
        {
            QTextStream out(&file);
            out << "------------------ Ligne marquant le debut du fichier ayant le nom : " << nameFile << " ------------------\n\n";
            out << "heure;temp (C);niveau (%)\n\n";
            out << current_time << ";" << temp << ";" << niveau << "\n";

            // Fermer le fichier
            file.close();
        }
    }
}

void MainWindow::on_bdd_archivage_clicked() // Enregistrement en Base de Données du fichier CSV
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("simulateur");

    QString LEJOUR = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString lien_vers_fichiers = nameFile;
    qDebug () << LEJOUR;
    qDebug () << lien_vers_fichiers;

    if (db.open())
    {
        qDebug() << "Connecté !";
        QMessageBox::information(this,"connexion", "connexion au serveur réussi");
        // Exécution d'une requête
        QSqlQuery requete;
        if(requete.exec("INSERT INTO `tracabilite`(`LEJOUR`, `lien_vers_fichiers`) VALUES ('"+LEJOUR+"', '"+lien_vers_fichiers+"');"))
        {
            qDebug() << "Ok - requete";
        }
        else
        {
            qDebug() << "Echec de la requête" << requete.lastError();
        }
        db.close(); // Fermeture de la base de données
    }

    else
    {
        qDebug() << "Non Connecté ...";
        QMessageBox::information(this,"Problème","connexion au serveur a echoué");
        qDebug() << db.lastError();
    }
}
