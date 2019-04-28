#include "loja.h"

Loja::Loja()
{
    porta = new Porta_Loja();
    nome = "Loja";
}

void Loja::desenha(){
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(1,0,0);
        } else {
            GUI::setColor(1,1,0);
        }
        //Face frontal
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glVertex3f(2,0,1);
            glVertex3f(2,1,1);
            glVertex3f(0,1,1);
        glEnd();
        //Face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(2,0,1);
            glVertex3f(2,0,0);
            glVertex3f(2,1,0);
            glVertex3f(2,1,1);
        glEnd();
        //Face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,1,1);
            glVertex3f(0,1,0);
            glVertex3f(0,0,0);
        glEnd();
        //Face tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,1,0);
            glVertex3f(2,1,0);
            glVertex3f(2,0,0);
        glEnd();
        //Face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0,1,1);
            glVertex3f(2,1,1);
            glVertex3f(2,1,0);
        glEnd();
        //Face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(2,0,0);
            glVertex3f(2,0,1);
            glVertex3f(0,0,1);
        glEnd();
        porta->desenha();
    glPopMatrix();
}
