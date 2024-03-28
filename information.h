#ifndef INFORMATION_H
#define INFORMATION_H

#include "port.h"
#include "profile.h"
#include <QDialog>

namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr, Port *mainPort = nullptr); // Modification ici
    ~information();
protected:
    void showEvent(QShowEvent *ev);
    void closeEvent(QCloseEvent *ev);
public slots:
    void data(const QString& data);
private:
    Ui::information *ui;
    Port* port; // Ajout d'un pointeur vers le port principal
};

#endif // INFORMATION_H
