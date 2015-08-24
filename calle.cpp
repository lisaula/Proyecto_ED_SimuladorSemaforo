#include "calle.h"

Calle::Calle(const QString &Filename,QGraphicsItem *parent): MyItem(Filename,parent)
{
    cola1 = new Cola(Filename);
    cola2 = new Cola2(Filename);
    sema= new SemaforoH(Filename);
    srand(time(NULL));
    activado=false;
}

void Calle::logica()
{
    cola1->logica();
    cola2->logica();
    sema->logica();

}

void Calle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    cola1->paint(painter,option,widget);
    cola2->paint(painter, option,widget);
    sema->paint(painter,option,widget);
}

void Calle::agregarCarro2()
{
    random2();
}

void Calle::activarSemaforo(int tiempo)
{
    sema->activar(tiempo);
}

void Calle::validarSema()
{
    int n=cola1->size();
    int n2 =cola2->size();
    if(n>0||n2>0){
        activarSemaforo(1520);
        activado=true;
    }
    if(n>4||n2>4){
        activarSemaforo(2500);
        activado=true;
    }
}

void Calle::validarSema2()
{
    if(activado == false){
        validarSema();
    }
    if(!sema->getActivo()){
        activado=false;
    }else{
        if(cola1->size()==0 && cola2->size()==0){
            activado==false;
            sema->tiempo=0;
        }
    }
}

Calle::~Calle()
{
    delete cola1;
    delete cola2;
}

void Calle::agregarCarro()
{
//    Autos * c =
            random();
//    cola1->push(c);
}

void Calle::setearPosiciones(string tipo)
{
    if(tipo=="Main St"){
        cx=V_POSX2;
        cy=V_POSY_BA;
        direccionY =-1;
        y_vel=1;

    }else if(tipo=="Maple St"){
        cx=V_POSX1;
        cy=V_POSY_AB;
        direccionY = 1;
        y_vel=1;

    }else if(tipo=="Adams Ave"){
        cx= H_POSX_DI;
        cy = H_POSY1;
        direccionX=-1;
        x_vel=1;

    }else{
        cx=H_POSX_ID;
        cy=H_POSY2;
        direccionX =1;
        x_vel=1;
    }
}

Autos*& Calle::random(){
    //srand(time(NULL));
    int x = rand()%5;
    int v = rand()%11;
//    if(x==1 || x==2){
//        if(v!=2 || v!=8){
//            x+=2;
//        }
//    }
    string tipo="";
    string tipo2="";
    Autos* c=NULL;
    tipo = tipo_carros[x];
    if(nombre == "Adams Ave" || nombre =="Creenshaw Ave"){
        c= new Autos(tipo.c_str());
    }else{
        tipo2 = tipo_carrosv[x];
        c= new Autos(tipo2.c_str());
    }
//    if(cola1->size()==0){
//        c->setPosition(QPointF(cx,cy));
//    }

    c->setCalle(nombre);
    c->setDireccion(direccionX,direccionY);
    c->setVelSegunCalle(x_vel,y_vel);
    c->setTipo(tipo);

    if(direccionX<0 && (nombre == "Adams Ave" || nombre =="Creenshaw Ave")){
        c->flip(true,false);
    }else if(direccionY>0 && (nombre == "Maple St" || nombre =="Main St")){
        c->flip(false,true);
    }
    cola1->push(c);
    return c;
}

Autos *Calle::random2()
{
    int x = rand()%5;
    int v = rand()%11;
//    if(x==1 || x==2){
//        if(v!=2 || v!=8){
//            x+=2;
//        }
//    }
    string tipo="";
    string tipo2="";
    Autos* c=NULL;
    tipo = tipo_carros[x];
    if(nombre == "Adams Ave" || nombre =="Creenshaw Ave"){
        c= new Autos(tipo.c_str());
    }else{
        tipo2 = tipo_carrosv[x];
        c= new Autos(tipo2.c_str());
    }

    c->setCalle(nombre);
    c->setDireccion(direccionX,direccionY);
    c->setVelSegunCalle(x_vel,y_vel);
    c->setTipo(tipo);

    if(direccionX<0 && (nombre == "Adams Ave" || nombre =="Creenshaw Ave")){
        c->flip(true,false);
    }else if(direccionY>0 && (nombre == "Maple St" || nombre =="Main St")){
        c->flip(false,true);
    }
    cola2->push(c);
    return c;
}

void Calle::setearTipo(string t)
{
    nombre = t;
    cola1->setName(nombre);
    cola2->setName(nombre);
    sema->setName(nombre);
    setearPosiciones(nombre);
}
