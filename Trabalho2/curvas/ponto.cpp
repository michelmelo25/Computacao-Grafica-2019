#include "ponto.h"

Ponto::Ponto(){

}

void Ponto::desenha(){
    glPushMatrix();
        glTranslated(t.x,t.y,t.z);
        glRotated(0,0,0,1);
        glRotated(0,0,1,0);
        glRotated(0,1,0,0);
        glScaled(1, 1, 1);

        glTranslated(0.5,0.5,0.5);
        glutSolidSphere(0.5,100,100);
    glPopMatrix();
}

Vetor3D Ponto::getCoordenadas(){
    return Vetor3D(t.x, t.y, t.z);
}
