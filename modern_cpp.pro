TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console c++17

SOURCES += \
        main.cpp

HEADERS += $$files(*.hpp, true)

LIBS += -pthread
LIBS +=  -lstdc++
