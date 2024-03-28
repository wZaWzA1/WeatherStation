#include "graphique.h"
#include "ui_graphique.h"
#include <QDateTime>
#include <QRegularExpression>
#include <QVector>
#include "trames.h"
#include "qcustomplot.h"

graphique::graphique(QWidget *parent, Port* mainPort, Settings* parametres): QDialog(parent), ui(new Ui::graphique)
{

    port = mainPort;
    param = parametres;
    mda = new MDA;
    gga = new GGA;
    hdg = new HDG;
    mwv = new MWV;

    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());

    QVBoxLayout * layout = new QVBoxLayout(this);

    QCheckBox *Temperature = new QCheckBox("Température");
    QCheckBox *Pression = new QCheckBox("Pression");
    QCheckBox *Vent = new QCheckBox("Vent");
    QCheckBox *Angle = new QCheckBox("Angle Vent");
    QCheckBox *GPS = new QCheckBox("GPS");
    QCheckBox *Direction = new QCheckBox("Direction");

    layout->addWidget(Temperature);
    layout->addWidget(Pression);
    layout->addWidget(Vent);
    layout->addWidget(Angle);
    layout->addWidget(Direction);
    layout->addWidget(GPS);


    ui->ScrollContent->setLayout(layout);

    // Slots
    connect(Temperature, &QCheckBox::clicked, this, &graphique::onTemperatureCheckboxClicked);
    connect(Pression, &QCheckBox::clicked, this, &graphique::onPressureCheckboxClicked);
    connect(Vent, &QCheckBox::clicked, this, &graphique::onVentCheckboxClicked);
    connect(Angle, &QCheckBox::clicked, this, &graphique::onAngleCheckboxClicked);
    connect(GPS, &QCheckBox::clicked, this, &graphique::onGPSCheckboxClicked);
    connect(Direction, &QCheckBox::clicked, this, &graphique::onDirectionCheckboxClicked);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this,&graphique::updateGraph);
    timer->start(1000);
}

void graphique::Graphique(QString data)
{
    static QRegularExpression re("^\\$([A-Za-z]{2})([A-Za-z]{3})");
    QRegularExpressionMatch match = re.match(data);

    if(match.hasMatch())
    {
        if(match.captured(2) == "MDA")
        {
            *mda = Trames::parseMDA(data);
        }

        if(match.captured(2) == "GGA")
        {
            *gga = Trames::parseGGA(data);
        }
        if(match.captured(2) == "HDG")
        {
            *hdg = Trames::parseHDG(data);
        }
        if(match.captured(2) == "MVW")
        {
            QStringList parts = data.split(",");
            QStringList partLast = parts[5].split('*');

            if(partLast[0] != 'V')
            {
                *mwv = Trames::parseMWV(data);
            }
        }
    }
}

void graphique::updateGraph()
{
    static int currentTime = 0;
    currentTime += 1;

    temps.push_back(currentTime);

    if(mda != nullptr && ui->Pression->isVisible())
    {
        ui->Pression->clearGraphs();
        ui->Pression->addGraph();

        if(param->pression == "Inches")
        {
           pressions.push_back(mda->pressure);
        } else if(param->pression == "Bar") {
            pressions.push_back(mda->pressureBar);
        } else if(param->pression == "Millibar")
        {
            pressions.push_back(mda->pressureBar*1000);
        }

        ui->Pression->graph(0)->setData(temps, pressions);
        ui->Pression->xAxis->setLabel("Temps (secondes)");
        ui->Pression->yAxis->setLabel("Pression (" + param->pression + ")");
        ui->Pression->rescaleAxes();
        ui->Pression->replot();
    }

    if(mda != nullptr && ui->Temperature->isVisible())
    {
        ui->Temperature->clearGraphs();
        ui->Temperature->addGraph();
        if(param->temperature == "Celsius")
        {
            temperature.push_back(mda->airtemperature);
        } else if(param->temperature == "Fahrenheit")
        {
            temperature.push_back((mda->airtemperature*1.8) + 32);
        }

        ui->Temperature->graph(0)->setData(temps, temperature);
        ui->Temperature->xAxis->setLabel("Temps (secondes)");
        ui->Temperature->yAxis->setLabel("Temperature (" + param->temperature + ")");
        ui->Temperature->rescaleAxes();
        ui->Temperature->replot();
    }
    if(mwv != nullptr && ui->Vent->isVisible())
    {
        ui->Vent->clearGraphs();
        ui->Vent->addGraph();

        if(param->vitesse == "noeuds")
        {
            vent.push_back(mwv->speed);
        } else if(param->vitesse == "km/h")
        {
            vent.push_back(mwv->speed*1.852);
        } else if(param->vitesse == "m/s")
        {
            vent.push_back(mwv->speed/1.944);
        }

        ui->Vent->graph(0)->setData(temps, vent);
        ui->Vent->xAxis->setLabel("Temps (secondes)");
        ui->Vent->yAxis->setLabel("Vitesse (" + param->vitesse + ")");
        ui->Vent->rescaleAxes();
        ui->Vent->replot();
    }

    if(mwv != nullptr && ui->Angle->isVisible())
    {
        ui->Angle->clearGraphs();
        ui->Angle->addGraph();

        angle.push_back(mwv->angle);

        ui->Angle->graph(0)->setData(temps, angle);
        ui->Angle->xAxis->setLabel("Temps (secondes)");
        ui->Angle->yAxis->setLabel("Orientation du Vent");
        ui->Angle->rescaleAxes();
        ui->Angle->replot();
    }

    if(hdg != nullptr && ui->Direction->isVisible())
    {
        ui->Direction->clearGraphs();
        ui->Direction->addGraph();
        direction.push_back(hdg->orientation);

        ui->Direction->graph(0)->setData(temps, direction);
        ui->Direction->xAxis->setLabel("Temps (secondes)");
        ui->Direction->yAxis->setLabel("Orientation du port");
        ui->Direction->rescaleAxes();
        ui->Direction->replot();
    }

    if(gga != nullptr && ui->GPS->isVisible())
    {
        ui->GPS->clearGraphs();
        ui->GPS->addGraph();

        gps.push_back(gga->numberOfSatellites);

        ui->GPS->graph(0)->setData(temps, gps);
        ui->GPS->xAxis->setLabel("Temps (secondes)");
        ui->GPS->yAxis->setLabel("Nb. GPS");

        ui->GPS->rescaleAxes();
        ui->GPS->replot();
    }
}

