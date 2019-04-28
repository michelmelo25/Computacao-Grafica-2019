#include "asfalto.h"
#include "objeto.h"

Asfalto::Asfalto()
{

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
