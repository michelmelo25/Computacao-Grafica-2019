#ifndef SPLINE_H
#define SPLINE_H

#include <Vetor3D.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include <Desenha.h>

using namespace std;

class Spline
{
public:

    float Modo[4][4];
    vector<Vetor3D> Pn;
    Vetor3D * P;
    float delta = .01;


    Spline();


    void atualizarPontosDeControle(vector<Vetor3D> pontosDeControle);
    Vetor3D d1(float u);
    Vetor3D d2(float u);
    Vetor3D PTu(float u);
    void desenhaTrilho();
    void setTipo(int tipo);
};

#endif // SPLINE_H
