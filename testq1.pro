#-------------------------------------------------
#
# Project created by QtCreator 2017-10-07T13:45:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testq1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    untils.cpp \
    t1view.cpp \
    t2view.cpp \
    drawitem.cpp \
    t3view.cpp

HEADERS += \
        mainwindow.h \
    constant.h \
    untils.h \
    t1view.h \
    t2view.h \
    drawitem.h \
    t3view.h

#FORMS += \
#        mainwindow.ui

FORMS +=
