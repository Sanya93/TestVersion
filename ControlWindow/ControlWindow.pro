#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T14:29:37
#
#-------------------------------------------------

QT       += core gui opengl winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestVersion
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    screenwidget.cpp \
    screenmaker.cpp

HEADERS  += mainwindow.h \
    screenwidget.h \
    screenmaker.h

FORMS    += mainwindow.ui

LIBS += -lgdi32

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../HLib/release/ -lHLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../HLib/debug/ -lHLib

INCLUDEPATH += $$PWD/../HLib
DEPENDPATH += $$PWD/../HLib
