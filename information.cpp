#include "information.h"
#include "port.h"
#include <QDebug>
#include "qregularexpression.h"
#include "ui_information.h"
#include "trames.h"
information::information(QWidget *parent, Port *mainPort) : QDialog(parent), ui(new Ui::information)
{
    ui->setupUi(this);
    port = mainPort;
}


unsigned constexpr str2int(char const *input) {return *input ?static_cast<unsigned int>(*input) + 33 * str2int(input + 1) :5381;}


void information::data(const QString& data)
{
    static QRegularExpression re("^\\$([A-Za-z]{2})([A-Za-z]{3})");
    QRegularExpressionMatch match = re.match(data);

    if(match.hasMatch())
    {
        XDRA trame;
        XDRB trame2;
        MDA trame3;
        MWV trame4;
        ROT trame5;

        QStringList list;
        switch(str2int(match.captured(2).toStdString().c_str()))
        {
        case str2int("XDR"):
            list = data.split(",");
            if(list.size() >= 17)
            {
                trame = Trames::parseXDR(data);

                ui->XDRTemp->setText("Température: " + QString::number(trame.relativeWindChillTemp));
                ui->XDRTempT->setText("Température théorique: " + QString::number(trame.theoreticalWindChillTemp));
                ui->XDRIndex->setText("Index: " + QString::number(trame.heatIndex));

                ui->XDRPression->setText("Pression: " + QString::number(trame.stationPressure) + " BAR");
            }

            if(list.size() <= 9)
            {
                trame2 = Trames::parseXDRB(data);
                ui->XDRPitch->setText("Hauteur : " + QString::number(trame2.pitch));
                ui->XDRPRoll->setText("Profondeur : " + QString::number(trame2.roll));
            }
            break;
        case str2int("MDA"):
            trame3 = Trames::parseMDA(data);
            ui->WIMDAPression->setText("Pression (Inches) : " + QString::number(trame3.pressure));
            ui->WIMDAPressionB->setText("Pression (bars) : " + QString::number(trame3.pressureBar));
            ui->WIMDATemperature->setText("Température exterieur : " + QString::number(trame3.airtemperature) + "° Celcus");
            ui->WIMDAHumide->setText("Humidité relatif : " + QString::number(trame3.humidity));
            ui->WIMDAPDR->setText("Point de rosée : " + QString::number(trame3.dewpoint));
            ui->WIMDAVent->setText("Direction du vent : " + QString::number(trame3.winddirection));
            ui->WIMDADirection->setText("Direction du vent magnétique : " + QString::number(trame3.winddirectionm));
            ui->WIMDAVitesse->setText("Vitesse du vent : " + QString::number(trame3.windspeed));
            ui->WIMDAVitesseVENT->setText("Vitesse du vent m/s : " + QString::number(trame3.winddirectionm));
            break;

        case str2int("MWV"):
        {
            QStringList parts = data.split(",");
            QStringList partLast = parts[5].split("*");
            if(partLast[0] != 'V')
            {
                trame4 = Trames::parseMWV(data);
                ui->MWVWind->setText("Angle du vent : " + QString::number(trame4.angle));
                ui->MWVReference->setText("Reference : " + QString(trame4.ref));

                if(ui->comboBox->currentText() == "noeuds")
                {
                   ui->MWVSpeed->setText("Vitesse du vent : " + QString::number(trame4.speed) + " noeuds"); // Noeuds
                }

                if(ui->comboBox->currentText() == "km/h")
                {
                    ui->MWVSpeed->setText("Vitesse du vent : " + QString::number(trame4.speed*1.852) + " km/h");
                    // Formule pour convertir en km heure = noeuds fois 1.852

                }

                if(ui->comboBox->currentText() == "m/s")
                {
                    ui->MWVSpeed->setText("Vitesse du vent : " + QString::number(trame4.speed/1.944) + " m/s");
                    // Formule pour convertir en m/s = noeuds divisé par 1.944
                }

                ui->MWVStatus->setText("Status : " + QString(trame4.valid));
            }
        }
            break;
        case str2int("ROT"):
            QStringList parts = data.split(",");
            QStringList partLast = parts[2].split("*");

            if(partLast[0] != 'V')
            {
                trame5 = Trames::parseROT(data);
                ui->ROTRate->setText("Rate : " + QString::number(trame5.rate));
                ui->ROTStatus->setText("Status : " + QString(trame5.status));
            }
            break;
        }
    }
}

void information::showEvent(QShowEvent *ev)
{
    QDialog::showEvent(ev);
    connect(port, &Port::dataReceived, this, &information::data);
}

void information::closeEvent(QCloseEvent *ev)
{
    QDialog::closeEvent(ev);
    disconnect(port, &Port::dataReceived, this, &information::data);
}

information::~information() {
    delete ui;
}
