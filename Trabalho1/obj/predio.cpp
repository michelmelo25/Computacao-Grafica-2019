#include "predio.h"

Predio::Predio()
{
    janela = new Janela_predio();
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
            glVertex3f(1,0,1);
            glVertex3f(1,3,1);
            glVertex3f(0,3,1);
        glEnd();
//        face tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,3,0);
            glVertex3f(1,3,0);
            glVertex3f(1,0,0);
        glEnd();
//        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(1,3,0);
            glVertex3f(1,3,1);
        glEnd();
//        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,3,1);
            glVertex3f(0,3,0);
            glVertex3f(0,0,0);
        glEnd();
//        //face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,3,0);
            glVertex3f(0,3,1);
            glVertex3f(1,3,1);
            glVertex3f(1,3,0);
        glEnd();
//        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(0,0,1);
        glEnd();

        janela->desenha();
    glPopMatrix();
}
