TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += obj
INCLUDEPATH += 3ds

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += \
        main.cpp\
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    obj/objeto.cpp \
    obj/casa.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    obj/porta.cpp \
    obj/janela_frontal.cpp \
    obj/predio.cpp \
    obj/janela_predio.cpp \
    obj/porta_predio.cpp \
    obj/asfalto.cpp \
    obj/loja.cpp \
    obj/arvore.cpp \
    obj/porta_loja.cpp \
    obj/ambulancia.cpp \
    obj/caminhao.cpp \
    obj/dirigivel.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    obj/objeto.h \
    obj/casa.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    obj/porta.h \
    obj/porta.h \
    obj/janela_frontal.h \
    obj/predio.h \
    obj/janela_predio.h \
    obj/porta_predio.h \
    obj/asfalto.h \
    obj/loja.h \
    obj/arvore.h \
    obj/porta_loja.h \
    obj/ambulancia.h \
    obj/caminhao.h \
    obj/dirigivel.h
