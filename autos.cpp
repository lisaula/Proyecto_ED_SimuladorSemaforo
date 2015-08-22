#include "autos.h"

Autos::Autos(const QString &Filename, QGraphicsItem *parent): MyItem(Filename,parent)
{
    QString temp=Filename;
    tipo="";
    setSize(QSizeF(pixmap.width(),pixmap.height()));
    setPosition(QPointF(H_POSX_ID,H_POSY1));
    this->tipo_vel=0;
    espacio_ocupa=0;
    prioridad=false;
    setTipo(temp.toStdString());
}

void Autos::setTipo(string t){
    this->tipo=t;
    if(tipo==":turismo.png"){
        tipo_vel=2;
        espacio_ocupa=1;
        prioridad=false;
        setVelMax(QPointF(1.5,0));
        setVelocity(QPointF(1.5,0));
        setPosition(QPointF(H_POSX_ID,H_POSY1));

    }else if(tipo==":ambulancia.png"){
        tipo_vel=3;
        espacio_ocupa=1;
        prioridad=true;
        setVelMax(QPointF(1.5,0));
        setVelocity(QPointF(1.5,0));
    }else if(tipo==":Policia.png"){
        tipo_vel=3;
        espacio_ocupa=1;
        prioridad=true;
        setVelMax(QPointF(1.5,0));
        setVelocity(QPointF(1.5,0));
    }else if(tipo==":bus.png"){
        tipo_vel=4;
        espacio_ocupa=2;
        prioridad=false;
        setVelMax(QPointF(1.5,0));
        setVelocity(QPointF(1.5,0));
    }else{
        tipo_vel=1;
        espacio_ocupa=3;
        prioridad=false;
        setVelMax(QPointF(1.5,0));
        setVelocity(QPointF(-1.5,0));
        setPosition(QPointF(H_POSX_DI,H_POSY1));
    }
}

void Autos::logica(){

    float x=this->position().x();
    float y=this->position().y();
    float vx=this->velocity().x();
    float vy=this->velocity().y();

    x+= vx;

    if(x<0){
       setVelocity(QPointF(0.0,0.0));
       setPosition(QPointF(0,0));
    }
    if(y<0||y>659){
        vy = -vy;
    }
    this->setPosition(QPointF(x,y));
}

void Autos::cruzar(){

}

