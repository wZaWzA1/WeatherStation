#include "mainwindow.h"
#include "graphique.h"
#include "port.h"
#include <QTimer>
#include "qregularexpression.h"
#include "ui_mainwindow.h"
#include "trames.h"
#include <QTime>
#include <QLabel>
#include <QSettings>
#include <QFile>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StateLabel = new QLabel(this);
    ui->statusbar->addPermanentWidget(StateLabel);

    startTimer(1000);

    checkTimer = new QTimer(this);



    trameRecue = false;

    if(QFile("settings.ini").exists())
    {

        QSettings settings("settings.ini", QSettings::IniFormat);
        QString savedPort = settings.value("Port").toString();
        if(!savedPort.isEmpty())
        {
            com.port = savedPort;
            com.baudrate = settings.value("Baudrate").toInt();
            if(!com.Setup())
            {
                StateLabel->setText("Déconnecté");
                ui->actionConsole->setEnabled(false);
                ui->actionGraphique->setEnabled(false);
                com.Close();
                return;
            }
            isFirstConnexion = false;
            param.temperature = settings.value("Temperature").toString();
            param.vitesse  = settings.value("Vitesse").toString();
            param.pression = settings.value("Unite").toString();
            StateLabel->setText("Connecté sur le port <span style='color: #32CBFF'>" + com.port + "</span> | Baudrate : <span style='color: #FF5154'>" + QString::number(com.baudrate) + "</span>");
            ui->actionConsole->setEnabled(true);
            ui->actionGraphique->setEnabled(true);
            ui->LabelError->setVisible(false);
        } else {
            StateLabel->setText("Déconnecté");
            ui->actionConsole->setEnabled(false);
            ui->actionGraphique->setEnabled(false);
            isFirstConnexion = true;
        }
    } else {
        StateLabel->setText("Déconnecté");
        isFirstConnexion = true;
        ui->actionConsole->setEnabled(false);
        ui->actionGraphique->setEnabled(false);
    }

    this->setFixedSize(this->width(), this->height());
    connect(&com, &Port::dataReceived, this, &MainWindow::Traitement);
    connect(checkTimer, &QTimer::timeout, this, &MainWindow::checkTrames);
}


void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);

    ui->LabelTemp->setVisible(false);
    ui->TempIco->setVisible(false);

    ui->Group1->setVisible(false);

    ui->Group2->setVisible(false);
    ui->Time->setVisible(false);
    ui->TimeIco->setVisible(false);

    ui->Invalide->setVisible(false);

    checkTimer->start(500);
}

double calculateWindChill(double temperature, double windSpeed) {
    return 13.12 + 0.6215 * temperature - 11.37 * std::pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
}



void MainWindow::Traitement(const QString& data)
{
    static QRegularExpression re("^\\$([A-Za-z]{2})([A-Za-z]{3})");
    QRegularExpressionMatch match = re.match(data);

    static MDA trames;
    static MWV trames2;
    static GGA trames3;
    static HDG trames4;

    static bool mdaReceived = false;
    static bool mwvReceived = false;

    trameRecue = true;
    if(match.hasMatch())
    {
        if(ui->Group1->isVisible() == false)
        {
            isFirstConnexion = false;
            ui->LabelError->setVisible(false);
            ui->Group1->setVisible(true);
            ui->Group2->setVisible(true);
            ui->LabelTemp->setVisible(true);
            ui->TempIco->setVisible(true);
            ui->Time->setVisible(true);
            ui->TimeIco->setVisible(true);

        }
        if(match.captured(2) == "MDA")
        {
            trames = Trames::parseMDA(data);
            mdaReceived = true;
            // Temperature
            if(param.temperature == "Celsius")
            {
                ui->LabelTemp->setText(QString::number(trames.airtemperature) + "°C");
            } else if(param.temperature == "Fahrenheit")
            {
                ui->LabelTemp->setText(QString::number((trames.airtemperature*1.8) + 32) + "°F");
            }

            // Pression
            if(param.pression == "Inches")
            {
               ui->Pression->setText(QString::number(trames.pressure, 'f', 1) + " Inches");
            } else if(param.pression == "Bar") {
                ui->Pression->setText(QString::number(trames.pressureBar, 'f', 1) + " Bar");
            } else if(param.pression == "Millibar")
            {
                ui->Pression->setText(QString::number(trames.pressureBar*1000, 'f', 1) +" mbars");
            }

        }
        if(match.captured(2) == "MWV")
        {
            QStringList parts = data.split(",");
            QStringList partLast = parts[5].split('*');
            if(partLast[0] != 'V')
            {
                trames2 = Trames::parseMWV(data);
                mwvReceived = true;

                if(param.vitesse == "noeuds")
                {
                    ui->Vent->setText(QString::number(trames2.speed, 'f', 0) + " noeuds");
                } else if(param.vitesse == "km/h") {
                    ui->Vent->setText(QString::number(trames2.speed*1.852, 'f', 1) + " km/h");
                } else if(param.vitesse == "m/s") {
                    ui->Vent->setText(QString::number(trames2.speed/1.944, 'f', 1) + " m/s");
                }
                ui->Rapporter->setText(QString::number(trames2.angle) + "°");

            }
        }
        if(match.captured(2) == "GGA")
        {
            trames3 = Trames::parseGGA(data);
            ui->GPS->setText(QString::number(trames3.numberOfSatellites));
        }
        if(match.captured(2) == "HDG")
        {
            trames4 = Trames::parseHDG(data);
            ui->Direction->setText(QString::number(trames4.orientation) + "°");
        }
    }

    if(mdaReceived == true && mwvReceived == true)
    {
        double windChill = calculateWindChill(trames.airtemperature, trames2.speed * 1.852);
        ui->Refroidissement->setText(QString::number(windChill, 'f', 1) + "°C");
        mdaReceived = false;
        mwvReceived = false;
    }


}


