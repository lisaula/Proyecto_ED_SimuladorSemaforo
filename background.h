#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "myitem.h"

class Background :public MyItem
{
public:
    void logica();
    Background(const QString &Filename,QGraphicsItem *parent=nullptr);
};

#endif // BACKGROUND_H
