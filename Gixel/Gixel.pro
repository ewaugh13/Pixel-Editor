#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T14:52:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gixel
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    spritedatasheet.cpp \
    setspritesize.cpp \
    tool.cpp \
    pen.cpp \
    rendercanvas.cpp

HEADERS  += mainwindow.h \
    spritedatasheet.h \
    setspritesize.h \
    tool.h \
    rendercanvas.h

FORMS    += mainwindow.ui \
    setspritesize.ui
