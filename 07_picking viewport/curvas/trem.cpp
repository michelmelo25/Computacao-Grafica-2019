#include "trem.h"

Trem::Trem()
{
    malha = new Model3DS("/home/michel/Documentos/Computacao-Grafica-2019/07_picking viewport/curvas/st.3ds");
}

void Trem::desenha(){
    glPushMatrix();
        glColor3d(0.5,.5,.5);
        glTranslated(2.2, 0, 1.1);
        glRotated(-90, 1, 0, 0);
        glRotated(45, 0, 0, 1);
        glScaled(0.02, 0.02, 0.02);
        malha->draw();
    glPopMatrix();
}
