#include "trames.h"
#include "qdebug.h"
#include "qregularexpression.h"
#include <QList>
GGA Trames::parseGGA(QString data)
{
    GGA final;

    QStringList parts = data.split(",");



    if(parts.size() >= 15)
    {
        final.utcTime = parts[1].toFloat();

        final.latitude = parts[2].toFloat();
        final.directionLatitude = parts[3];

        final.longitude = parts[4].toFloat();
        final.directionLongitude = parts[5];

        final.gpsQualityIndicator = parts[6].toInt();
        final.numberOfSatellites = parts[7].toInt();

        final.horizontalDilution = parts[8].toDouble();
        if(parts[9] != "")
        {
            final.altitudeUnits = parts[9] + parts[10];
        } else {
            final.altitudeUnits = "0";
        }
    }

    static QRegularExpression re("\\*([0-9]+)");
    QRegularExpressionMatch match = re.match(data);

    if(match.hasMatch())
    {
        final.checksum = match.captured(0);
    } else {
        final.checksum = "Cannot get the checksum";
    }



    return final;
}

GGL Trames::parseGGL(QString data)
{
    GGL final;

    QStringList parts = data.split(",");

    if(parts.size() >= 7)
    {
        final.latitude = parts[1].toDouble();
        final.directionLatitude = parts[2];

        final.longitude = parts[3].toDouble();
        final.directionLongitude = parts[4];

        final.time = parts[5].toInt();
        final.checksum = parts[6];
    }

    return final;

}
VTG Trames::parseVTG(QString data)
{
    VTG final;

    QStringList parts = data.split(",");

    if(parts.size() >= 8)
    {
        if(parts[1] != "")
        {
            final.degree = parts[1] + parts[2];
        } else {
            final.degree = "0";
        }
        if(parts[3] != "")
        {
            final.magnetique = parts[3] + parts[4];
        } else {
            final.magnetique = "0";
        }
        if(parts[5] != "")
        {
            final.noeuds = parts[5] + parts[6];
        } else {
            final.noeuds = "0";
        }
        if(parts[7] != "")
        {
            final.kilometres = parts[7] + parts[8];
        } else {
            final.kilometres = "0";
        }


    } else {
        final.degree = 0;
        final.magnetique = "0";
        final.noeuds = "0";
        final.kilometres = "0";
    }
    return final;
}

XDRA Trames::parseXDR(QString data)
{
    XDRA final;

    QStringList parts = data.split(",");

    if(parts[2] != "")
    {
        final.relativeWindChillTemp = parts[2].toFloat();
    } else {
        final.relativeWindChillTemp = 0;
    }

    if(parts[6] != "")
    {
        final.theoreticalWindChillTemp = parts[6].toFloat();
    } else {
        final.theoreticalWindChillTemp = 0;
    }

    if(parts[10] != "")
    {
        final.heatIndex = parts[10].toFloat();
    } else {
        final.heatIndex = 0;
    }

    if(parts[14] != "")
    {
        final.stationPressure = parts[14].toFloat();
    } else {
        final.stationPressure = 0;
    }

    return final;

}

HDG Trames::parseHDG(QString data)
{
    HDG final;
    QStringList parts = data.split(",");

    if(parts[1] != "")
    {
        final.orientation = parts[1].toFloat();
    } else {
        final.orientation = 0;
    }
    if(parts[2] != "")
    {
        final.magneticDeviation = parts[2].toFloat();
    } else {
        final.magneticDeviation = 0;
    }

    if(parts[3] != "")
    {
        final.direction = parts[3].at(parts[3].size() - 1);
    } else {
        final.direction = 'I';
    }
    if(parts[4] != "")
    {
        final.magneticDeviation2 = parts[4].toFloat();
    } else {
        final.magneticDeviation2 = 0;
    }

    if(parts[5] != "")
    {
        final.direction2 = parts[5].at(parts[5].size() - 1);
    } else {
        final.direction2 = 'I';
    }
    return final;
}


XDRB Trames::parseXDRB(QString data)
{
    XDRB final;

    QStringList parts = data.split(",");

    if(parts[2] != "")
    {
        final.pitch = parts[2].toFloat();
    } else {
        final.roll = 0;
    }

    if(parts[6] != "")
    {
        final.roll = parts[6].toFloat();
    } else {
        final.roll = 0;
    }

    return final;
}

MDA Trames::parseMDA(QString data)
{
    MDA final;

    QStringList parts = data.split(",");

    if(parts[1] != "")
    {
        final.pressure = parts[1].toFloat();
    } else {
        final.pressure = 0;
    }

    if(parts[3] != "")
    {
        final.pressureBar = parts[3].toFloat();
    } else {
        final.pressureBar = 0;
    }

    if(parts[5] != "")
    {
        final.airtemperature = parts[5].toFloat();
    } else {
        final.airtemperature = 0;
    }

    if(parts[9] != "")
    {
        final.humidity = parts[9].toFloat();
    } else {
        final.humidity = 0;
    }

    if(parts[11] != "")
    {
        final.dewpoint = parts[11].toFloat();
    } else {
        final.dewpoint = 0;
    }

    if(parts[13] != "")
    {
        final.winddirection = parts[13].toFloat();
    } else {
        final.winddirection = 0;
    }

    if(parts[15] != "")
    {
        final.winddirectionm = parts[15].toFloat();
    } else {
        final.winddirectionm = 0;
    }

    if(parts[17] != "")
    {
        final.windspeed = parts[17].toFloat();
    } else {
        final.windspeed = 0;
    }
    if(parts[19] != "")
    {
        final.windspeedm = parts[19].toFloat();
    } else {
        final.windspeedm = 0;
    }

    return final;
}


MWV Trames::parseMWV(QString data)
{
    MWV final;
    QStringList parts = data.split(",");

    final.angle = parts[1].toFloat();
    final.ref = parts[2].at(parts[2].size() - 1);
    final.speed = parts[3].toFloat();
    final.unit = parts[4].at(parts[4].size() - 1);
    QStringList partLast = parts[5].split("*");
    final.valid = partLast[0].at(partLast[0].size() - 1);
    return final;
}

ROT Trames::parseROT(QString data)
{
    ROT final;
    QStringList part = data.split(",");
    QStringList partFinal = part[2].split("*");
    if(part[1] != "")
    {
        final.rate = part[1].toFloat();
    } else {
        final.rate = 0.0;
    }
    final.status = partFinal[0].at(partFinal[0].size() - 1);


    return final;
}
QString Utils::formatDirection(double direction, QString directionCap) {
    int degrees = static_cast<int>(direction / 100);
    double minutes = direction - (degrees * 100);
    return QString(QString::number(degrees) + "° " + QString::number(minutes, 'f', 3) + "' " + directionCap);
}



QString Utils::formatTime(float time)
{
    try {
        QString timeFormated = QString::number(time, 'f', 3);

        int hours = std::stoi(timeFormated.toStdString().substr(0,2));
        int minutes = std::stoi(timeFormated.toStdString().substr(2,2));
        int seconds = std::stoi(timeFormated.toStdString().substr(4,2));
        int ms = std::stod(timeFormated.toStdString().substr(7));
        return QString(QString::number(hours)+"h "+QString::number(minutes)+"m "+QString::number(seconds)+"s " + QString::number(ms)+"ms");
    }catch(std::out_of_range const&) {
        return QString("Cannot parse the time");
    }
}

