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
