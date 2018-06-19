#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T10:03:08
#
#-------------------------------------------------

QT     += widgets
TEMPLATE  = lib
TARGET = DetailView
CONFIG += plugin

EXAMPLE_FILES = DetailView.json

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
    detailview.cpp \
    detailplugin.cpp \
    treeitem.cpp \
    treemodel.cpp

HEADERS += \
    detailview.h \
    detailplugin.h \
    treeitem.h \
    treemodel.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    detailview.ui
