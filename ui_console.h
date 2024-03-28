/********************************************************************************
** Form generated from reading UI file 'console.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_console
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *Export;
    QCheckBox *Autoscroll;
    QPushButton *Effacer;
    QPlainTextEdit *Console;

    void setupUi(QDialog *console)
    {
        if (console->objectName().isEmpty())
            console->setObjectName("console");
        console->resize(438, 305);
        console->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rc/console.png"), QSize(), QIcon::Normal, QIcon::Off);
        console->setWindowIcon(icon);
        gridLayout = new QGridLayout(console);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(console);
        pushButton->setObjectName("pushButton");
        pushButton->setCheckable(true);

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        Export = new QPushButton(console);
        Export->setObjectName("Export");

        gridLayout->addWidget(Export, 5, 0, 1, 1);

        Autoscroll = new QCheckBox(console);
        Autoscroll->setObjectName("Autoscroll");
        Autoscroll->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(Autoscroll, 5, 3, 1, 1);

        Effacer = new QPushButton(console);
        Effacer->setObjectName("Effacer");

        gridLayout->addWidget(Effacer, 5, 2, 1, 1);

        Console = new QPlainTextEdit(console);
        Console->setObjectName("Console");
        Console->setUndoRedoEnabled(false);
        Console->setReadOnly(true);

        gridLayout->addWidget(Console, 0, 0, 3, 4);


        retranslateUi(console);

        QMetaObject::connectSlotsByName(console);
    } // setupUi

    void retranslateUi(QDialog *console)
    {
        console->setWindowTitle(QCoreApplication::translate("console", "Console", nullptr));
        pushButton->setText(QCoreApplication::translate("console", "Pause", nullptr));
        Export->setText(QCoreApplication::translate("console", "Export Console", nullptr));
        Autoscroll->setText(QCoreApplication::translate("console", "D\303\251filement automatique", nullptr));
        Effacer->setText(QCoreApplication::translate("console", "Effacer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class console: public Ui_console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_H
