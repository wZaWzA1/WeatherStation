/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOptions;
    QAction *actionQuitter;
    QAction *actionConsole;
    QAction *actionA_propos;
    QAction *actionGraphique;
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *Group1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *PressionIco;
    QLabel *PressionLabel;
    QLabel *Pression;
    QHBoxLayout *horizontalLayout_2;
    QLabel *VentIco;
    QLabel *PressionLabel_2;
    QLabel *Vent;
    QHBoxLayout *horizontalLayout_3;
    QLabel *RapporterIco;
    QLabel *RapporterLabel;
    QLabel *Rapporter;
    QHBoxLayout *horizontalLayout_7;
    QLabel *TimeIco;
    QLabel *Time;
    QGroupBox *Group2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *RefroidissementICO;
    QLabel *RefroidissementLabel;
    QLabel *Refroidissement;
    QHBoxLayout *horizontalLayout_5;
    QLabel *GPSIco;
    QLabel *GPSLabel;
    QLabel *GPS;
    QHBoxLayout *horizontalLayout_6;
    QLabel *DirectionICO;
    QLabel *DirectionLabel;
    QLabel *Direction;
    QLabel *LabelTemp;
    QLabel *LabelError;
    QLabel *Invalide;
    QLabel *TempIco;
    QMenuBar *menubar;
    QMenu *menuProgramme;
    QMenu *menuAutres;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(699, 476);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rc/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName("actionOptions");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rc/Martz90-Circle-Settings.512.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon1);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName("actionQuitter");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rc/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon2);
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName("actionConsole");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rc/console.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConsole->setIcon(icon3);
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName("actionA_propos");
        actionGraphique = new QAction(MainWindow);
        actionGraphique->setObjectName("actionGraphique");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rc/graphique.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGraphique->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 190, 671, 177));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        groupBox_2->setFlat(true);
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(-1, 9, -1, 19);
        Group1 = new QGroupBox(groupBox_2);
        Group1->setObjectName("Group1");
        Group1->setAutoFillBackground(false);
        Group1->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(Group1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        PressionIco = new QLabel(Group1);
        PressionIco->setObjectName("PressionIco");
        PressionIco->setEnabled(true);
        PressionIco->setMaximumSize(QSize(31, 31));
        PressionIco->setPixmap(QPixmap(QString::fromUtf8(":/rc/pression.png")));
        PressionIco->setScaledContents(true);

        horizontalLayout->addWidget(PressionIco);

        PressionLabel = new QLabel(Group1);
        PressionLabel->setObjectName("PressionLabel");
        QFont font;
        font.setBold(true);
        PressionLabel->setFont(font);

        horizontalLayout->addWidget(PressionLabel);

        Pression = new QLabel(Group1);
        Pression->setObjectName("Pression");
        Pression->setFont(font);

        horizontalLayout->addWidget(Pression);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        VentIco = new QLabel(Group1);
        VentIco->setObjectName("VentIco");
        VentIco->setEnabled(true);
        VentIco->setMaximumSize(QSize(31, 31));
        VentIco->setPixmap(QPixmap(QString::fromUtf8(":/rc/vent.png")));
        VentIco->setScaledContents(true);

        horizontalLayout_2->addWidget(VentIco);

        PressionLabel_2 = new QLabel(Group1);
        PressionLabel_2->setObjectName("PressionLabel_2");
        PressionLabel_2->setFont(font);

        horizontalLayout_2->addWidget(PressionLabel_2);

        Vent = new QLabel(Group1);
        Vent->setObjectName("Vent");
        Vent->setFont(font);

        horizontalLayout_2->addWidget(Vent);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        RapporterIco = new QLabel(Group1);
        RapporterIco->setObjectName("RapporterIco");
        RapporterIco->setEnabled(true);
        RapporterIco->setMaximumSize(QSize(31, 31));
        RapporterIco->setPixmap(QPixmap(QString::fromUtf8(":/rc/rapporteur.png")));
        RapporterIco->setScaledContents(true);

        horizontalLayout_3->addWidget(RapporterIco);

        RapporterLabel = new QLabel(Group1);
        RapporterLabel->setObjectName("RapporterLabel");
        RapporterLabel->setFont(font);

        horizontalLayout_3->addWidget(RapporterLabel);

        Rapporter = new QLabel(Group1);
        Rapporter->setObjectName("Rapporter");
        Rapporter->setFont(font);

        horizontalLayout_3->addWidget(Rapporter);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_8->addWidget(Group1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(62, -1, -1, -1);
        TimeIco = new QLabel(groupBox_2);
        TimeIco->setObjectName("TimeIco");
        TimeIco->setMaximumSize(QSize(42, 39));
        TimeIco->setPixmap(QPixmap(QString::fromUtf8(":/rc/time.png")));
        TimeIco->setScaledContents(true);

        horizontalLayout_7->addWidget(TimeIco);

        Time = new QLabel(groupBox_2);
        Time->setObjectName("Time");

        horizontalLayout_7->addWidget(Time);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        Group2 = new QGroupBox(groupBox_2);
        Group2->setObjectName("Group2");
        Group2->setStyleSheet(QString::fromUtf8("/*border: 0"));
        verticalLayout_4 = new QVBoxLayout(Group2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        RefroidissementICO = new QLabel(Group2);
        RefroidissementICO->setObjectName("RefroidissementICO");
        RefroidissementICO->setEnabled(true);
        RefroidissementICO->setMinimumSize(QSize(41, 31));
        RefroidissementICO->setMaximumSize(QSize(41, 31));
        RefroidissementICO->setPixmap(QPixmap(QString::fromUtf8(":/rc/eolien.png")));
        RefroidissementICO->setScaledContents(true);

        horizontalLayout_4->addWidget(RefroidissementICO);

        RefroidissementLabel = new QLabel(Group2);
        RefroidissementLabel->setObjectName("RefroidissementLabel");
        RefroidissementLabel->setFont(font);

        horizontalLayout_4->addWidget(RefroidissementLabel);

        Refroidissement = new QLabel(Group2);
        Refroidissement->setObjectName("Refroidissement");
        Refroidissement->setFont(font);

        horizontalLayout_4->addWidget(Refroidissement);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        GPSIco = new QLabel(Group2);
        GPSIco->setObjectName("GPSIco");
        GPSIco->setEnabled(true);
        GPSIco->setMinimumSize(QSize(1, 1));
        GPSIco->setMaximumSize(QSize(31, 21));
        GPSIco->setPixmap(QPixmap(QString::fromUtf8(":/rc/gps.png")));
        GPSIco->setScaledContents(true);
        GPSIco->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        GPSIco->setWordWrap(false);

        horizontalLayout_5->addWidget(GPSIco);

        GPSLabel = new QLabel(Group2);
        GPSLabel->setObjectName("GPSLabel");
        GPSLabel->setFont(font);

        horizontalLayout_5->addWidget(GPSLabel);

        GPS = new QLabel(Group2);
        GPS->setObjectName("GPS");
        GPS->setFont(font);

        horizontalLayout_5->addWidget(GPS);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        DirectionICO = new QLabel(Group2);
        DirectionICO->setObjectName("DirectionICO");
        DirectionICO->setEnabled(true);
        DirectionICO->setMinimumSize(QSize(31, 31));
        DirectionICO->setMaximumSize(QSize(31, 31));
        DirectionICO->setPixmap(QPixmap(QString::fromUtf8(":/rc/aiguille.png")));
        DirectionICO->setScaledContents(true);

        horizontalLayout_6->addWidget(DirectionICO);

        DirectionLabel = new QLabel(Group2);
        DirectionLabel->setObjectName("DirectionLabel");
        DirectionLabel->setFont(font);

        horizontalLayout_6->addWidget(DirectionLabel);

        Direction = new QLabel(Group2);
        Direction->setObjectName("Direction");
        Direction->setFont(font);

        horizontalLayout_6->addWidget(Direction);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_8->addWidget(Group2);

        LabelTemp = new QLabel(centralwidget);
        LabelTemp->setObjectName("LabelTemp");
        LabelTemp->setGeometry(QRect(0, 60, 701, 38));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(25);
        font1.setBold(true);
        LabelTemp->setFont(font1);
        LabelTemp->setStyleSheet(QString::fromUtf8("border-bottom-width: 1px;\n"
"border-bottom-style: solid;\n"
"border-radius: 0px;"));
        LabelTemp->setFrameShape(QFrame::NoFrame);
        LabelTemp->setTextFormat(Qt::AutoText);
        LabelTemp->setScaledContents(true);
        LabelTemp->setAlignment(Qt::AlignCenter);
        LabelError = new QLabel(centralwidget);
        LabelError->setObjectName("LabelError");
        LabelError->setGeometry(QRect(100, 100, 551, 81));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        LabelError->setFont(font2);
        LabelError->setScaledContents(false);
        LabelError->setWordWrap(true);
        Invalide = new QLabel(centralwidget);
        Invalide->setObjectName("Invalide");
        Invalide->setEnabled(false);
        Invalide->setGeometry(QRect(190, 160, 311, 31));
        Invalide->setWordWrap(true);
        TempIco = new QLabel(centralwidget);
        TempIco->setObjectName("TempIco");
        TempIco->setGeometry(QRect(260, 60, 41, 41));
        TempIco->setMaximumSize(QSize(31313, 1331313));
        TempIco->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0)"));
        TempIco->setMidLineWidth(1);
        TempIco->setPixmap(QPixmap(QString::fromUtf8(":/rc/temperature.png")));
        TempIco->setScaledContents(true);
        TempIco->setMargin(0);
        TempIco->setIndent(-1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 699, 21));
        menuProgramme = new QMenu(menubar);
        menuProgramme->setObjectName("menuProgramme");
        menuAutres = new QMenu(menubar);
        menuAutres->setObjectName("menuAutres");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuProgramme->menuAction());
        menubar->addAction(menuAutres->menuAction());
        menuProgramme->addAction(actionOptions);
        menuProgramme->addAction(actionGraphique);
        menuProgramme->addAction(actionConsole);
        menuProgramme->addAction(actionQuitter);
        menuAutres->addAction(actionA_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "WeatherStation", nullptr));
        actionOptions->setText(QCoreApplication::translate("MainWindow", "Param\303\250tres", nullptr));
        actionQuitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        actionConsole->setText(QCoreApplication::translate("MainWindow", "Console", nullptr));
        actionA_propos->setText(QCoreApplication::translate("MainWindow", "A propos", nullptr));
        actionGraphique->setText(QCoreApplication::translate("MainWindow", "Graphique", nullptr));
        groupBox_2->setTitle(QString());
        Group1->setTitle(QString());
        PressionIco->setText(QString());
