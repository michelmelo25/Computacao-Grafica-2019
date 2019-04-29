#ifndef CAMINHAO_H
#define CAMINHAO_H
#include <objeto.h>

class Caminhao: public Objeto
{
public:
    Caminhao();
    void desenha();
    void carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo);
};

#endif // CAMINHAO_H
