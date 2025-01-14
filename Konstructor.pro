#-------------------------------------------------
#
# Project created by QtCreator 2019-09-10T16:42:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Konstructor
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
    src/main.cpp \
    src/mainwindow.cpp \
    src/ViewWidget.cpp \
    src/ClassRepository/GlobalVariables.cpp \
    src/ClassRepository/Settings.cpp \
    src/ClassRepository/Drawables/Circle.cpp \
    src/ClassRepository/Drawables/DrawableObject.cpp \
    src/ClassRepository/Drawables/Line.cpp \
    src/ClassRepository/Drawables/Point.cpp \
    src/ClassRepository/Tools/Tool.cpp \
    src/ClassRepository/Tools/CircleTool.cpp \
    src/ClassRepository/Tools/RectangleTool.cpp \
    src/ClassRepository/Tools/LabelTool.cpp \
    src/ClassRepository/Tools/LineTool.cpp \
    src/ClassRepository/DrawablesFactory.cpp

HEADERS += \
    src/mainwindow.h \
    src/ViewWidget.h \
    src/ClassRepository/GlobalVariables.h \
    src/ClassRepository/Settings.h \
    src/ClassRepository/Vector.h \
    src/ClassRepository/Drawables/Circle.h \
    src/ClassRepository/Drawables/DrawableObject.h \
    src/ClassRepository/Drawables/Line.h \
    src/ClassRepository/Drawables/Point.h \
    src/ClassRepository/Tools/Tool.h \
    src/ClassRepository/Tools/LineTool.h \
    src/ClassRepository/Tools/CircleTool.h \
    src/ClassRepository/Tools/RectangleTool.h \
    src/ClassRepository/Tools/LabelTool.h \
    src/ClassRepository/DrawablesFactory.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CodeStyle.md