#if QT_CONFIG(tooltip)
        PressionLabel->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Pression atmosph\303\251rique</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        PressionLabel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        PressionLabel->setText(QCoreApplication::translate("MainWindow", "Pression", nullptr));
#if QT_CONFIG(tooltip)
        Pression->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        Pression->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Pression->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        VentIco->setText(QString());
#if QT_CONFIG(tooltip)
        PressionLabel_2->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Vitesse du vent</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        PressionLabel_2->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        PressionLabel_2->setText(QCoreApplication::translate("MainWindow", "Vent", nullptr));
#if QT_CONFIG(tooltip)
        Vent->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        Vent->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Vent->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        RapporterIco->setText(QString());
#if QT_CONFIG(tooltip)
        RapporterLabel->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Angle du vent<br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        RapporterLabel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        RapporterLabel->setText(QCoreApplication::translate("MainWindow", "Angle Vent", nullptr));
#if QT_CONFIG(tooltip)
        Rapporter->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        Rapporter->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Rapporter->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        TimeIco->setText(QString());
        Time->setText(QCoreApplication::translate("MainWindow", "temps", nullptr));
        Group2->setTitle(QString());
        RefroidissementICO->setText(QString());
#if QT_CONFIG(tooltip)
        RefroidissementLabel->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Refroidissement \303\251olien.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        RefroidissementLabel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        RefroidissementLabel->setText(QCoreApplication::translate("MainWindow", "Refroidissement", nullptr));
