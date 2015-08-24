#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T16:31:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto_ED_P1
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myitem.cpp \
    myscene.cpp \
    mythread.cpp \
    estrella.cpp \
    background.cpp \
    semaforoh.cpp \
    autos.cpp \
    colacarros.cpp \
    nodocarro.cpp \
    calle.cpp \
    interseccion.cpp \
    cola.cpp \
    cola2.cpp \
    nodop.cpp \
    pila.cpp

HEADERS  += widget.h \
    myitem.h \
    myscene.h \
    mythread.h \
    estrella.h \
    background.h \
    defines.h \
    semaforoh.h \
    autos.h \
    colacarros.h \
    nodocarro.h \
    calle.h \
    interseccion.h \
    cola.h \
    cola2.h \
    nodop.h \
    pila.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=gnu++11

RESOURCES += \
    res.qrc
