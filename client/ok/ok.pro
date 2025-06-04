QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gwangsan_org_system
TEMPLATE = app

SOURCES += main.cpp \
    dbmanager.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    schedule.cpp

HEADERS += \
    dbmanager.h \
    loginwindow.h \
    mainwindow.h \
    schedule.h

FORMS += \
    loginwindow.ui \
    mainwindow.ui \
    schedule.ui

INCLUDEPATH +=\
        # $$PWD/include
        /home/scar/ok_corp/client/ok/include


RESOURCES += \
    image.qrc
