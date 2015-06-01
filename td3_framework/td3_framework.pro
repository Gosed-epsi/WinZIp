#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T10:34:12
#
#-------------------------------------------------

QT       += core gui
QT += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = td3_ex1
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    directoryselector.cpp \
    filepool.cpp

HEADERS  += mainwindow.h \
    directoryselector.h \
    filepool.h \

FORMS    +=
