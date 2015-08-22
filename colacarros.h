#ifndef COLACARROS_H
#define COLACARROS_H
#include "nodocarro.h"

class ColaCarros
{
public:
    NodoCarro *root, *end;
    void push(Autos *c);
    Autos* pop();
    Autos* first();
    void limpiar();
    void anular();
    int size();
    bool desplazar(Autos *c);
    ColaCarros();
};

#endif // COLACARROS_H
