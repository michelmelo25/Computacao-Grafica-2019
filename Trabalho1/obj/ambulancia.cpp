#include "ambulancia.h"
#include "objeto.h"
#include <fstream>

Ambulancia::Ambulancia()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Car Ambulance N160614.3ds");
    nome = "Ambulancia";
}

void Ambulancia::desenha(){
    glPushMatrix();
        Objeto::desenha();
        if(selecionado){
            GUI::setColor(1,0,0);
        }else{
            GUI::setColor(1,1,0);
        }
        glTranslatef(0,0.26,0);
        glRotatef(-90,1,0,0);
        //X,Z,Y -> Global
        glScalef(0.0055,0.006,0.004);
        glColor3f(1,0,0);
        malha->draw();
    glPopMatrix();
}

void Ambulancia::carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo){
//    nome = "Ambulancia";
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
