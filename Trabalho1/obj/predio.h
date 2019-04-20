#ifndef PREDIO_H
#define PREDIO_H
#include <objeto.h>
#include <Desenha.h>
#include <janela_predio.h>

class Predio: public Objeto
{
public:
    Predio();
    void desenha();
private:
    Janela_predio * janela;
};

#endif // PREDIO_H
