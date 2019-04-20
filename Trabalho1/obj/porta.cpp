#include "porta.h"

Porta::Porta()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Door 1.3ds");
}

void Porta::desenha(){

//    if (selecionado) {
//        glColor3d(1,0,0);
//    }else {
//        glColor3d(1,1,0);
//    }

    glPushMatrix();
//        glTranslatef(0.3,-0.72,0.999);
        glTranslatef(0.3,0.3,1.0);
        glRotatef(90,0,1,0);
        glRotated(-90,1,0,0);
        glScalef(-0.001,-0.0003,-0.00026);
        malha->draw();
    glPopMatrix();
}
