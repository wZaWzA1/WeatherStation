
#include "port.h"
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QCoreApplication>
// Inclure les bibliothèques

// Constructeur, ne fait rien.
Port::Port()
{

}

// Permet une fois appeler de fermer le port communiquant.
void Port::Close()
{
    if (serial.isOpen())
    {
        serial.clear();
        serial.close();
    }
}
// Méthode qui a pour objectif de mettre en place notre port de communication.
bool Port::Setup()
{
    // Elle met d'abord le nom du port
    serial.setPortName(this->port);
    // Ferme la connexion si il y'a une connexion déjà ouverte
    serial.close();
    // Instancie une messagebox
    QMessageBox box;
    // Si il arrive pas à ouvrir le port com, il met une erreur.
    if(!serial.open(QIODevice::ReadWrite))
    {

        #ifdef QT_DEBUG
            qDebug() << serial.errorString();
        #endif

        box.critical(0, "Error", "Cannot open the device " + this->port);
        this->Close();
        return false;
    }
    // Si il arrive pas a mettre le baudrate il met une erreur.
    if(!serial.setBaudRate(this->baudrate))
    {
        #ifdef QT_DEBUG
            qDebug() << serial.errorString();
        #endif

        box.critical(0, "Error", "Cannot set the baudrate as" + QString::number(this->baudrate));
        this->Close();
        return false;
    }

    // Autres conditions

    if(!serial.setDataBits(QSerialPort::Data8))
    {
        #ifdef QT_DEBUG
            qDebug() << serial.errorString();
        #endif
            box.critical(0, "Error", "Cannot set the DataBit");
            this->Close();
        return false;
    }

    if(!serial.setParity(QSerialPort::NoParity))
    {
        #ifdef QT_DEBUG
            qDebug() << serial.errorString();
        #endif
            box.critical(0, "Error", "Cannot set the parity as none");
            this->Close();
        return false;
    }

    if(!serial.setStopBits(QSerialPort::OneStop))
    {
        #ifdef QT_DEBUG
            qDebug() << serial.errorString();
        #endif
            box.critical(0, "Error", "Cannot set the stop bits");
            this->Close();
        return false;
    }

    if(!serial.setFlowControl(QSerialPort::NoFlowControl))
    {
        #ifdef QT_DEBUG
            qDebug() << serial.errorString();
        #endif
            box.critical(0, "Error", "Cannot set the flow control");
            this->Close();
        return false;
    }
    // Permet de mettre un slots.
    connect(&serial, SIGNAL(readyRead()), this, SLOT(readyRead()));
    // Retourne vrai, car la function  est un boolean, on pourra ensuite géré si il retourne false.
    return true;
}



void Port::readyRead()
{
    if(serial.canReadLine())
    {
        QByteArray data = serial.readLine();
        if(data.isValidUtf8())
        {
            data = data.trimmed();
            emit dataReceived(QString(data));
        }
    }
}

Port::~Port()
{
    disconnect(&serial, SIGNAL(readyRead()), this, SLOT(readyRead()));
    serial.close();
}
