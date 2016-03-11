#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T20:23:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(Libraries/qextserialport/src/qextserialport.pri)

TARGET = Oscilloscope
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp

HEADERS  += window.h

FORMS    += window.ui
