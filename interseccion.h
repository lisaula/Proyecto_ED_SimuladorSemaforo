#ifndef INTERSECCION_H
#define INTERSECCION_H
#include "calle.h"
#include "myscene.h"
#include "mythread.h"
class Interseccion
{
public:
    Calle *main,*maple,*creenshow,*adams;
    void cruzar();
    Interseccion();
    MyScene* getScene();

private:
    MyScene *scn;

};

#endif // INTERSECCION_H
