QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Motion
TEMPLATE = app

SOURCES += main.cpp

HEADERS  += motion.h \
    LTDMC.h

win32: LIBS += -L$$PWD/ -lLTDMC
INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
