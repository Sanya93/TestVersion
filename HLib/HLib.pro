#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T16:39:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HLib
TEMPLATE = lib

DEFINES += HLIB_LIBRARY

SOURCES += hlib.cpp

HEADERS += hlib.h\
        hlib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
