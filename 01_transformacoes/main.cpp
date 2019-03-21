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

    //original
    //glPushMatrix();
        GUI::drawOrigin(1);
        GUI::setColor(1,1,0);
        if (!deslocarCubo) GUI::drawScaledBox(0.99,0,0,0, 1,1,1);
        else GUI::drawScaledBox(0.99,1,1,0, 2,2,1);
    //glPopMatrix();

    //transformado (mostrar cada trasformacao 3D individualmente)
    //glPushMatrix();
    //    glTranslatef(glutGUI::tx,glutGUI::ty,glutGUI::tz);
    //    //glRotatef(glutGUI::az,0,0,1);
    //    //glRotatef(glutGUI::ay,0,1,0);
    //    //glRotatef(glutGUI::ax,1,0,0);
    //    //glScalef(glutGUI::sx,glutGUI::sy,glutGUI::sz);
    //    //GUI::glShearXf(glutGUI::ty,glutGUI::tz);
    //    //GUI::glShearXYf(glutGUI::tz,glutGUI::ty);
    //    //GUI::glReflectPlaneYZf();
    //    GUI::setColor(0,0,1,0.5);
    //    if (!deslocarCubo) GUI::drawBox(0,0,0, 1,1,1);
    //    else GUI::drawBox(1,1,0, 2,2,1);
    //glPopMatrix();

    //matriz de composicao de transformacoes 2D (tecla 'o') (comentar original)
    //converte vertice em coords locais para coords globais
    //glPushMatrix();
    //    glutGUI::composite();
    //    //    glTranslatef(glutGUI::tx,glutGUI::ty,0.0);
    //    //    glRotatef(glutGUI::az,0,0,1);
    //    //    glScalef(glutGUI::sx,glutGUI::sy,1.0);
    //    GUI::drawOrigin(1);
    //    GUI::setColor(0,0,1);
    //    GUI::drawBox(0,0,-1, 1,1,0);
    //    //vertice
    //    GUI::setColor(0,1,1);
    //    GUI::drawSphere(glutGUI::lx,glutGUI::ly,glutGUI::lz,0.1);
    //glPopMatrix();

    //composicao de transformacoes 2D (tecla 'o')
    //glPushMatrix();
    //    //testar mudar a ordem
    //    //glTranslatef(glutGUI::lx,glutGUI::ly,0.0); //T2 <----------- à esquerda
    //    glTranslatef(glutGUI::tx,glutGUI::ty,0.0);
    //    glRotatef(glutGUI::az,0,0,1);
    //    //glScalef(glutGUI::sx,glutGUI::sy,1.0);
    //    //glTranslatef(glutGUI::lx,glutGUI::ly,0.0); //T2 <----------- à direita
    //    GUI::drawOrigin(1);
    //    GUI::setColor(0,0,1,0.5);
    //    if (!deslocarCubo) GUI::drawBox(0,0,0, 1,1,1);
    //    else GUI::drawBox(1,1,0, 2,2,1);
    //glPopMatrix();

    GUI::displayEnd();
}

void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key,x,y);

    float pl[4] = {glutGUI::lx,glutGUI::ly,glutGUI::lz,1.0};

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
    case 'g':
        glutGUI::showLocalAndGlobalCoords(pl);
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
