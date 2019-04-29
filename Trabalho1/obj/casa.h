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
    void carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo);

private:
    Porta * porta;
    Janela_Frontal * janela;
};

#endif // CASA_H
