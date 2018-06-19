#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T14:44:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CommTool
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

CONFIG +=debug_and_release
CONFIG(debug,debug|release){
DESTDIR = $$PWD/../OutPut/Debug
LIBS += $$PWD/../OutPut/Debug/libCoreLib.a
}else{
DESTDIR = $$PWD/../OutPut/Release
LIBS += $$PWD/../OutPut/Release/libCoreLib.a
}

INCLUDEPATH += $$PWD/../CoreLib/ZmqSource

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    multipagewidget.cpp \
    treeitem.cpp \
    treemodel.cpp \
    netform.cpp

HEADERS += \
        mainwindow.h \
    multipagewidget.h \
    treeitem.h \
    treemodel.h \
    netform.h

FORMS += \
        mainwindow.ui \
    netform.ui
