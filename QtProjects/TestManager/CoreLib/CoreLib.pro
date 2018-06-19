#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T14:17:57
#
#-------------------------------------------------

QT       -= gui

TARGET = CoreLib
TEMPLATE = lib
CONFIG += staticlib

CONFIG +=debug_and_release
CONFIG(debug,debug|release){
DESTDIR = $$PWD/../OutPut/Debug
}else{
DESTDIR = $$PWD/../OutPut/Release
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += $$PWD/ZmqLib/libzmq.a



SOURCES += \
    ZmqSource/Publisher.cpp \
    ZmqSource/Replier.cpp \
    ZmqSource/Requester.cpp \
    ZmqSource/Subscriber.cpp

HEADERS += \
    ZmqSource/Publisher.hpp \
    ZmqSource/Replier.hpp \
    ZmqSource/Requester.hpp \
    ZmqSource/Subscriber.hpp \
    ZmqLib/zmq_utils.h \
    ZmqLib/zmq.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}