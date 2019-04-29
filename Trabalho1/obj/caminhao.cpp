#include "caminhao.h"

Caminhao::Caminhao()
{
   malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Truck  freightliner N200314.3DS");
   nome = "Caminhao";
}

void Caminhao::desenha(){
    glPushMatrix();
        Objeto::desenha();
        if(selecionado){
            GUI::setColor(1,0,0);
        }else{
            GUI::setColor(1,1,0);
        }
//        glTranslatef(0,0,0);
        glRotatef(90,0,1,0);
        glRotatef(-90,1,0,0);
        //X,Z,Y -> Global
        glScalef(0.0002,0.00028,0.00028);
        malha->draw();
    glPopMatrix();
}

void Caminhao::carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo){
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
