#ifndef AUTOS_H
#define AUTOS_H
#include "myitem.h"
#include <iostream>
#include"defines.h"
#include<QRect>
#include<QRectF>
using namespace std;

class Autos :public MyItem
{
public:
    void logica();
    string tipo, calle;
    void setCalle(string s);
    float x_vel=0,y_vel=0,x_mul=0,y_mul=0;
    float direccionX=1,direccionY=1;
    void setVelSegunCalle(float, float);
    void setDireccion(float, float);
    bool prioridad;
    int espacio_ocupa;
    int tipo_vel;
    void setTipo(string tipo);
    void cruzar();
    Autos(const QString &Filename,QGraphicsItem *parent=nullptr);
    QRectF bordes;
    QRect cuadrado;
    void setBundingRect();
};

#endif // AUTOS_H
