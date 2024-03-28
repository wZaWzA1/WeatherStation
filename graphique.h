#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QDialog>
#include "port.h"
#include "trames.h"
#include "param.h"
#include <QChart>
#include "qcustomplot.h"
#include <QBarSeries>
QT_BEGIN_NAMESPACE
namespace Ui { class graphique; }
QT_END_NAMESPACE

class graphique : public QDialog
{
    Q_OBJECT

public:
    graphique(QWidget *parent = nullptr, Port* mainPort = nullptr, Settings* parametres = nullptr);
    ~graphique();

protected:
    void showEvent(QShowEvent *env) override;
    void closeEvent(QCloseEvent *env) override;

private slots:
    void Graphique(QString data);
    void onTemperatureCheckboxClicked(bool checked);
    void onPressureCheckboxClicked(bool checked);
    void onVentCheckboxClicked(bool checked);
    void onAngleCheckboxClicked(bool checked);
    void onGPSCheckboxClicked(bool checked);
    void onDirectionCheckboxClicked(bool checked);
    void on_AngleButton_clicked();

    void on_TempButton_clicked();

    void on_PressionButton_clicked();

    void on_VentButton_clicked();

    void on_DirectionButton_clicked();
    void saveFile(QCustomPlot *plot);
    void on_GPSButton_clicked();

private:
    Ui::graphique *ui;
    Port* port;
    Settings* param;
    MDA* mda;
    MWV* mwv;
    GGA* gga;
    HDG* hdg;
    QTimer *timer;

    QVector<double> temps;

    QVector<double> pressions;
    QVector<double> temperature;
    QVector<double> vent;
    QVector<double> gps;
    QVector<double> direction;
    QVector<double> angle;
    void updateGraph();
};

#endif // GRAPHIQUE_H
