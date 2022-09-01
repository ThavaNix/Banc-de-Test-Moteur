#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     QSerialPort *serial;

private slots:
    void messagesRecus();
    void envoyerCommande();
    QString recupvaleur(QString val);
    QString valFinal(QStringList x);
private:
     Ui::MainWindow *ui;
     QString donnee;
       QString ligne_info;
     QStringList  parts;

     QStringList Vitesse;
     QStringList Regime;
     QStringList Boite_vit;
     QStringList Temp_eau;
     QStringList Capt_eau;
     QStringList Capt_air;
     QStringList Capt_huile;
     QStringList Etat_moteur;

     QString vit1;

};
#endif // MAINWINDOW_H
