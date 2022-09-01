#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyACM0");
    serial->setBaudRate(QSerialPort::Baud115200);
    //serial->setDataBits(QSerialPort::Data8);
    //serial->setParity(QSerialPort::NoParity);
    //serial->setStopBits(QSerialPort::OneStop);
    //serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);

    connect(serial, SIGNAL(readyRead()),this, SLOT(messagesRecus()));
    //connect(serial, SIGNAL(readyRead()),this, SLOT(affiche_donnee()));
   // connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(affiche_donnee()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::messagesRecus(){
    QTextStream standardOutput(stdout);
    QByteArray data;
    data = serial->readAll();
    while (serial->waitForReadyRead((10)))
    {
        data.append(serial->readAll());
        //ui->label->setText(data);
 parts = donnee.split(QLatin1Char('\n'));
        standardOutput << "\n" << data << "\n";
   Vitesse = parts.filter("Vitesse");
   Regime = parts.filter("Régime");
   Boite_vit = parts.filter("Rapport");
   Etat_moteur = parts.filter("Etat moteur");
   Temp_eau = parts.filter("Temp Eau");
   Capt_eau = parts.filter("Capteur de température D'eau");
   Capt_air = parts.filter("Capteur de température d’Air");
   Capt_huile = parts.filter("Capteur de température d’huile");




// for (int i = 0; i < Vitesse.size(); ++i){
//                 QString val_vitesse =  Vitesse.at(0).toLocal8Bit().constData() ;
//                  ui->labelVitesse->setText(recupvaleur(val_vitesse));

//        }



// for (int i = 0; i < Etat_moteur.size(); ++i){

//                QString val_BV = Etat_moteur.at(0).toLocal8Bit().constData() ;
//                ui->labelBoite->setText(recupvaleur(val_BV));


//        }


    ui->labelVitesse->setText(valFinal(Vitesse));
    ui->labelRegime->setText(valFinal(Regime));
    ui->labelBoite->setText(valFinal(Boite_vit));
    ui->labelEtat->setText(valFinal(Etat_moteur));
    ui->labelTempEau->setText(valFinal(Temp_eau));
    ui->labelCapEau->setText(valFinal(Capt_eau));
    ui->labelCapHuile->setText(valFinal(Capt_huile));
    ui->labelCapAir->setText(valFinal(Capt_air));
        donnee = QString(data);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //       QString tmp_Vitesse = Vitesse.at(0).toLocal8Bit().constData();
    //      QStringList val_Vitesse = tmp_Vitesse.split(':');
    //          ui->labelVitesse->setText(val_Vitesse.at(1));
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//               QString tmp_Regime = Regime.at(0).toLocal8Bit().constData();
//                QStringList val_Regime = tmp_Regime.split(QLatin1Char(':'));
//               QString labelR = val_Regime.at(1);
//                ui->labelRegime->setText(labelR);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//              QString tmp_Boite_vit = Boite_vit.at(0).toLocal8Bit().constData();
//              QStringList val_Boite_vit = tmp_Boite_vit.split(QLatin1Char(':'));
//              QString labelB = val_Boite_vit.at(1);
//              ui->labelBoite->setText(labelB);
     }



}








void MainWindow::envoyerCommande(){
    QByteArray data;
    //data = ui->lineEdit->text().toLocal8Bit();
    serial->write(data);
    qDebug() << "Envoi effectuer";
}

QString MainWindow::recupvaleur(QString val)
{


    int nbcar = val.count();

    QString test[nbcar];

    for (int var = 0; var < nbcar; ++var) {
        test[var] = val.operator [](var);
    }

    QString mot;


    for (int i = 0; i < nbcar ; ++i)
    {
       //qDebug() << test[i];

       if (test[i]==":")
       {

           for (int var = i; var < (nbcar-1); ++var)
           {
               mot = mot + test[var+1];
           }


       }

    }

    return mot;
}

QString MainWindow::valFinal(QStringList x){

    QString val_List;
    QString val_F;
    for (int i = 0; i < x.size(); ++i){

                 val_List = x.at(0).toLocal8Bit().constData() ;
                 val_F =  recupvaleur(val_List);
     }

return val_F;
}



