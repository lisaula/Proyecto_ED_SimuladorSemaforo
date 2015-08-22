#ifndef ESTRELLA_H
#define ESTRELLA_H
#include "myitem.h"

class Estrella :public MyItem
{
public:
    void logica();

    void Invertir();
    Estrella(const QString &Filename,QGraphicsItem *parent=nullptr);
};

#endif // ESTRELLA_H
