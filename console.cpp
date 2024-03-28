#include "console.h"
#include "port.h"
#include "ui_console.h"
#include <QFile>
#include <QStandardPaths>
#include <QFileDialog>
#include <Windows.h>
console::console(QWidget *parent, Port *com): QDialog(parent), ui(new Ui::console)
{
    ui->setupUi(this);
    port = com;

    QFlags flags = windowFlags();
    setWindowFlags(flags | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
}

void console::showEvent(QShowEvent *ev)
{
    QDialog::showEvent(ev);
    connect(port, &Port::dataReceived, this, &console::Console);
}

void console::closeEvent(QCloseEvent *ev)
{
    QDialog::closeEvent(ev);
    disconnect(port, &Port::dataReceived, this, &console::Console);
}

void console::Console(const QString& data)
{
    if(ui->pushButton->isChecked())
        return;

    ui->Console->appendPlainText(data);

    if(ui->Autoscroll->isChecked())
    {
        ui->Console->moveCursor(QTextCursor::End);
        ui->Console->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->Console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    } else {
        ui->Console->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ui->Console->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    }
}
console::~console()
{
    delete ui;
}

void console::on_Export_clicked()
{
    QString filters("Log files (*.log)");
    QString defaultFilter("Log files (*.log)");
    QString path = QFileDialog::getSaveFileName(this, "Export console", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), filters, &defaultFilter);

    if(path.isEmpty())
        return;

    QFile file(path);

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    out << ui->Console->toPlainText();
    file.close();

    if(out.status() != QTextStream::Ok)
    {
        MessageBoxW(NULL, L"Le text n'a pas été sauvegarder, suite à une erreur", L"Erreur", MB_ICONERROR | MB_OK);
    } else {
        MessageBoxW(NULL, L"Le text à bien été sauvegarder!", L"Sauvegarder", MB_OK | MB_ICONINFORMATION);
    }


}


void console::on_pushButton_clicked(bool checked)
{

    if(checked == false)
    {
        ui->pushButton->setText("Pause");
        ui->pushButton->setStyleSheet("");
    }
    if(checked == true)
    {
        ui->pushButton->setText("Continuer");
        ui->pushButton->setStyleSheet("background-color: red;");
    }
}


void console::on_Effacer_clicked()
{
    ui->Console->clear();
}

