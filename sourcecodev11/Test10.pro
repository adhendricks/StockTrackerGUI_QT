#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T17:40:25
#
#-------------------------------------------------
RC_FILE += resources.rc

QT       += core gui


QT += webenginewidgets




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test10
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    cleardialog.cpp \
    view.cpp \
    about.cpp \
    displaygraph.cpp

HEADERS += \
        mainwindow.h \
    dialog.h \
    cleardialog.h \
    view.h \
    about.h \
    findstocksymbol.h \
    displaygraph.h

FORMS += \
        mainwindow.ui \
    dialog.ui \
    cleardialog.ui \
    view.ui \
    about.ui \
    displaygraph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += stocktracker.qrc

DISTFILES +=


win32 {
    RC_FILE = stocktracker.rc
}
