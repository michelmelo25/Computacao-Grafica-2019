#include <janela_frontal.h>

Janela_Frontal::Janela_Frontal(){
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Window 1.3DS");
}

void Janela_Frontal::desenha(){


    glPushMatrix();
        Objeto::desenha();
//        glTranslatef(0.3,-0.72,0.999);
        glTranslatef(1.0,0.3,1.44);
        glRotatef(90,1,0,0);
        glRotated(-90,0,0,1);
        glScalef(-0.001,-0.0003,-0.00026);
        malha->draw();
        // Brilho do material
        int especMaterial = 70;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
