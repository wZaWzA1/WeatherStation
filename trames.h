#ifndef TRAMES_H
#define TRAMES_H
#include <QString>

typedef struct GGA {
    float utcTime;
    double latitude;
    QString directionLatitude;
    double longitude;
    QString directionLongitude;
    int gpsQualityIndicator;
    int numberOfSatellites;
    float horizontalDilution;
    QString altitudeUnits;
    double geoidalSeparation;
    QString geoidalSeparationUnits;
    double ageOfDifferentialData;
    QString differentialReferenceStationId;
    QString checksum;

}GGA;

typedef struct MWV
{
    float angle;
    QChar ref;
    float speed;
    QChar unit;
    QChar valid;
}MWV;

typedef struct ROT
{
    float rate;
    QChar status;
}ROT;

typedef struct GLL {
    double   latitude;
    QString  directionLatitude;
    double   longitude;
    QString  directionLongitude;
    int      time;
    QString  checksum;
}GGL;

typedef struct VTG {
    QString degree;
    QString magnetique;
    QString noeuds;
    QString kilometres;
}VTG;

typedef struct XDRA
{
    float relativeWindChillTemp;
    float theoreticalWindChillTemp;
    float heatIndex;
    float stationPressure;
}XDR;

typedef struct XDRB
{
    float pitch;
    float roll;
}XDRB;

typedef struct HDG
{
    float orientation;
    float magneticDeviation;
    QChar direction;
    float magneticDeviation2;
    QChar direction2;
}HDG;

typedef struct MDA
{
    float pressure;
    float pressureBar;
    float airtemperature;
    float humidity;
    float dewpoint;
    float winddirection;
    float winddirectionm;
    float windspeed;
    float windspeedm;
}MDA;

namespace Trames
{
GGA parseGGA(QString data);

GGL parseGGL(QString data);

VTG parseVTG(QString data);

XDRA parseXDR(QString data);

XDRB parseXDRB(QString data);

MDA parseMDA(QString data);

MWV parseMWV(QString data);

ROT parseROT(QString data);

HDG parseHDG(QString data);
}


namespace Utils
{
QString formatTime(float time);
QString formatDirection(double direction, QString directionCap);

}

#endif
