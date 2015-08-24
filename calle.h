#ifndef CALLE_H
#define CALLE_H
#include <iostream>
#include"semaforoh.h"
#include <stdlib.h>
#include<time.h>
#include "defines.h"
#include "myscene.h"
#include "cola.h"
#include "cola2.h"
using namespace std;

class Calle : public MyItem
{
public:
    string nombre;
    Cola *cola1;
    Cola2 *cola2;
    bool activado;
    void agregarCarro();
    void setearPosiciones(string tipo);
    float direccionX =1,direccionY =1;
    float x_vel=0,y_vel=0;
    SemaforoH * sema;
    Autos*& random();
    Autos* random2();
    void setearTipo(string t);
    Calle(const QString &Filename,QGraphicsItem *parent=nullptr);
    void logica();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);
    void agregarCarro2();
    void activarSemaforo(int tiempo);
    void validarSema();
    void validarSema2();
private:
    float cx=0,cy=0;

    string tipo_carros[5]={":turismo.png",":ambulancia.png",":Policia.png",":bus.png",":camion.png"};
    string tipo_carrosv[5]={":turismoV.png",":ambulanciaV.png",":PoliciaV.png",":busV.png",":camionV.png"};

};

#endif // CALLE_H
