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
    ColaCarros *cola1,*cola2;
    void agregarCarro(MyScene* &scn);
    void setearPosiciones(string tipo);
    float direccionX =1,direccionY =1;
    float x_vel=0,y_vel=0;
    SemaforoH * sema;
    Autos* random();
    void setearTipo(string t);
    Calle(string name);
private:
    float cx=0,cy=0,sx=0,sy=0;

    string tipo_carros[5]={":turismo.png",":ambulancia.png",":Policia.png",":bus.png",":camion.png"};
    string tipo_carrosv[5]={":turismoV.png",":ambulanciaV.png",":PoliciaV.png",":busV.png",":camionV.png"};

};

#endif // CALLE_H
