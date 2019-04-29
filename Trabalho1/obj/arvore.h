#ifndef ARVORE_H
#define ARVORE_H
#include <objeto.h>


class Arvore: public Objeto
{
public:
    Arvore();
    void desenha();
    void carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo);
};

#endif // ARVORE_H
