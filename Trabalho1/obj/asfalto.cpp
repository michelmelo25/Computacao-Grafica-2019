#include "asfalto.h"
#include "objeto.h"

Asfalto::Asfalto()
{
    nome = "Asfalto";
}

void Asfalto::desenha(){
    glPushMatrix();
        Objeto::desenha();
        if(selecionado){
            GUI::setColor(1,1,0);
        }else{
            GUI::setColor(0,0,0);
        }
        glTranslatef(0,0.01,0);
        glBegin(GL_QUADS);
            glVertex3f(0,0,1);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(0,0,0);
        glEnd();
        if(selecionado){
            GUI::setColor(0,0,0);
        }else{
            GUI::setColor(1,1,0);
        }
        glTranslatef(0,0.01,0);
        glBegin(GL_QUADS);
            glVertex3f(0,0,0.6);
            glVertex3f(1,0,0.6);
            glVertex3f(1,0,0.4);
            glVertex3f(0,0,0.4);
        glEnd();
    glPopMatrix();
}

void Asfalto::carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo){
    t.x = tx;
    t.y = ty;
    t.z = tz;
    a.x = ax;
    a.y = ay;
    a.z = az;
    s.x = sx;
    s.y = sy;
    s.z = sz;
    selecionado = isselecionado;
    origem = eixo;
}
