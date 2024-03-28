#ifndef CONSOLE_H
#define CONSOLE_H

#include "port.h"
#include <QDialog>

namespace Ui {
class console;
}

class console : public QDialog
{
    Q_OBJECT

public:
    explicit console(QWidget *parent = nullptr, Port* com= nullptr);
    ~console();
protected:
    void showEvent(QShowEvent *ev);
    void closeEvent(QCloseEvent *ev);

public slots:
    void Console(const QString& data);
private slots:
    void on_Export_clicked();

    void on_pushButton_clicked(bool checked);

    void on_Effacer_clicked();

private:
    Ui::console *ui;
    Port* port;
};

#endif // CONSOLE_H
