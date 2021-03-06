#-------------------------------------------------
#
# Project created by QtCreator 2018-10-10T15:31:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nodeConstructor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += graphicsItems\
               nodeModel

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(graphicsItems/graphicsItems.pri)
include(diagramScene/diagramScene.pri)
include(diagramView/diagramView.pri)
include(node/node.pri)
include(nodePainter/nodePainter.pri)
include(nodeModel/nodeModel.pri)
include(concreteNodes/concreteNodes.pri)
include(geometry/geometry.pri)
include(state/state.pri)
include(nodeDelegate/nodeDelegate.pri)

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
    stdutil.h

FORMS += \
        mainwindow.ui
