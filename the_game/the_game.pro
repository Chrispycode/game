QT += widgets

TEMPLATE = app

RESOURCES += the_game.qrc

TARGET = the_game

SOURCES += main.cpp \
    widget.cpp \
    shoot.cpp \
    plane.cpp \
    enemy.cpp

HEADERS += widget.h \
    shoot.h \
    plane.h \
    enemy.h

FORMS += widget.ui
