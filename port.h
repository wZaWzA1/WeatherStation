#ifndef PORT_H
#define PORT_H
// Permet d'éviter les erreurs liés à l'inclusions multiple dans le même programme.

#include "QtSerialPort/qserialport.h"
#include "qmainwindow.h"
#include <Windows.h>

// Permet d'inclure les bibliothèques dans ma classe.

class Port : public QMainWindow // Création de la classe Port elle hérite de la classe QMainWindow
{
    Q_OBJECT
public:
    // Constructeur -> Lorsque l'instance de la classe est crée, c'est ce code qui va s'executer.
    Port();

    // Méthodes
    bool Setup(); // Fonction qui retourne un boolean (vrai ou faux) avec comme nom Setup
    void Close(); // Fonction qui retourne rien avec comme nom Close

    // Destructeur -> Lorsque l'instance va être détruite, c'est ce code qui va s'executer
    ~Port();
    QString port; // Variable string (chaine de charactères) port
    int     baudrate; // Variable qui a pour type un int et qui possède comme nom "baudrate"
signals:
    void dataReceived(const QString& data); // signale

private slots:
    void readyRead(); // Slots
private:
    QSerialPort serial; // Variable accessible uniquement dans la classe, il ne peut pas être modifié en dehors
};

#endif // PORT_H
