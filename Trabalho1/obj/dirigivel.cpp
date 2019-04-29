#include "dirigivel.h"

Dirigivel::Dirigivel()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Dirigible N220509.3DS");
    nome = "Dirigivel";
}

void Dirigivel::desenha(){
    glPushMatrix();
        Objeto::desenha();
        if(selecionado){
             GUI::setColor(1,0,0);

        }else{

        }

        glRotatef(90,0,0,1);
        glRotatef(90,0,1,0);
        glScalef(0.001,0.0009,0.001);
        malha->draw();
    glPopMatrix();
}

void Dirigivel::carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo){
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
