QT       += core gui
QT += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qcustomplot.cpp \
    about.cpp \
    console.cpp \
    graphique.cpp \
    main.cpp \
    mainwindow.cpp \
    option.cpp \
    port.cpp \
    trames.cpp

HEADERS += \
    qcustomplot.h \
    about.h \
    console.h \
    graphique.h \
    mainwindow.h \
    option.h \
    param.h \
    port.h \
    trames.h

FORMS += \
    about.ui \
    console.ui \
    graphique.ui \
    mainwindow.ui \
    option.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += serialport
QT += charts
QT += widgets
QT += printsupport

DEFINES += UNICODE
DEFINES -= _MBCS

RESOURCES += qdarkstyle/dark/darkstyle.qrc \
    logo/logo.qrc

RC_ICONS = icon.ico

QMAKE_CXXFLAGS_RELEASE -= -O
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2

# add the desired -O3 if not present
QMAKE_CXXFLAGS_RELEASE *= -O3
