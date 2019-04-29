#ifndef LOJA_H
#define LOJA_H
#include <objeto.h>
#include <porta_loja.h>

class Loja: public Objeto
{
public:
    Loja();
    void desenha();
    void carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo);
private:
    Porta_Loja * porta;
};

#endif // LOJA_H
