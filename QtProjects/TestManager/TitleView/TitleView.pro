#-------------------------------------------------
#
# Project created by QtCreator 2018-05-23T11:08:47
#
#-------------------------------------------------

QT     += widgets
TEMPLATE  = lib
TARGET = TitleView
CONFIG += plugin

EXAMPLE_FILES = TitleView.json

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
    titleview.cpp \
    titleplugin.cpp

HEADERS += \
    titleview.h \
    titleplugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    titleview.ui
