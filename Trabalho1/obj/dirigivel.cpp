#include "dirigivel.h"

Dirigivel::Dirigivel()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/Trabalho1/3ds/Dirigible N220509.3DS");
    nome = "Dirirgivel";
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
