#ifndef PONTO_H
#define PONTO_H
#include <objeto.h>
#include <Vetor3D.h>
#include <GL/glut.h>

class Ponto: public Objeto
{
public:
    Ponto();
    void desenha();
    Vetor3D getCoordenadas();
};

#endif // PONTO_H
