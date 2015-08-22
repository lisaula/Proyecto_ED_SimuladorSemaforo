#include "autos.h"

Autos::Autos(const QString &Filename, QGraphicsItem *parent): MyItem(Filename,parent)
{
    tipo="";
    setSize(QSizeF(pixmap.width(),pixmap.height()));
    this->tipo_vel=0;
    espacio_ocupa=0;
    prioridad=false;
    calle="";

}

void Autos::setBundingRect()
{
    bordes = boundingRect();
    cuadrado=QRect(bordes.x(),bordes.y(),bordes.width(),bordes.height());
}

void Autos::setTipo(string t){
    this->tipo=t;
    if(tipo==":turismo.png"){
        tipo_vel=2;
        espacio_ocupa=1;
        prioridad=false;
        x_vel=1.5*x_mul*direccionX;
        y_vel=1.5*y_mul*direccionY;
//        setVelMax(QPointF(1.5,1.5));
//        setVelocity(QPointF(x_vel,y_vel));

    }else if(tipo==":ambulancia.png"){
        tipo_vel=3;
        espacio_ocupa=1;
        prioridad=true;
        x_vel=3*x_mul*direccionX;
        y_vel=3*y_mul*direccionY;
//        setVelMax(QPointF(3,3));
//        setVelocity(QPointF(x_vel,y_vel));
    }else if(tipo==":Policia.png"){
        tipo_vel=3;
        espacio_ocupa=1;
        prioridad=true;
        x_vel=3*x_mul*direccionX;
        y_vel=3*y_mul*direccionY;
//        setVelMax(QPointF(3,3));
//        setVelocity(QPointF(x_vel,y_vel));
    }else if(tipo==":bus.png"){
        tipo_vel=4;
        espacio_ocupa=2;
        prioridad=false;
        x_vel=4*x_mul*direccionX;
        y_vel=4*y_mul*direccionY;
//        setVelMax(QPointF(4,4));
//        setVelocity(QPointF(x_vel,y_vel));
    }else{
        tipo_vel=1;
        espacio_ocupa=3;
        prioridad=false;
        x_vel=0.75*x_mul*direccionX;
        y_vel=0.75*y_mul*direccionY;
//        setVelMax(QPointF(0.75,0.75));
//        setVelocity(QPointF(x_vel,y_vel));
    }
    setVelMax(QPointF(0,0));
    setVelocity(QPointF(0,0));
}

void Autos::logica(){

    float x=this->position().x();
    float y=this->position().y();
    float vx=this->velocity().x();
    float vy=this->velocity().y();

    x+= vx;

    if(x<0){
       setVelocity(QPointF(0.0,0.0));
    }
    if(y<0||y>659){
        vy = -vy;
    }
    this->setPosition(QPointF(x,y));
    this->setBundingRect();
}

void Autos::setCalle(string s)
{
    calle=s;

}

void Autos::setVelSegunCalle(float x, float y)
{

    x_mul=x;
    y_mul=y;
}

void Autos::setDireccion(float x, float y)
{
    direccionX=x;
    direccionY=y;
}

void Autos::cruzar(){

}

