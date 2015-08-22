#include "estrella.h"

Estrella::Estrella(const QString &Filename,QGraphicsItem *parent)
    :MyItem(Filename,parent)
{
}

void Estrella::logica(){
        float x=this->position().x();
        float y=this->position().y();
        float vx=this->velocity().x();
        float vy=this->velocity().y();

        x+= vx;
        y=0 ;

        if(x<0||x+this->size().width()>1054){
            vx=-vx;
        }
        if(y<0||y>659){
            vy = -vy;
        }

        vy +=0.5;

        this->setPosition(QPointF(x,y));
        this->setVelocity(QPointF(vx,vy));
}

void Estrella::Invertir(){
    QPixmap p =getPixmap();
    QImage img =p.toImage();
    QTransform mt;
    mt.rotate(180);
    img=img.transformed(mt);
    p.fromImage(img);
    this->setPixmap(p);
}
