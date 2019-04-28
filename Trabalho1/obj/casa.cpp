#include "casa.h"
#include "porta.h"
#include "janela_frontal.h"

Casa::Casa()
{
    porta = new Porta();
    janela = new Janela_Frontal();
    nome = "Casa";
}

void Casa::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(1,0,0);
            porta->selecionado = true;
        } else {
            GUI::setColor(1,1,0);
            porta->selecionado = false;
        }
        //face frente
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glVertex3f(1,0,1);
            glVertex3f(1,1,1);
            glVertex3f(0,1,1);
        glEnd();
        //face tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,0,0);
        glEnd();
        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(1,1,0);
            glVertex3f(1,1,1);
        glEnd();
        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,1,1);
            glVertex3f(0,1,0);
            glVertex3f(0,0,0);
        glEnd();
        //face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
        glEnd();
        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(0,0,1);
        glEnd();
        //telhado
        //esquerda
        glPushMatrix();
            glTranslatef(0,1,0);
            glRotatef(-90,0,1,0);
            glRotatef(-45,1,0,0);
            glScalef(1,1.4,1);
            glBegin(GL_POLYGON);
                glNormal3f(0,0,1);
                glVertex3f(0,0,0);
                glVertex3f(1,0,0);
                glVertex3f(0.5,0.5,0);
            glEnd();
        glPopMatrix();
        //frente
        glBegin(GL_POLYGON);
            glNormal3f(0,1,1);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //tras
        glBegin(GL_POLYGON);
            glNormal3f(0,1,-1);
            glVertex3f(1,1,0);
            glVertex3f(0,1,0);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //direita
        glBegin(GL_POLYGON);
            glNormal3f(1,1,0);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //Desenhando a porta e janela
        porta->desenha();
        janela->desenha();
    glPopMatrix();


}
