TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS+=-lglut
LIBS+=-lGL
LIBS+=-lGLU

SOURCES += main.cpp \
    matrix.cpp \
    vector.cpp \
    color.cpp \
    obj_parser.cpp \
    projection.cpp \
    surface_rendering.cpp \
    transformation.cpp \
    pixel_plot.cpp \
    light.cpp \
    camera.cpp \
    material.cpp \
    mouse_event.cpp \
    vertex.cpp \
    keyboard_event.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    matrix.h \
    vector.h \
    color.h \
    obj_parser.h \
    projection.h \
    surface_rendering.h \
    transformation.h \
    pixel_plot.h \
    light.h \
    camera.h \
    material.h \
    illumination.h \
    mouse_event.h \
    vertex.h \
    keyboard_event.h

