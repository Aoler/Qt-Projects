#-------------------------------------------------
#
# Project created by QtCreator 2018-05-16T10:58:42
#
#-------------------------------------------------

TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets

EXAMPLE_FILES = RegexpPlugin.json

INCLUDEPATH += ../Interface

SOURCES += \
        regexpplugin.cpp

HEADERS += \
        regexpplugin.h

TARGET  = regexpplugin
DESTDIR = ../plugins
