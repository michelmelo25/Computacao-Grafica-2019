#ifndef DIRIGIVEL_H
#define DIRIGIVEL_H
#include <objeto.h>

class Dirigivel: public Objeto
{
public:
    Dirigivel();
    void desenha();
    void carregar(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ax,GLfloat ay,GLfloat az,GLfloat sx,GLfloat sy,GLfloat sz,bool isselecionado, bool eixo);
};

#endif // DIRIGIVEL_H
