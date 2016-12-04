TEMPLATE = app

LIBS +=  -lX11  -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -L/usr/lib/x86_64-linux_gnu/ -lyaml-cpp -L/usr/local/lib/ -lAGE
INCLUDEPATH += /usr/local/include src

CONFIG += c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += gui
QT += core
QT += widgets

SOURCES += src/main.cpp \
    src/core.cpp \
    src/player.cpp \
    src/entities.cpp

HEADERS += \
    src/core.hpp \
    src/player.h \
    src/entities.hpp

