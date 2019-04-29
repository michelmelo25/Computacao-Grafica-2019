#ifndef ASFALTO_H
#define ASFALTO_H
#include <objeto.h>

class Asfalto: public Objeto
{
public:
    Asfalto();
    void desenha();
    void carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo);
};

#endif // ASFALTO_H
