#include "autos.h"

Autos::Autos(const QString &Filename, QGraphicsItem *parent): MyItem(Filename,parent)
{
    tipo="";
    setSize(QSizeF(pixmap.width(),pixmap.height()));
    this->tipo_vel=0;
    espacio_ocupa=0;
    prioridad=false;
    calle="";
    pasar = false;
    salio=false;
    opuesto="";
    srand(time(NULL));
}

void Autos::setBundingRect()
{
    bordes = boundingRect();
    cuadrado=QRect(bordes.x(),bordes.y(),bordes.width(),bordes.height());
}

int Autos::random()
{
    int x = 1+rand()%3;
    return x;
}

void Autos::validarSalio(float x, float y)
{
    if(calle=="Adams Ave"){
        if(x<250){
           salio = true;
        }
    }else if(calle =="Creenshaw Ave"){
        if(x>813){
           salio = true;
        }
    }else if(calle=="Main St"){
        if(y<163){
           salio = true;
        }
    }else{
        if(y>493){
           salio = true;
        }
    }
}

void Autos::validarOpuesto()
{
    if(calle=="Adams Ave"){
        opuesto="Creenshaw Ave";

    }else if(calle =="Creenshaw Ave"){
        opuesto = "Adams Ave";

    }else if(calle=="Main St"){
        opuesto = "Maple St";

    }else{
        opuesto="Main St";
    }
}

bool Autos::randonm()
{
    int x= rand()%5;
    cout<<"Random :"<<x<<endl;
    if(x==2){
        return true;
    }
    return false;
}

bool Autos::paseLimite(float x, float y)
{
    if(calle=="Creenshaw Ave"){
        if(x>230.2)
            return true;
    }else if(calle=="Adams Ave"){
        if(x<788.2)
            return true;
    }else if(calle == "Main St"){
        if(y<430.35)
            return true;
    }else{
        if(y>130)
            return true;
    }
    return false;
}

void Autos::setTipo(string t){
    this->tipo=t;
    if(tipo==":turismo.png" ||tipo==":turismoV.png"){
        tipo_vel=2;
        espacio_ocupa=1;
        prioridad=false;
        x_vel=1.5*x_mul*direccionX;
        y_vel=1.5*y_mul*direccionY;
        x_vel=x_vel/random();
        y_vel=y_vel/random();
        setVelMax(QPointF(1.5,1.5));
        setVelocity(QPointF(x_vel,y_vel));

    }else if(tipo==":ambulancia.png"||tipo==":ambulanciaV.png" ){
        tipo_vel=3;
        espacio_ocupa=1;
        prioridad=true;
        x_vel=3*x_mul*direccionX;
        y_vel=3*y_mul*direccionY;
        setVelMax(QPointF(3,3));
        setVelocity(QPointF(x_vel,y_vel));
    }else if(tipo==":Policia.png" || tipo==":PoliciaV.png"){
        tipo_vel=3;
        espacio_ocupa=1;
        prioridad=true;
        x_vel=3*x_mul*direccionX;
        y_vel=3*y_mul*direccionY;
        setVelMax(QPointF(3,3));
        setVelocity(QPointF(x_vel,y_vel));
    }else if(tipo==":bus.png"||tipo==":busV.png"){
        tipo_vel=4;
        espacio_ocupa=2;
        prioridad=false;
        x_vel=4*x_mul*direccionX;
        y_vel=4*y_mul*direccionY;
        x_vel=x_vel/random();
        y_vel=y_vel/random();
        setVelMax(QPointF(4,4));
        setVelocity(QPointF(x_vel,y_vel));
    }else{
        tipo_vel=1;
        espacio_ocupa=3;
        prioridad=false;
        x_vel=0.75*x_mul*direccionX;
        y_vel=0.75*y_mul*direccionY;
        setVelMax(QPointF(0.75,0.75));
        setVelocity(QPointF(x_vel,y_vel));
    }
}

void Autos::logica(){
    float x=this->position().x();
    float y=this->position().y();
    float vx=this->velocity().x();
    float vy=this->velocity().y();

    if(pasar){
        x+= vx;
        y+=vy;
        validarSalio(x,y);

        this->setPosition(QPointF(x,y));
        this->setBundingRect();
    }
}

void Autos::setCalle(string s)
{
    calle=s;
    validarOpuesto();

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

void Autos::cruzar(bool cruzar){
    this->pasar = cruzar;
}

