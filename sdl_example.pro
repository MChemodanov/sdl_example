#-------------------------------------------------
#
# Project created by QtCreator 2015-04-03T06:27:15
#
#-------------------------------------------------

#win32:QMAKE_LIBS_QT_ENGTRY -= lqtmain
#win32-g++:DEFINES -= QT_NEEDS_QMAIN

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sdl_example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


win32: LIBS += -L$$PWD/SDL2-2.0.3/i686-w64-mingw32/lib/ -lSDL2

INCLUDEPATH += $$PWD/SDL2-2.0.3/i686-w64-mingw32/include
DEPENDPATH += $$PWD/SDL2-2.0.3/i686-w64-mingw32/include

