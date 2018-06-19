#-------------------------------------------------
#
# Project created by QtCreator 2018-05-24T12:02:39
#
#-------------------------------------------------

QT       += widgets

TARGET = MainForm
TEMPLATE = lib

CONFIG += plugin

#DEFINES += MAINFORM_LIBRARY

CONFIG +=debug_and_release
CONFIG(debug,debug|release){
DESTDIR = $$PWD/../OutPut/Debug
}else{
DESTDIR = $$PWD/../OutPut/Release
}

SOURCES += \
    mainwindow.cpp \
    plugininterface.cpp

HEADERS += \
    common.h \
    mainwindow.h \
    plugininterface.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    mainwindow.ui
