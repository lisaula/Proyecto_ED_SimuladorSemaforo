#include "calle.h"

Calle::Calle(string name)
{
    nombre = name;
    setearPosiciones(name);
}

void Calle::agregarCarro(MyScene* scn)
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

    }else if(tipo=="Maple St"){
        sx=122.0;
        sy=100.0;
        cx=V_POSX1;
        cy=V_POSY_AB;

    }else if(tipo=="Adams St"){
        cx= H_POSX_ID;
        cy = H_POSY1;
        sx=8823;
        sy=172.14;

    }else{
        cx=H_POSX_DI;
        cy=H_POSY2;
        sx=206.31;
        sy=629;
    }
}

Autos* Calle::random(){
    srand(time(NULL));
    string tipo = tipo_carros[rand()%6];
    Autos *c = new Autos(tipo.c_str());
    return c;
}
