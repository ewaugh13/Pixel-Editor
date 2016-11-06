#-------------------------------------------------
#
# Project created by QtCreator 2016-11-05T13:33:05
#
#-------------------------------------------------

QT       += core gui

TARGET = GifPlugin
TEMPLATE = lib
CONFIG += plugin

DESTDIR = $$[QT_INSTALL_PLUGINS]/imageformats

SOURCES += gifplugin.cpp

HEADERS += gifplugin.h
DISTFILES += GifPlugin.json

unix {
    target.path = /usr/lib
    INSTALLS += target
}
