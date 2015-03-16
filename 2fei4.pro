#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T16:04:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = 2fei4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    libs/config.cpp \
    libs/ftdi.cpp \
    libs/func.cpp \
    libs/geniobase.cpp

HEADERS  += mainwindow.h \
    libs/geniobase.h \
    libs/config.h \
    libs/ftdi.h \
    libs/func.h \
    libs/geniobase.h
FORMS    += mainwindow.ui

LIBS +=../hvcmos -lftd2xx
QMAKE_CXXFLAGS += -pthread -fopenmp -Wunused-parameter
