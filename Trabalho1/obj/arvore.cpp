#include "arvore.h"
#include "objeto.h"

Arvore::Arvore()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Tree Ficus Carica N280518.3ds");
    nome = "Arvore";
}

void Arvore::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glNormal3f(0,1,0);
        glTranslatef(0,0.3,0);
        glRotatef(90,0,1,0);
        glRotatef(-90,1,0,0);
        //Z,X,Y
        glScalef(0.0025,0.002,0.003);
        malha->draw();
    glPopMatrix();
}

void Arvore::carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo){
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
