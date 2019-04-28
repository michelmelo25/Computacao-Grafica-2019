#include "arvore.h"
#include "objeto.h"

Arvore::Arvore()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Tree Ficus Carica N280518.3ds");
    nome = "Arvore";
}

void Arvore::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glNormal3f(0,1,0);
        glTranslatef(0,0.3,0);
        glRotatef(90,0,1,0);
        glRotatef(-90,1,0,0);
        //Z,X,Y
        glScalef(0.0025,0.002,0.003);
        malha->draw();
    glPopMatrix();
}
