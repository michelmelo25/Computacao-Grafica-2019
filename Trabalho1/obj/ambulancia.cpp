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

