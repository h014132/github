QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assistance
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainpage.cpp \
    askforhelp.cpp \
    tohelpothers.cpp

RESOURCES += \        
    summary.qrc

HEADERS += \
    mainpage.h \
    askforhelp.h \
    tohelpothers.h
