#-------------------------------------------------
#
# Project created by QtCreator 2015-01-12T20:12:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qtextender
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../Qtraspberrylib/mcp23017.cpp \
    ../../Qtraspberrylib/mcp23017_isr.cpp

LIBS += -lwiringPi

HEADERS  += mainwindow.h \
    ../../Qtraspberrylib/mcp23017.h \
    ../../Qtraspberrylib/mcp23017_isr.h \
    hardware_conf.h

FORMS    += mainwindow.ui
