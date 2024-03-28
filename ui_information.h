/********************************************************************************
** Form generated from reading UI file 'information.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_information
{
public:
    QGridLayout *gridLayout;
    QGroupBox *XDRGroup;
    QVBoxLayout *verticalLayout;
    QLabel *XDRTemp;
    QLabel *XDRTempT;
    QLabel *XDRIndex;
    QLabel *XDRPression;
    QLabel *XDRPitch;
    QLabel *XDRPRoll;
    QGroupBox *RotBox;
    QGridLayout *gridLayout_2;
    QLabel *ROTRate;
    QLabel *ROTStatus;
    QGroupBox *MWVGroup;
    QLabel *MWVWind;
    QLabel *MWVReference;
    QLabel *MWVSpeed;
    QLabel *MWVStatus;
    QComboBox *comboBox;
    QGroupBox *WIMDAGroup;
    QVBoxLayout *verticalLayout_2;
    QLabel *WIMDAPression;
    QLabel *WIMDAPressionB;
    QLabel *WIMDATemperature;
    QLabel *WIMDAHumide;
    QLabel *WIMDAPDR;
    QLabel *WIMDAVent;
    QLabel *WIMDADirection;
    QLabel *WIMDAVitesse;
    QLabel *WIMDAVitesseVENT;

    void setupUi(QDialog *information)
    {
        if (information->objectName().isEmpty())
            information->setObjectName("information");
        information->resize(1566, 862);
        gridLayout = new QGridLayout(information);
        gridLayout->setObjectName("gridLayout");
        XDRGroup = new QGroupBox(information);
        XDRGroup->setObjectName("XDRGroup");
        verticalLayout = new QVBoxLayout(XDRGroup);
        verticalLayout->setObjectName("verticalLayout");
        XDRTemp = new QLabel(XDRGroup);
        XDRTemp->setObjectName("XDRTemp");

        verticalLayout->addWidget(XDRTemp);

        XDRTempT = new QLabel(XDRGroup);
        XDRTempT->setObjectName("XDRTempT");

        verticalLayout->addWidget(XDRTempT);

        XDRIndex = new QLabel(XDRGroup);
        XDRIndex->setObjectName("XDRIndex");

        verticalLayout->addWidget(XDRIndex);

        XDRPression = new QLabel(XDRGroup);
        XDRPression->setObjectName("XDRPression");

        verticalLayout->addWidget(XDRPression);

        XDRPitch = new QLabel(XDRGroup);
        XDRPitch->setObjectName("XDRPitch");

        verticalLayout->addWidget(XDRPitch);

        XDRPRoll = new QLabel(XDRGroup);
        XDRPRoll->setObjectName("XDRPRoll");

        verticalLayout->addWidget(XDRPRoll);


        gridLayout->addWidget(XDRGroup, 0, 0, 1, 1);

        RotBox = new QGroupBox(information);
        RotBox->setObjectName("RotBox");
        gridLayout_2 = new QGridLayout(RotBox);
        gridLayout_2->setObjectName("gridLayout_2");
        ROTRate = new QLabel(RotBox);
        ROTRate->setObjectName("ROTRate");

        gridLayout_2->addWidget(ROTRate, 0, 0, 1, 1);

        ROTStatus = new QLabel(RotBox);
        ROTStatus->setObjectName("ROTStatus");

        gridLayout_2->addWidget(ROTStatus, 1, 0, 1, 1);


        gridLayout->addWidget(RotBox, 0, 1, 1, 1);

        MWVGroup = new QGroupBox(information);
        MWVGroup->setObjectName("MWVGroup");
        MWVWind = new QLabel(MWVGroup);
        MWVWind->setObjectName("MWVWind");
        MWVWind->setGeometry(QRect(12, 31, 491, 191));
        MWVReference = new QLabel(MWVGroup);
        MWVReference->setObjectName("MWVReference");
        MWVReference->setGeometry(QRect(12, 225, 491, 191));
        MWVSpeed = new QLabel(MWVGroup);
        MWVSpeed->setObjectName("MWVSpeed");
        MWVSpeed->setGeometry(QRect(12, 450, 491, 191));
        MWVStatus = new QLabel(MWVGroup);
        MWVStatus->setObjectName("MWVStatus");
        MWVStatus->setGeometry(QRect(12, 644, 491, 191));
        comboBox = new QComboBox(MWVGroup);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(230, 540, 91, 21));

        gridLayout->addWidget(MWVGroup, 0, 2, 1, 1);

        WIMDAGroup = new QGroupBox(information);
        WIMDAGroup->setObjectName("WIMDAGroup");
        WIMDAGroup->setMinimumSize(QSize(523, 0));
        verticalLayout_2 = new QVBoxLayout(WIMDAGroup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        WIMDAPression = new QLabel(WIMDAGroup);
        WIMDAPression->setObjectName("WIMDAPression");

        verticalLayout_2->addWidget(WIMDAPression);

        WIMDAPressionB = new QLabel(WIMDAGroup);
        WIMDAPressionB->setObjectName("WIMDAPressionB");

        verticalLayout_2->addWidget(WIMDAPressionB);

        WIMDATemperature = new QLabel(WIMDAGroup);
        WIMDATemperature->setObjectName("WIMDATemperature");

        verticalLayout_2->addWidget(WIMDATemperature);

        WIMDAHumide = new QLabel(WIMDAGroup);
        WIMDAHumide->setObjectName("WIMDAHumide");

        verticalLayout_2->addWidget(WIMDAHumide);

        WIMDAPDR = new QLabel(WIMDAGroup);
        WIMDAPDR->setObjectName("WIMDAPDR");

        verticalLayout_2->addWidget(WIMDAPDR);

        WIMDAVent = new QLabel(WIMDAGroup);
        WIMDAVent->setObjectName("WIMDAVent");

        verticalLayout_2->addWidget(WIMDAVent);

        WIMDADirection = new QLabel(WIMDAGroup);
        WIMDADirection->setObjectName("WIMDADirection");

        verticalLayout_2->addWidget(WIMDADirection);

        WIMDAVitesse = new QLabel(WIMDAGroup);
        WIMDAVitesse->setObjectName("WIMDAVitesse");

        verticalLayout_2->addWidget(WIMDAVitesse);

        WIMDAVitesseVENT = new QLabel(WIMDAGroup);
        WIMDAVitesseVENT->setObjectName("WIMDAVitesseVENT");

        verticalLayout_2->addWidget(WIMDAVitesseVENT);


        gridLayout->addWidget(WIMDAGroup, 0, 3, 1, 1);


        retranslateUi(information);

        QMetaObject::connectSlotsByName(information);
    } // setupUi

    void retranslateUi(QDialog *information)
    {
        information->setWindowTitle(QCoreApplication::translate("information", "Dialog", nullptr));
        XDRGroup->setTitle(QCoreApplication::translate("information", "XDR", nullptr));
        XDRTemp->setText(QCoreApplication::translate("information", "Temperature", nullptr));
        XDRTempT->setText(QCoreApplication::translate("information", "Temperature th\303\251orique", nullptr));
        XDRIndex->setText(QCoreApplication::translate("information", "Index", nullptr));
        XDRPression->setText(QCoreApplication::translate("information", "Pression", nullptr));
        XDRPitch->setText(QCoreApplication::translate("information", "Hauteur", nullptr));
        XDRPRoll->setText(QCoreApplication::translate("information", "Profondeur", nullptr));
        RotBox->setTitle(QCoreApplication::translate("information", "ROT", nullptr));
        ROTRate->setText(QCoreApplication::translate("information", "Rate", nullptr));
        ROTStatus->setText(QCoreApplication::translate("information", "Status", nullptr));
        MWVGroup->setTitle(QCoreApplication::translate("information", "MWV", nullptr));
        MWVWind->setText(QCoreApplication::translate("information", "Angle du vent", nullptr));
        MWVReference->setText(QCoreApplication::translate("information", "Reference", nullptr));
        MWVSpeed->setText(QCoreApplication::translate("information", "Vitesse du vent", nullptr));
        MWVStatus->setText(QCoreApplication::translate("information", "Status", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("information", "noeuds", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("information", "km/h", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("information", "m/s", nullptr));

        WIMDAGroup->setTitle(QCoreApplication::translate("information", "MDA", nullptr));
        WIMDAPression->setText(QCoreApplication::translate("information", "Pression (Inches)", nullptr));
        WIMDAPressionB->setText(QCoreApplication::translate("information", "Pression (bars)", nullptr));
        WIMDATemperature->setText(QCoreApplication::translate("information", "Temp\303\251rature exterieur", nullptr));
        WIMDAHumide->setText(QCoreApplication::translate("information", "Humidit\303\251 relatif", nullptr));
        WIMDAPDR->setText(QCoreApplication::translate("information", "Point de ros\303\251e", nullptr));
        WIMDAVent->setText(QCoreApplication::translate("information", "Direction du vent", nullptr));
        WIMDADirection->setText(QCoreApplication::translate("information", "Direction du vent magn\303\251tique", nullptr));
        WIMDAVitesse->setText(QCoreApplication::translate("information", "Vitesse du vent", nullptr));
        WIMDAVitesseVENT->setText(QCoreApplication::translate("information", "Vitesse du vent m/s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class information: public Ui_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
