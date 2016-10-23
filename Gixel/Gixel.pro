#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T14:52:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gixel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spritedatasheet.cpp \
<<<<<<< HEAD \
    setspritesize.cpp
    setspritesize.cpp

HEADERS  += mainwindow.h \
    spritedatasheet.h \
    setspritesize.h
=======
    tool.cpp \
    pen.cpp

HEADERS  += mainwindow.h \
    spritedatasheet.h \
    tool.h
>>>>>>> 6c96863fe0a47c1ab28e89ad0afca869a553255b

FORMS    += mainwindow.ui \
    setspritesize.ui
