#include "janela_predio.h"

Janela_predio::Janela_predio()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Window N211013.3DS");
    nome = "Janela_predio";
}

void Janela_predio::desenha(){
    //Janelas frontais
    //Primeiro andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.2,1.4,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.9,1.4,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    //Segundo andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.2,2.0,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.9,2.0,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    //Terceiro andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.2,2.6,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.9,2.6,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    //Quarto andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.2,3.2,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.9,3.2,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    //Quinto andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.2,3.8,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.9,3.8,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.02,0.02,0.02);
        malha->draw();
    glPopMatrix();
}
