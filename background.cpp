#include "background.h"

Background::Background(const QString &Filename,QGraphicsItem *parent): MyItem(Filename,parent)
{
    setVelocity(QPointF(0.0,0.0));
    setPosition(QPointF(0.0,0.0));
    setSize(QSizeF(1054,659));
}

void Background::logica(){


}

