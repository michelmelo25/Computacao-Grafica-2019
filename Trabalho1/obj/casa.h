#ifndef CASA_H
#define CASA_H

#include <objeto.h>
#include <porta.h>
#include <janela_frontal.h>

class Casa : public Objeto
{
public:
    Casa();
    void desenha();

private:
    Porta * porta;
    Janela_Frontal * janela;
};

#endif // CASA_H
