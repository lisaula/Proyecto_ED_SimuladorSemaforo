#ifndef NODOCARRO_H
#define NODOCARRO_H
#include "autos.h"

class NodoCarro
{
public:
    Autos *carro;
    NodoCarro *sig, *ant;
    NodoCarro(Autos* c);
};

#endif // NODOCARRO_H
