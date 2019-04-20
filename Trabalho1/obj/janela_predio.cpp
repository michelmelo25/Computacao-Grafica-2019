#include "janela_predio.h"

Janela_predio::Janela_predio()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Window N211013.3DS");
}

void Janela_predio::desenha(){
    //Janelas frontais
    //Primeiro andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.1,0.7,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.6,0.7,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    //Segundo andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.1,1.2,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.6,1.2,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    //Terceiro andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.1,1.7,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.6,1.7,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    //Quarto andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.1,2.2,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.6,2.2,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    //Quinto andar
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.1,2.7,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
    glPushMatrix();
        Objeto::desenha();
        glTranslatef(0.6,2.7,1.01);
        glRotatef(90,0,1,0);
        glScalef(0.015,0.015,0.015);
        malha->draw();
    glPopMatrix();
}
