#-------------------------------------------------
#
# Project created by QtCreator 2020-07-02T19:16:03
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarControlSystem
TEMPLATE = app


SOURCES += main.cpp\
        homewindow.cpp \
    mscplayer.cpp \
    vdoplayer.cpp

HEADERS  += homewindow.h \
    mscplayer.h \
    vdoplayer.h

FORMS    += homewindow.ui \
    mscplayer.ui \
    vdoplayer.ui

RESOURCES += \
    resources.qrc
