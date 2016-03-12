#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T20:23:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = Oscilloscope
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    qcustomplot.cpp

HEADERS  += window.h \
    qcustomplot.h

FORMS    += window.ui
