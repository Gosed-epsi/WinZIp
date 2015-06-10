#-------------------------------------------------
#
# Project created by QtCreator 2015-06-05T15:17:37
#
#-------------------------------------------------

QT       += core gui
QT += concurrent

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WinZip
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        directoryselector.cpp \
        epsifilecompressor.cpp \
        filepool.cpp \
        writer.cpp \
        zippedbuffer.cpp \
        zippedbufferpool.cpp \
        zipper.cpp \
    fileselector.cpp

HEADERS  += mainwindow.h \
            directoryselector.h \
            epsifilecompressor.h \
            filepool.h \
            writer.h \
            zippedbuffer.h \
            zippedbufferpool.h \
            zipper.h \
    fileselector.h

FORMS +=

DISTFILES +=
