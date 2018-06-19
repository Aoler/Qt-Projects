#-------------------------------------------------
#
# Project created by QtCreator 2018-05-16T16:31:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestManager
TEMPLATE = app

# The following define makes your compiler emit warnings
DEFINES += QT_DEPRECATED_WARNINGS


CONFIG +=debug_and_release
CONFIG(debug,debug|release){
DESTDIR = $$PWD/../OutPut/Debug
LIBS += $$PWD/../OutPut/Debug/libMainForm.dylib \
}else{
DESTDIR = $$PWD/../OutPut/Release
LIBS += $$PWD/../OutPut/Release/libMainForm.dylib
}

INCLUDEPATH += $$PWD/../MainForm \
               $$PWD/../TitleView

SOURCES += \
        main.cpp

HEADERS +=

FORMS +=
