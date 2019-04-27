#ifndef LOJA_H
#define LOJA_H
#include <objeto.h>
#include <porta_loja.h>

class Loja: public Objeto
{
public:
    Loja();
    void desenha();
private:
    Porta_Loja * porta;
};

#endif // LOJA_H
