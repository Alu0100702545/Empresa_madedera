#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T22:39:46
#
#-------------------------------------------------

QT       += core gui
QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robotico
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    terreno.cpp \
    robot.cpp \
    celda.cpp \
    vistagrafica.cpp

HEADERS  += mainwindow.h \
    terreno.h \
    robot.h \
    celda.h \
    vistagrafica.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    Imagenes.qrc
