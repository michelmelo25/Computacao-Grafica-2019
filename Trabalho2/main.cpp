#include <iostream>
#include <GL/glut.h>

#include <iostream>
#include <stdlib.h>

#include "CameraDistante.h"
#include "Desenha.h"

#include <curvas/ponto.h>

#include <vector>

#include <curvas/spline.h>

bool drawPontos = true;
int posSelecionado = -1;

Spline *  spline = new Spline;
vector<Ponto *> pontos;
vector<Ponto *> pronto;
Camera * cam = new CameraDistante();
Camera * goPro = new CameraDistante();
Camera * terceiraPessoa = new CameraDistante();

float delta = 0.01;
static bool trans_obj = false;


using namespace std;

static void key(unsigned char key, int x, int y)
{
    switch (key){
    //casos para saida
        case 27 : // esc
        case 13 : // enter
        case 'q':
            exit(0);

            break;

//        case '3':
//            Is3Pessoa = !Is3Pessoa;
//            break;

        case 'F': //Tela Cheira
            glutFullScreen();
            break;
        case 'f': //Minimizar
            glutReshapeWindow(800,600);
            break;

        case 'n': //Seleciona o proximo ponto da lista
        if (posSelecionado >= 0 and posSelecionado < pontos.size()) {
                   pontos[posSelecionado]->selecionado = false;
               }
               posSelecionado++;
               posSelecionado = posSelecionado%pontos.size();
               if (posSelecionado >= 0 and posSelecionado < pontos.size()) {
                   pontos[posSelecionado]->selecionado = true;
               }
            break;
        case 'N': //Seleciona o anterior ponto da lista
        if (posSelecionado >= 0 and posSelecionado < pontos.size()) {
                  pontos[posSelecionado]->selecionado = false;
              }
              posSelecionado--;
              if (posSelecionado < 0) {
                  posSelecionado = pontos.size()-1;
              }
              if (posSelecionado >= 0 and posSelecionado < pontos.size()) {
                  pontos[posSelecionado]->selecionado = true;
              }
            break;

        case 'p'://Adiciona um ponto na lista de pontos
            if(drawPontos){
                pontos.push_back(new Ponto);
                posSelecionado = (int) pontos.size() - 1;
            }
            break;

        case 'P'://Deleta um ponto da lista de pontos
            if(drawPontos && posSelecionado != -1){
                if(pontos.size() > 0){
                    if(pontos.size() == 1){
                        pontos.pop_back();
                    }else{
                        for(int i = posSelecionado; i < (((int) pontos.size()) - 1); i ++){
                            pontos.at(i) = pontos.at(i+1);
                        }
                        pontos.pop_back();
                        posSelecionado = (int) pontos.size() - 1;
                    }
                }
            }
            break;

        case 'd'://Alterna entra mostrar os pontos ou não, se não mostrar não é possivel adicionar ou remover pontos
            drawPontos = !drawPontos;
            if(!drawPontos){
                trans_obj = false;
            }
            break;



        case 'X': //move o ponto selecionado no eixo x
            pontos.at(posSelecionado)->t.x = pontos.at(posSelecionado)->t.x + .1;
            break;
        case 'x': //move o ponto selecionado no eixo x
            pontos.at(posSelecionado)->t.x = pontos.at(posSelecionado)->t.x - .1;
            break;

        case 'Y': //move o ponto selecionado no eixo y
            pontos.at(posSelecionado)->t.y = pontos.at(posSelecionado)->t.y + .1;
            break;
        case 'y': //move o ponto selecionado no eixo y
            pontos.at(posSelecionado)->t.y = pontos.at(posSelecionado)->t.y - .1;
            break;

        case 'Z': //move o ponto selecionado no eixo z
            pontos.at(posSelecionado)->t.z = pontos.at(posSelecionado)->t.z + .1;
            break;
        case 'z': //move o ponto selecionado no eixo z
            pontos.at(posSelecionado)->t.z = pontos.at(posSelecionado)->t.z - .1;
            break;

        case 'R': //reseta para o pronto de translação o ponto 0 0 0 o ponto selecionado do vetor
            pontos.at(posSelecionado)->t.x = 0;
            pontos.at(posSelecionado)->t.z = 0;
            pontos.at(posSelecionado)->t.y = 0;
            break;



//        case 't': //ativa as tranlações de pontos do vetor com mouse, se não existir objetos não ativa
//            if(selecionado == -1){

//            }else{
//                trans_obj = !trans_obj;
//            }
//            break;

        case 'I':{
            Ponto * p = new Ponto;
            p = new Ponto;
            p->t.x = -10; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -5; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 0; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 5; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);


            for(Ponto * p : pronto){
               delete p;
            }

            pontos.clear();



            for(Ponto * p : pronto){
               pontos.push_back(p);
            }

            pronto.clear();

            spline->setTipo(1);
            glutSetWindowTitle("Interpoladora");
            break;
            }

        case 'B':{
            Ponto * p = new Ponto;
            p = new Ponto;
            p->t.x = -10; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -5; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 0; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 5; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);

            pontos.clear();

            for(Ponto * p : pronto){
               pontos.push_back(p);
            }

            pronto.clear();

            spline->setTipo(2);
            glutSetWindowTitle("Bezier");
            break;
            }

        case 'H':{
            Ponto * p = new Ponto;
            p = new Ponto;
            p->t.x = -10; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -5; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 0; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 5; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);

            pontos.clear();

            for(Ponto * p : pronto){
               pontos.push_back(p);
            }

            pronto.clear();

            spline->setTipo(3);
            glutSetWindowTitle("Hermite");
            break;
            }

        case 'C':{
            Ponto * p = new Ponto;
            p->t.x = -25; p->t.y = -3; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -25; p->t.y = 3; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -15; p->t.y = 5; p->t.z = -3;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -10; p->t.y = 5; p->t.z = -3;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -5; p->t.y = 8; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 0; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 5; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 10; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 15; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 20; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 25; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 30; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);

            pontos.clear();

            for(Ponto * p : pronto){
               pontos.push_back(p);
            }

            pronto.clear();

            spline->setTipo(4);
            glutSetWindowTitle("Catmull-Rom");
            break;
            }

        case 'S':{
            Ponto * p = new Ponto;
            p->t.x = -25; p->t.y = -3; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -25; p->t.y = 3; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -15; p->t.y = 5; p->t.z = -3;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -10; p->t.y = 5; p->t.z = -3;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = -5; p->t.y = 8; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 0; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 5; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 10; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 15; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 20; p->t.y = 10; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 25; p->t.y = 5; p->t.z = 0;
            pronto.push_back(p);
            p = new Ponto;
            p->t.x = 30; p->t.y = 1; p->t.z = 0;
            pronto.push_back(p);

            pontos.clear();

            for(Ponto * p : pronto){
                pontos.push_back(p);
            }

            pronto.clear();

            spline->setTipo(5);
            glutSetWindowTitle("B-Spline");
            break;
            }

    }

    glutPostRedisplay();
}



int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
