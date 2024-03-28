/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *Icon;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName("about");
        about->resize(512, 249);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rc/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setWindowIcon(icon);
        Icon = new QLabel(about);
        Icon->setObjectName("Icon");
        Icon->setGeometry(QRect(10, 50, 161, 171));
        Icon->setPixmap(QPixmap(QString::fromUtf8(":/rc/icon.png")));
        Icon->setScaledContents(true);
        label_2 = new QLabel(about);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 60, 111, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_2->setFont(font);
        label = new QLabel(about);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 90, 111, 21));
        label_3 = new QLabel(about);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 120, 311, 61));
        QFont font1;
        font1.setPointSize(9);
        label_3->setFont(font1);
        label_3->setScaledContents(false);
        label_3->setWordWrap(true);

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "A propos", nullptr));
        Icon->setText(QString());
        label_2->setText(QCoreApplication::translate("about", "Weather Station ", nullptr));
        label->setText(QCoreApplication::translate("about", "<html><head/><body><p>Fond\303\251 sur <span style=\" color:#40cd52;\">QT</span> 6.6.2</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("about", "<html><head/><body><p><span style=\" color:#e0777d;\">WeatherStation</span>, est un programme permettant d'afficher la m\303\251t\303\251o ainsi que des donn\303\251es li\303\251 \303\240 celles-ci. Ne n\303\251cessite pas d'internet pour utiliser le programme.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
