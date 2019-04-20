#ifndef CASA_H
#define CASA_H

#include <objeto.h>
#include <porta.h>

class Casa : public Objeto
{
public:
    Casa();
    void desenha();

private:
    Porta * porta;
};

#endif // CASA_H
