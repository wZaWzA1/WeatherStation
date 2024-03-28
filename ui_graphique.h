/********************************************************************************
** Form generated from reading UI file 'graphique.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIQUE_H
#define UI_GRAPHIQUE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graphique
{
public:
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *ScrollContent;
    QCustomPlot *Direction;
    QCustomPlot *GPS;
    QCustomPlot *Angle;
    QCustomPlot *Vent;
    QCustomPlot *Pression;
    QCustomPlot *Temperature;
    QLabel *TemperatureLabel;
    QLabel *PressionLabel;
    QLabel *VentLabel;
    QLabel *AngleLabel;
    QLabel *GPSLabel;
    QLabel *DirectionLabel;
    QPushButton *TempButton;
    QPushButton *PressionButton;
    QPushButton *VentButton;
    QPushButton *AngleButton;
    QPushButton *DirectionButton;
    QPushButton *GPSButton;

    void setupUi(QDialog *graphique)
    {
        if (graphique->objectName().isEmpty())
            graphique->setObjectName("graphique");
        graphique->resize(1126, 903);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rc/graphique.png"), QSize(), QIcon::Normal, QIcon::Off);
        graphique->setWindowIcon(icon);
        line = new QFrame(graphique);
        line->setObjectName("line");
        line->setGeometry(QRect(180, 0, 20, 901));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(graphique);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 9, 161, 251));
        scrollArea->setWidgetResizable(true);
        ScrollContent = new QWidget();
        ScrollContent->setObjectName("ScrollContent");
        ScrollContent->setGeometry(QRect(0, 0, 159, 249));
        scrollArea->setWidget(ScrollContent);
        Direction = new QCustomPlot(graphique);
        Direction->setObjectName("Direction");
        Direction->setGeometry(QRect(490, 340, 271, 261));
        GPS = new QCustomPlot(graphique);
        GPS->setObjectName("GPS");
        GPS->setGeometry(QRect(780, 340, 261, 261));
        Angle = new QCustomPlot(graphique);
        Angle->setObjectName("Angle");
        Angle->setGeometry(QRect(190, 340, 281, 261));
        Vent = new QCustomPlot(graphique);
        Vent->setObjectName("Vent");
        Vent->setGeometry(QRect(770, 10, 271, 271));
        Pression = new QCustomPlot(graphique);
        Pression->setObjectName("Pression");
        Pression->setGeometry(QRect(470, 10, 281, 271));
        Temperature = new QCustomPlot(graphique);
        Temperature->setObjectName("Temperature");
        Temperature->setGeometry(QRect(190, 10, 261, 271));
        TemperatureLabel = new QLabel(graphique);
        TemperatureLabel->setObjectName("TemperatureLabel");
        TemperatureLabel->setGeometry(QRect(230, 290, 91, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        TemperatureLabel->setFont(font);
        PressionLabel = new QLabel(graphique);
        PressionLabel->setObjectName("PressionLabel");
        PressionLabel->setGeometry(QRect(560, 290, 91, 21));
        PressionLabel->setFont(font);
        VentLabel = new QLabel(graphique);
        VentLabel->setObjectName("VentLabel");
        VentLabel->setGeometry(QRect(870, 290, 41, 16));
        VentLabel->setFont(font);
        AngleLabel = new QLabel(graphique);
        AngleLabel->setObjectName("AngleLabel");
        AngleLabel->setGeometry(QRect(260, 610, 101, 21));
        AngleLabel->setFont(font);
        GPSLabel = new QLabel(graphique);
        GPSLabel->setObjectName("GPSLabel");
        GPSLabel->setGeometry(QRect(830, 610, 111, 20));
        GPSLabel->setFont(font);
        DirectionLabel = new QLabel(graphique);
        DirectionLabel->setObjectName("DirectionLabel");
        DirectionLabel->setGeometry(QRect(550, 610, 91, 16));
        DirectionLabel->setFont(font);
        TempButton = new QPushButton(graphique);
        TempButton->setObjectName("TempButton");
        TempButton->setGeometry(QRect(370, 290, 81, 21));
        PressionButton = new QPushButton(graphique);
        PressionButton->setObjectName("PressionButton");
        PressionButton->setGeometry(QRect(670, 290, 81, 21));
        VentButton = new QPushButton(graphique);
        VentButton->setObjectName("VentButton");
        VentButton->setGeometry(QRect(960, 290, 81, 21));
        AngleButton = new QPushButton(graphique);
        AngleButton->setObjectName("AngleButton");
        AngleButton->setGeometry(QRect(390, 610, 81, 21));
        DirectionButton = new QPushButton(graphique);
        DirectionButton->setObjectName("DirectionButton");
        DirectionButton->setGeometry(QRect(680, 610, 81, 21));
        GPSButton = new QPushButton(graphique);
        GPSButton->setObjectName("GPSButton");
        GPSButton->setGeometry(QRect(960, 610, 81, 21));

        retranslateUi(graphique);

        QMetaObject::connectSlotsByName(graphique);
    } // setupUi

    void retranslateUi(QDialog *graphique)
    {
        graphique->setWindowTitle(QCoreApplication::translate("graphique", "Graphique", nullptr));
        TemperatureLabel->setText(QCoreApplication::translate("graphique", "Temperature", nullptr));
        PressionLabel->setText(QCoreApplication::translate("graphique", "Pression", nullptr));
        VentLabel->setText(QCoreApplication::translate("graphique", "Vent", nullptr));
        AngleLabel->setText(QCoreApplication::translate("graphique", "Angle du Vent", nullptr));
        GPSLabel->setText(QCoreApplication::translate("graphique", "GPS", nullptr));
        DirectionLabel->setText(QCoreApplication::translate("graphique", "Direction", nullptr));
        TempButton->setText(QCoreApplication::translate("graphique", "Export", nullptr));
        PressionButton->setText(QCoreApplication::translate("graphique", "Export", nullptr));
        VentButton->setText(QCoreApplication::translate("graphique", "Export", nullptr));
        AngleButton->setText(QCoreApplication::translate("graphique", "Export", nullptr));
        DirectionButton->setText(QCoreApplication::translate("graphique", "Export", nullptr));
        GPSButton->setText(QCoreApplication::translate("graphique", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphique: public Ui_graphique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIQUE_H
