#ifndef OPTION_H
#define OPTION_H

#include <QDialog>
#include "param.h"
#include "port.h"
namespace Ui {
class option;
}

class option : public QDialog
{
    Q_OBJECT

public:
    explicit option(QWidget *parent = nullptr, Port* mainPort = nullptr, Settings* parametres = nullptr);
    ~option();
protected:
    void showEvent(QShowEvent *ev);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::option *ui;
    Port* port;
    Settings* param;
    void Setup();
};

#endif // OPTION_H
