#ifndef AUTOS_H
#define AUTOS_H
#include "myitem.h"
#include <iostream>
#include"defines.h"
using namespace std;

class Autos :public MyItem
{
public:
    void logica();
    string tipo;
    bool prioridad;
    int espacio_ocupa;
    int tipo_vel;
    void setTipo(string tipo);
    void cruzar();
    Autos(const QString &Filename,QGraphicsItem *parent=nullptr);
};

#endif // AUTOS_H
