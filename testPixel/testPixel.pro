#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T23:50:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testPixel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawmodel.cpp \
    sizeselector.cpp

HEADERS  += mainwindow.h \
    drawmodel.h \
    sizeselector.h

FORMS    += mainwindow.ui \
    sizeselector.ui

RESOURCES += \
    resources.qrc
