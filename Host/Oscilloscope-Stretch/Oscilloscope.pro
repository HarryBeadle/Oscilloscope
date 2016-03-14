#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T20:23:04
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

include(Libraries/qextserialport/src/qextserialport.pri)

TARGET = Oscilloscope
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    qcustomplot.cpp \
    Libraries/arduino-serial/arduino-serial-lib.cpp

HEADERS  += window.h \
    qcustomplot.h \
    Libraries/arduino-serial/arduino-serial-lib.h

FORMS    += window.ui