#if QT_CONFIG(tooltip)
        Refroidissement->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        Refroidissement->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Refroidissement->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        GPSIco->setText(QString());
#if QT_CONFIG(tooltip)
        GPSLabel->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Nombre de satellites</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        GPSLabel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        GPSLabel->setText(QCoreApplication::translate("MainWindow", "GPS Satellites", nullptr));
#if QT_CONFIG(tooltip)
        GPS->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        GPS->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        GPS->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        DirectionICO->setText(QString());
#if QT_CONFIG(tooltip)
        DirectionLabel->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Direction du port m\303\251t\303\251o</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        DirectionLabel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        DirectionLabel->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
#if QT_CONFIG(tooltip)
        Direction->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        Direction->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Direction->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
#if QT_CONFIG(tooltip)
        LabelTemp->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Temp\303\251rature de l'air.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        LabelTemp->setText(QCoreApplication::translate("MainWindow", "temperature", nullptr));
        LabelError->setText(QCoreApplication::translate("MainWindow", "Veuillez aller dans Programme > Param\303\250tres\n"
"Puis s\303\251lectionner le port COM valide\n"
".", nullptr));
        Invalide->setText(QCoreApplication::translate("MainWindow", "null", nullptr));
        TempIco->setText(QString());
        menuProgramme->setTitle(QCoreApplication::translate("MainWindow", "Programme", nullptr));
        menuAutres->setTitle(QCoreApplication::translate("MainWindow", "Autres", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
