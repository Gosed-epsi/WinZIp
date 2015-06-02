#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T03:13:00
#
#-------------------------------------------------

QT       += core gui
QT += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WinZip
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    filepool.cpp \
    zipper.cpp \
    zippedbuffer.cpp \
    zippedbufferpool.cpp \
    writer.cpp \
    epsifilecompressor.cpp \
    mainwindow.cpp \
    directoryselector.cpp

HEADERS += \
    filepool.h \
    zipper.h \
    zippedbuffer.h \
    zippedbufferpool.h \
    writer.h \
    epsifilecompressor.h \
    mainwindow.h \
    directoryselector.h

FORMS    +=
