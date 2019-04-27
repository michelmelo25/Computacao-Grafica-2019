#include "porta_loja.h"

Porta_Loja::Porta_Loja()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Door stefano galli N011112.3ds");
}

void Porta_Loja::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(1.45,0,1.02);
        glRotatef(-90,1,0,0);
        //X,Z,Y
        glScalef(0.0015,0.0028,0.0023);
        malha->draw();
        // Brilho do material
        int especMaterial = 70;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
