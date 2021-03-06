#-------------------------------------------------
#
# Project created by QtCreator 2015-07-14T20:40:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = platform
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flux.cpp \
    emprunt.cpp \
    fusionneur.cpp \
    fusionneurbuilder.cpp \
    test.cpp \
    unittest.cpp \
    hanoi.cpp \
    point.cpp

HEADERS  += mainwindow.h \
    graph.h \
    flux.h \
    emprunt.h \
    fusionneur.h \
    fusionneurbuilder.h \
    graph_test.h \
    test.h \
    unittest.h \
    arbre.h \
    hanoi.h \
    utils.h \
    tuple.h \
    point.h

FORMS    += mainwindow.ui
