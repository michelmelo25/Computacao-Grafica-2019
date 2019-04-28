#include "predio.h"
#include <fstream>

Predio::Predio()
{
    janela = new Janela_predio();
    porta = new Porta_predio();
    nome = "Predio";
}

void Predio::desenha(){
    glPushMatrix();
        Objeto::desenha();
        if (selecionado) {
            GUI::setColor(1,0,0);
        } else {
            GUI::setColor(1,1,0);
        }
        //face frente
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glVertex3f(1.5,0,1);
            glVertex3f(1.5,4.3,1);
            glVertex3f(0,4.3,1);
        glEnd();
//        face tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,4.3,0);
            glVertex3f(1.5,4.3,0);
            glVertex3f(1.5,0,0);
        glEnd();
//        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1.5,0,1);
            glVertex3f(1.5,0,0);
            glVertex3f(1.5,4.3,0);
            glVertex3f(1.5,4.3,1);
        glEnd();
//        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,4.3,1);
            glVertex3f(0,4.3,0);
            glVertex3f(0,0,0);
        glEnd();
//        //face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,4.3,0);
            glVertex3f(0,4.3,1);
            glVertex3f(1.5,4.3,1);
            glVertex3f(1.5,4.3,0);
        glEnd();
//        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1.5,0,0);
            glVertex3f(1.5,0,1);
            glVertex3f(0,0,1);
        glEnd();

        janela->desenha();
        porta->desenha();
    glPopMatrix();
}
