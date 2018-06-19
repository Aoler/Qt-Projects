#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T10:06:50
#
#-------------------------------------------------

QT       += widgets

TARGET = UUTView
TEMPLATE = lib

CONFIG += plugin

EXAMPLE_FILES = UUTView.json

CONFIG +=debug_and_release
CONFIG(debug,debug|release){
DESTDIR = $$PWD/../OutPut/Debug
LIBS += $$PWD/../OutPut/Debug/libMainForm.dylib
}else{
DESTDIR = $$PWD/../OutPut/Release
LIBS += $$PWD/../OutPut/Release/libMainForm.dylib
}

INCLUDEPATH += $$PWD/../MainForm

SOURCES += \
    uutplugin.cpp \
    uutview.cpp

HEADERS += \
    uutplugin.h \
    uutview.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    uutview.ui
