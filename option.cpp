#include "option.h"
#include "ui_option.h"
#include <QSettings>
#include <QFile>
#include <QSerialPortInfo>
option::option(QWidget *parent, Port* mainPort, Settings* mainParam) : QDialog(parent), ui(new Ui::option)
{
    ui->setupUi(this);
    port = mainPort;
    param = mainParam;

}

option::~option()
{
    delete ui;
}

void option::Setup()
{
    Q_FOREACH(const QSerialPortInfo port, QSerialPortInfo::availablePorts())
    {
        ui->COMBox->addItem(port.portName());
    }

    if(QFile("settings.ini").exists())
    {
        QSettings settings("settings.ini", QSettings::IniFormat);
        QString savedPort = settings.value("Port").toString();
        if(!savedPort.isEmpty())
        {
            int index = ui->COMBox->findText(savedPort);
            if(index != -1)
                ui->COMBox->setCurrentIndex(index);

            index = ui->COMBaud->findText(settings.value("Baudrate").toString());
            if(index != -1)
                ui->COMBaud->setCurrentIndex(index);

            index = ui->TemperatureCombo->findText(settings.value("Temperature").toString());
            if(index != -1)
                ui->TemperatureCombo->setCurrentIndex(index);

            index = ui->VitesseCombo->findText(settings.value("Vitesse").toString());
            if(index != -1)
                ui->VitesseCombo->setCurrentIndex(index);

            index = ui->PressionCombo->findText(settings.value("Unite").toString());
            if(index != -1)
                ui->PressionCombo->setCurrentIndex(index);

        }
    }
    else
    {
        QSettings settings("settings.ini", QSettings::IniFormat);
        settings.setValue("Port", "");
        settings.setValue("Baudrate", "");
        settings.setValue("Temperature", "");
        settings.setValue("Vitesse", "");
        settings.setValue("Unite", "");
    }

    this->setFixedSize(this->width(), this->height());
}

void option::showEvent(QShowEvent *ev)
{
    QDialog::showEvent(ev);
    Setup();
}





void option::on_pushButton_clicked()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setValue("Port", ui->COMBox->currentText());
    settings.setValue("Baudrate", ui->COMBaud->currentText().toInt());
    settings.setValue("Temperature", ui->TemperatureCombo->currentText());
    settings.setValue("Vitesse", ui->VitesseCombo->currentText());
    settings.setValue("Unite", ui->PressionCombo->currentText());

    port->port = ui->COMBox->currentText();
    port->baudrate = ui->COMBaud->currentText().toInt();

    param->temperature = ui->TemperatureCombo->currentText();
    param->vitesse = ui->VitesseCombo->currentText();
    param->pression = ui->PressionCombo->currentText();

    if(!port->Setup())
    {
        return;
    }
    option::close();
}


void option::on_pushButton_2_clicked()
{
    option::close();
}

