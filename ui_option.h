/********************************************************************************
** Form generated from reading UI file 'option.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_option
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *General;
    QGroupBox *COM;
    QGridLayout *gridLayout;
    QLabel *COMRate;
    QComboBox *COMBox;
    QComboBox *COMBaud;
    QLabel *COMLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *VitesseCombo;
    QLabel *VitesseMesure;
    QLabel *TemperatureMesure;
    QComboBox *TemperatureCombo;
    QLabel *PressionMesure;
    QComboBox *PressionCombo;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *option)
    {
        if (option->objectName().isEmpty())
            option->setObjectName("option");
        option->resize(500, 459);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rc/Martz90-Circle-Settings.512.ico"), QSize(), QIcon::Normal, QIcon::Off);
        option->setWindowIcon(icon);
        option->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(option);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        General = new QGroupBox(option);
        General->setObjectName("General");
        COM = new QGroupBox(General);
        COM->setObjectName("COM");
        COM->setGeometry(QRect(12, 31, 461, 81));
        gridLayout = new QGridLayout(COM);
        gridLayout->setObjectName("gridLayout");
        COMRate = new QLabel(COM);
        COMRate->setObjectName("COMRate");

        gridLayout->addWidget(COMRate, 1, 0, 1, 1);

        COMBox = new QComboBox(COM);
        COMBox->setObjectName("COMBox");

        gridLayout->addWidget(COMBox, 0, 1, 1, 1);

        COMBaud = new QComboBox(COM);
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->addItem(QString());
        COMBaud->setObjectName("COMBaud");

        gridLayout->addWidget(COMBaud, 1, 1, 1, 1);

        COMLabel = new QLabel(COM);
        COMLabel->setObjectName("COMLabel");

        gridLayout->addWidget(COMLabel, 0, 0, 1, 1);

        groupBox = new QGroupBox(General);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 120, 461, 131));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        VitesseCombo = new QComboBox(groupBox);
        VitesseCombo->addItem(QString());
        VitesseCombo->addItem(QString());
        VitesseCombo->addItem(QString());
        VitesseCombo->setObjectName("VitesseCombo");

        gridLayout_2->addWidget(VitesseCombo, 2, 1, 1, 1);

        VitesseMesure = new QLabel(groupBox);
        VitesseMesure->setObjectName("VitesseMesure");

        gridLayout_2->addWidget(VitesseMesure, 2, 0, 1, 1);

        TemperatureMesure = new QLabel(groupBox);
        TemperatureMesure->setObjectName("TemperatureMesure");

        gridLayout_2->addWidget(TemperatureMesure, 0, 0, 1, 1);

        TemperatureCombo = new QComboBox(groupBox);
        TemperatureCombo->addItem(QString());
        TemperatureCombo->addItem(QString());
        TemperatureCombo->setObjectName("TemperatureCombo");

        gridLayout_2->addWidget(TemperatureCombo, 0, 1, 1, 1);

        PressionMesure = new QLabel(groupBox);
        PressionMesure->setObjectName("PressionMesure");

        gridLayout_2->addWidget(PressionMesure, 1, 0, 1, 1);

        PressionCombo = new QComboBox(groupBox);
        PressionCombo->addItem(QString());
        PressionCombo->addItem(QString());
        PressionCombo->addItem(QString());
        PressionCombo->setObjectName("PressionCombo");

        gridLayout_2->addWidget(PressionCombo, 1, 1, 1, 1);

        widget = new QWidget(General);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(300, 410, 168, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addWidget(General);


        retranslateUi(option);

        QMetaObject::connectSlotsByName(option);
    } // setupUi

    void retranslateUi(QDialog *option)
    {
        option->setWindowTitle(QCoreApplication::translate("option", "Param\303\250tres", nullptr));
        General->setTitle(QCoreApplication::translate("option", "General", nullptr));
        COM->setTitle(QString());
        COMRate->setText(QCoreApplication::translate("option", "Baudrate :", nullptr));
        COMBaud->setItemText(0, QCoreApplication::translate("option", "110", nullptr));
        COMBaud->setItemText(1, QCoreApplication::translate("option", "300", nullptr));
        COMBaud->setItemText(2, QCoreApplication::translate("option", "600", nullptr));
        COMBaud->setItemText(3, QCoreApplication::translate("option", "1200", nullptr));
        COMBaud->setItemText(4, QCoreApplication::translate("option", "2400", nullptr));
        COMBaud->setItemText(5, QCoreApplication::translate("option", "4800", nullptr));
        COMBaud->setItemText(6, QCoreApplication::translate("option", "9600", nullptr));
        COMBaud->setItemText(7, QCoreApplication::translate("option", "14400", nullptr));

        COMBaud->setCurrentText(QCoreApplication::translate("option", "110", nullptr));
        COMLabel->setText(QCoreApplication::translate("option", "Port COM :", nullptr));
        groupBox->setTitle(QString());
        VitesseCombo->setItemText(0, QCoreApplication::translate("option", "noeuds", nullptr));
        VitesseCombo->setItemText(1, QCoreApplication::translate("option", "km/h", nullptr));
        VitesseCombo->setItemText(2, QCoreApplication::translate("option", "m/s", nullptr));

        VitesseMesure->setText(QCoreApplication::translate("option", "Unit\303\251 de Vitesse", nullptr));
        TemperatureMesure->setText(QCoreApplication::translate("option", "Unit\303\251 de Temp\303\251rature", nullptr));
        TemperatureCombo->setItemText(0, QCoreApplication::translate("option", "Celsius", nullptr));
        TemperatureCombo->setItemText(1, QCoreApplication::translate("option", "Fahrenheit", nullptr));

        PressionMesure->setText(QCoreApplication::translate("option", "Unit\303\251 de Pression", nullptr));
        PressionCombo->setItemText(0, QCoreApplication::translate("option", "Inches", nullptr));
        PressionCombo->setItemText(1, QCoreApplication::translate("option", "Bar", nullptr));
        PressionCombo->setItemText(2, QCoreApplication::translate("option", "Millibar", nullptr));

        pushButton->setText(QCoreApplication::translate("option", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("option", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class option: public Ui_option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
