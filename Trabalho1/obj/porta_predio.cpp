#include "porta_predio.h"

Porta_predio::Porta_predio()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Door N270410.3DS");
}

void Porta_predio::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.75,0.01,1.01);
        glRotatef(-90,1,0,0);
        glScalef(0.00029,0.0002,0.00027);
        malha->draw();
    glPopMatrix();
}
