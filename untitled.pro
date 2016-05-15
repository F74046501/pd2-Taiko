#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T11:35:37
#
#-------------------------------------------------

QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game_scene.cpp

HEADERS  += mainwindow.h \
    game_scene.h

FORMS    += mainwindow.ui \
    game_scene.ui

RESOURCES += \
    pics.qrc
