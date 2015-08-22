#include "calle.h"

Calle::Calle(string name)
{
    cola1 = new ColaCarros();
    cola2 = new ColaCarros();
    nombre = name;
    setearPosiciones(name);
}

void Calle::agregarCarro(MyScene* &scn)
{
    Autos * c = random();
    cola1->push(c);
    scn->addActor(c);
}

void Calle::setearPosiciones(string tipo)
{
    if(tipo=="Main St"){
        cx=V_POSX2;
        cy=V_POSY_BA;
        sx=847.88;
        sy=585.70;
        direccionY =-1;
        y_vel=1;

    }else if(tipo=="Maple St"){
        sx=122.0;
        sy=100.0;
        cx=V_POSX1;
        cy=V_POSY_AB;
        direccionY = 1;
        y_vel=1;

    }else if(tipo=="Adams Ave"){
        cx= H_POSX_DI;
        cy = H_POSY1;
        sx=8823;
        sy=172.14;
        direccionX=-1;
        x_vel=1;
        cout<<"Entro Adams Ave"<<endl;

    }else{
        cx=H_POSX_ID;
        cy=H_POSY2;
        sx=206.31;
        sy=629;
        direccionX =1;
        x_vel=1;
    }
}

Autos* Calle::random(){
    //srand(time(NULL));
    int x = rand()%5;
    string tipo="";
    if(nombre == "Adams Ave" || nombre =="Creenshaw Ave"){
        tipo = tipo_carros[x];
    }else{
        tipo = tipo_carrosv[x];
    }
    cout<<tipo<<endl;
    Autos *c = new Autos(tipo.c_str());
    c->setCalle(nombre);
    c->setDireccion(direccionX,direccionY);
    c->setVelSegunCalle(x_vel,y_vel);
    float total=0;
    float suma=0;
    if(cola1->size()==0){
        c->setPosition(QPointF(cx,cy));
    }else{

        if(nombre == "Adams Ave"){
            suma = cola1->sumaWidth();
            total = suma+cx+5;
        }else if(nombre =="Creenshaw Ave"){
            suma = cola1->sumaWidth();
            total = cx-suma-5;
        }else if(nombre == "Maple St"){
            suma = cola1->sumaHeight();
            total = cy-suma-5;
        }else{
            suma = cola1->sumaHeight();
            total = cy+suma+5;
        }
        c->setPosition(QPointF(total,cy));
    }

    c->setTipo(tipo);

    if(direccionX<0 && (nombre == "Adams Ave" || nombre =="Creenshaw Ave")){
        c->flip(true,false);
    }else if(direccionY>0 && (nombre == "Maple St" || nombre =="Main St")){
        c->flip(false,true);
    }

    return c;
}
