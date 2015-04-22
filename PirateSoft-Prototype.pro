#-------------------------------------------------
#
# Project created by QtCreator 2015-03-15T02:13:12
#
#-------------------------------------------------
QT += widgets

TARGET = PirateSoft-Prototype
TEMPLATE = app


SOURCES += main.cpp \
    resttable.cpp \
    employeemenu.cpp \
    systemmenu.cpp \
    barchair.cpp \
    editmenu.cpp \
    Menu.cpp \
    receipt.cpp \
    backend/src/fooditem.cpp \
    backend/src/menumodel.cpp \
    backend/src/menucontroller.cpp \
    introwindow.cpp \
    backend/src/fooditem_serialize.cpp


HEADERS  += \
    resttable.h \
    employeemenu.h \
    systemmenu.h \
    barchair.h \
    editmenu.h \
    Menu.h \
    receipt.h \
    backend/include/fooditem.h \
    backend/include/iitem.h \
    backend/include/imenu.h \
    backend/include/imenucontroller.h \
    backend/include/iobserver.h \
    backend/include/menucontroller.h \
    backend/include/menumodel.h \
    backend/include/observer.h \
    mainwindow.h \
    backend/include/iviewable.h \
    introwindow.h \
    backend/include/fooditem_serialize.h \
    backend/include/iserializable.h \
    graphicsview.h

FORMS    += \
    employeemenu.ui \
    systemmenu.ui \
    editmenu.ui \
    Menu.ui \
    receipt.ui

RESOURCES +=
