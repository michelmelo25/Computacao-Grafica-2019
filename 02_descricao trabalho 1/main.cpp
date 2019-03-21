#include <iostream>

using namespace std;

#include <gui.h>
#include <vector>

bool deslocarCubo = false;

void desenha() {
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);
    //GUI::setLight(3,-5,3,5,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(1,0,0);
    GUI::drawFloor();

    //objeto transformado
    //glPushMatrix();
        glTranslatef(glutGUI::tx,glutGUI::ty,glutGUI::tz);
        glRotatef(glutGUI::az,0,0,1);
        glRotatef(glutGUI::ay,0,1,0);
        glRotatef(glutGUI::ax,1,0,0);
        GUI::drawOrigin(1);
        glScalef(glutGUI::sx,glutGUI::sy,glutGUI::sz);
        GUI::setColor(0,0,1);
        //GUI::drawBox(0,0,0, 1,1,1);
        //face frente
        glBegin(GL_QUADS);
            glNormal3f(0,1,1);
            glVertex3f(0,0,1);
            glVertex3f(1,0,1);
            glVertex3f(1,1,1);
            glVertex3f(0,1,1);
        glEnd();
        //face tras
        glBegin(GL_QUADS);
            glNormal3f(0,1,-1);
            glVertex3f(0,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,0,0);
            glVertex3f(0,0,0);
        glEnd();
        //face direita
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(1,1,0);
            glVertex3f(1,1,1);
        glEnd();
        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(1,-1,0);
            glVertex3f(0,0,1);
            glVertex3f(0,1,1);
            glVertex3f(0,1,0);
            glVertex3f(0,0,0);
        glEnd();
        //face Superior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,1,0);
            glVertex3f(0,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,0);
        glEnd();
        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(0,0,1);
        glEnd();
    //glPopMatrix();

    GUI::displayEnd();
}

void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key,x,y);

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'd':
        deslocarCubo = !deslocarCubo;
        break;
    default:
        break;
    }
}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado);
}


//while(true) {
//    desenha();
//    interacaoUsuario();
//}