void MainWindow::checkTrames()
{
    if(trameRecue == false && isFirstConnexion == false)
    {
        ui->actionConsole->setEnabled(false);
        ui->actionGraphique->setEnabled(false);
        ui->LabelTemp->setVisible(false);
        ui->TempIco->setVisible(false);

        ui->Group1->setVisible(false);
        ui->Group2->setVisible(false);

        ui->Time->setVisible(false);
        ui->TimeIco->setVisible(false);

        ui->LabelError->setVisible(true);
        ui->Invalide->setVisible(true);

        ui->Invalide->setText("Le port " + com.port + " ne reçoit plus de données/ou est invalide.");
        StateLabel->setText("Déconnecté");
    } else if(trameRecue == true && isFirstConnexion == false) {
        ui->Invalide->setVisible(false);
        ui->actionConsole->setEnabled(true);
        ui->actionGraphique->setEnabled(true);
        StateLabel->setText("Connecté sur le port <span style='color: #32CBFF'>" + com.port + "</span> | Baudrate : <span style='color: #FF5154'>" + QString::number(com.baudrate) + "</span>");
    } else if(trameRecue == false && isFirstConnexion == true)
    {
        ui->Invalide->setVisible(false);
        ui->actionConsole->setEnabled(false);
        ui->actionGraphique->setEnabled(false);
    }

    trameRecue = false;
}




void MainWindow::on_actionOptions_triggered()
{
    Option = new option(this, &com, &param);
    Option->setAttribute(Qt::WA_DeleteOnClose);
    Option->exec();

    QSettings settings("settings.ini", QSettings::IniFormat);
    if(com.port != "")
    {
        StateLabel->setText("Connecté sur le port <span style='color: #32CBFF'> " + com.port + "</span> | Baudrate : <span style='color: #FF5154'>" + QString::number(com.baudrate) + "</span>");
        ui->actionConsole->setEnabled(true);
        ui->actionGraphique->setEnabled(true);
        isFirstConnexion = false;
        ui->LabelError->setVisible(false);

    } else {
        ui->actionConsole->setEnabled(false);
        ui->actionGraphique->setEnabled(false);
        StateLabel->setText("Déconnecté");
    }



    if(param.pression.isEmpty())
    {
        param.pression = settings.value("Unite").toString();
    }
    if(param.vitesse.isEmpty())
    {
        param.pression = settings.value("Vitesse").toString();
    }

    if(param.temperature.isEmpty())
    {
        param.temperature = settings.value("Temperature").toString();
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    ui->Time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionConsole_triggered()
{
    Console = new console(this, &com);
    Console->setAttribute(Qt::WA_DeleteOnClose);
    Console->show();

}




void MainWindow::on_actionA_propos_triggered()
{
    About = new about(this);
    About->setAttribute(Qt::WA_DeleteOnClose);
    About->show();
}


void MainWindow::on_actionGraphique_triggered()
{
    Graphique = new graphique(this, &com, &param);
    Graphique->setAttribute(Qt::WA_DeleteOnClose);
    Graphique->show();
}
