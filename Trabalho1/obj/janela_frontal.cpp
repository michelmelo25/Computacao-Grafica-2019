#include <janela_frontal.h>

Janela_Frontal::Janela_Frontal(){
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Window N211013.3DS");
    nome = "Janela_frintal";
}

void Janela_Frontal::desenha(){


    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.7,0.55,1.01);
        glRotatef(90,1,0,0);
        glRotated(-90,0,0,1);
        glScalef(0.01,0.017,0.017);
        malha->draw();
        // Brilho do material
        int especMaterial = 70;
        // Define a concentração do brilho
        glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
    glPopMatrix();
}
