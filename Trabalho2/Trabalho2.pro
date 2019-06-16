TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += curvas

DEFINES += USE_SDL
LIBS += -lglut -l3ds -lGLU -lGL -lm -lSDL -lSDL_imag

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/Vetor3D.h \
    bib/model3ds.h \
    bib/objeto.h \
    curvas/ponto.h \
    curvas/spline.h \
    gui_glut/extra.h \
    gui_glut/gui.h \

SOURCES += \
    curvas/ponto.cpp \
    curvas/spline.cpp \
        main.cpp\
        bib/Camera.cpp \
        bib/CameraDistante.cpp \
        bib/CameraJogo.cpp \
        bib/Desenha.cpp \
        bib/Vetor3D.cpp \
        bib/objeto.cpp \
        bib/model3ds.cpp \
        gui_glut/extra.cpp \
        gui_glut/gui.cpp \