void graphique::onTemperatureCheckboxClicked(bool checked)
{
    ui->Temperature->setVisible(checked);
    ui->TemperatureLabel->setVisible(checked);
    ui->TempButton->setVisible(checked);

}
void graphique::onPressureCheckboxClicked(bool checked)
{
    ui->Pression->setVisible(checked);
    ui->PressionLabel->setVisible(checked);
    ui->PressionButton->setVisible(checked);

}
void graphique::onVentCheckboxClicked(bool checked)
{
    ui->Vent->setVisible(checked);
    ui->VentLabel->setVisible(checked);
    ui->VentButton->setVisible(checked);
}

void graphique::onAngleCheckboxClicked(bool checked)
{
    ui->Angle->setVisible(checked);
    ui->AngleLabel->setVisible(checked);
    ui->AngleButton->setVisible(checked);
}

void graphique::onGPSCheckboxClicked(bool checked)
{
    ui->GPS->setVisible(checked);
    ui->GPSLabel->setVisible(checked);
    ui->GPSButton->setVisible(checked);
}

void graphique::onDirectionCheckboxClicked(bool checked)
{
    ui->Direction->setVisible(checked);
    ui->DirectionLabel->setVisible(checked);
    ui->DirectionButton->setVisible(checked);
}

void graphique::showEvent(QShowEvent *env)
{
    QDialog::showEvent(env);

    ui->AngleLabel->setVisible(false);
    ui->DirectionLabel->setVisible(false);
    ui->GPSLabel->setVisible(false);
    ui->PressionLabel->setVisible(false);
    ui->TemperatureLabel->setVisible(false);
    ui->VentLabel->setVisible(false);


    ui->Direction->setVisible(false);
    ui->GPS->setVisible(false);
    ui->Angle->setVisible(false);
    ui->Vent->setVisible(false);
    ui->Pression->setVisible(false);
    ui->Temperature->setVisible(false);

    ui->AngleButton->setVisible(false);
    ui->DirectionButton->setVisible(false);
    ui->GPSButton->setVisible(false);
    ui->PressionButton->setVisible(false);
    ui->TempButton->setVisible(false);
    ui->VentButton->setVisible(false);

    connect(port, &Port::dataReceived, this, &graphique::Graphique);
}

void graphique::closeEvent(QCloseEvent *env)
{
    QDialog::closeEvent(env);
    disconnect(port, &Port::dataReceived, this, &graphique::Graphique);
}

graphique::~graphique()
{
    delete ui;
}

void graphique::saveFile(QCustomPlot *plot)
{
    QString filters("PNG (*.png);;JPG (*.jpg);;PDF (*.pdf);; BMP (*.bmp)");
    QString defaultFilter("PNG (*.png)");
    QString path = QFileDialog::getSaveFileName(this, "Export Graph", QStandardPaths::writableLocation(QStandardPaths::PicturesLocation), filters, &defaultFilter);

    if(path.isEmpty())
        return;

    if(path.endsWith(".png"))
    {
        plot->savePng(path, plot->width(), plot->height());
    }

    if(path.endsWith(".jpg"))
    {
        plot->saveJpg(path,plot->width(), plot->height());
    }

    if(path.endsWith(".pdf"))
    {
        plot->savePdf(path, plot->width(), plot->height());
    }
    if(path.endsWith(".bmp"))
    {
        plot->saveBmp(path, plot->width(), plot->height());
    }

    MessageBoxW(NULL, L"L'image a été sauvegarder !", L"Erreur", MB_OK | MB_ICONINFORMATION);
}

void graphique::on_TempButton_clicked()
{
    saveFile(ui->Temperature);
}

void graphique::on_PressionButton_clicked()
{
    saveFile(ui->Pression);
}

void graphique::on_VentButton_clicked()
{
    saveFile(ui->Vent);
}

void graphique::on_AngleButton_clicked()
{
    saveFile(ui->Angle);
}

void graphique::on_DirectionButton_clicked()
{
    saveFile(ui->Direction);
}


void graphique::on_GPSButton_clicked()
{
    saveFile(ui->GPS);
}

