#ifndef CALLE_H
#define CALLE_H
#include <iostream>
#include "colacarros.h"
#include"semaforoh.h"
#include <stdlib.h>
#include<time.h>
#include "defines.h"
#include "myscene.h"
using namespace std;

class Calle
{
public:
    string nombre;

    void agregarCarro(MyScene *scn);
    void setearPosiciones(string tipo);
    SemaforoH * sema;
    Autos* random();
    void setearTipo(string t);
    Calle(string name);
private:
    float cx=0,cy=0,sx=0,sy=0;
    ColaCarros *cola1,*cola2;
    string tipo_carros[5]={":turismo.png",":ambulancia.png",":Policia.png",":bus.png",":camion.png"};

};

#endif // CALLE_H
