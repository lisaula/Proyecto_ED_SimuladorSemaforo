#include "interseccion.h"

Interseccion::Interseccion(const QString &Filename,QGraphicsItem *parent): MyItem(Filename, parent)
{
    main = new Calle("Rojo.png");
    main->setearTipo("Main St");
    maple= new Calle("Rojo.png");
    maple->setearTipo("Maple St");
    creenshow= new Calle("Rojo.png");
    creenshow->setearTipo("Creenshaw Ave");
    adams= new Calle("Rojo.png");
    adams->setearTipo("Adams Ave");
    frame=0;
    srand(NULL);
    scn= NULL;
    carros_pasando=new ColaCarros(Filename);
    colision=false;
    pila= new Pila();
}
void Interseccion::logica()
{
    frame++;
    if(!colision){
        main->logica();
        maple->logica();
        creenshow->logica();
        adams->logica();
        carros_pasando->logica();
        if(frame%750==0){
            main->agregarCarro();
            main->agregarCarro2();
        }else if(frame%800==0){
            maple->agregarCarro();
            maple->agregarCarro2();
        }

        if(frame%1000==0){
            creenshow->agregarCarro();
            creenshow->agregarCarro2();
        }else if(frame%1500==0){
            adams->agregarCarro();
            adams->agregarCarro2();
        }
        validarSemaforos();
        liberarAutos();
        ValidarBusSegunCalle();
        carros_pasando->verificarSalio();
    }else{

        pila->push("bus.png colisiono con "+colisiono->tipo);
        if(frame%800==0){
            colision=false;
            carros_pasando->anular();
        }
    }

}

void Interseccion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    main->paint(painter,option,widget);
    maple->paint(painter,option,widget);
    creenshow->paint(painter,option,widget);
    adams->paint(painter,option,widget);
    carros_pasando->paint(painter,option,widget);
}

void Interseccion::setScene(MyScene* scene)
{
    scn= scene;
}

void Interseccion::liberarAutos()
{
    if(carros_pasando->vacio==0){
        if(main->sema->getActivo()){
            if(main->cola1->size()>0){
                Autos *carro= main->cola1->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
            if(main->cola2->size()>0){
                Autos *carro= main->cola2->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }

        }
        if(maple->sema->getActivo()){
            if(maple->cola1->size()>0){
                Autos *carro= maple->cola1->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
            if(maple->cola2->size()>0){
                Autos *carro= maple->cola2->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
        }
        if(creenshow->sema->getActivo()){
            if(creenshow->cola1->size()>0){
                Autos *carro= creenshow->cola1->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
            if(creenshow->cola2->size()>0){
                Autos *carro= creenshow->cola2->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
        }
        if(adams->sema->getActivo()){
            if(adams->cola1->size()>0){
                Autos *carro= adams->cola1->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
            if(adams->cola2->size()>0){
                Autos *carro= adams->cola2->pop();
                carro->cruzar(true);
                carros_pasando->push(carro);
            }
        }
    }

}

void Interseccion::validarSemaforos()
{
    if(!main->sema->getActivo() && !maple->sema->getActivo()){
        creenshow->validarSema2();
        if(creenshow->activado){
            adams->sema->activar(creenshow->sema->tiempo);
            return;
        }
        adams->validarSema2();
        if(adams->activado){
            creenshow->sema->activar(adams->sema->tiempo);
            return;
        }
    }
    if(!adams->sema->getActivo() && !creenshow->sema->getActivo()){
        main->validarSema2();
        if(main->activado){
            maple->sema->activar(main->sema->tiempo);
            return;
        }
        maple->validarSema2();
        if(maple->activado){
            main->sema->activar(maple->sema->tiempo);
            return;
        }
    }
}

void Interseccion::validarBus(Calle *calle)
{
    if(calle->cola1->size()>0){
        Autos *carro2=calle->cola1->first();
        if(carro2->tipo==":bus.png"){
            if(carro2->randonm()){
                Autos * t=calle->cola1->pop();
                t->cruzar(true);
                carros_pasando->push(t);
                colision=true;
                colisiono= ValidarMasCerca(t);
            }
        }
    }
    if(calle->cola2->size()>0){
        Autos *carro2=calle->cola2->first();
        if(carro2->tipo==":bus.png"){
            if(carro2->randonm()){
                Autos * t=calle->cola2->pop();
                t->cruzar(true);
                carros_pasando->push(t);
                colision=true;
                colisiono= ValidarMasCerca(t);
            }
        }
    }
}

void Interseccion::ValidarBusSegunCalle()
{
    if(!main->sema->getActivo()){
        validarBus(main);
    }
    if(!maple->sema->getActivo()){
        validarBus(maple);
    }
    if(!creenshow->sema->getActivo()){
        validarBus(creenshow);
    }
    if(!adams->sema->getActivo()){
        validarBus(adams);
    }
}

Autos *Interseccion::ValidarMasCerca(Autos *c)
{
    NodoCarro *temp = carros_pasando->root;
    int n=carros_pasando->size();
    float posiciones[n];
    int cont=0;
    while(cont<n){
        Autos*carro = temp->carro;
        if(carro->calle==c->calle || carro->calle==c->opuesto){
            posiciones[cont]=-1;

        }else{
        posiciones[cont]=getDistance(c,carro);

        }
        cont++;
        temp=temp->sig;
        cout<<"Salio primer while"<<endl;
    }
    cont=0;
    int pos=0;
    int menor=5000;
    while(cont<n){
        if(posiciones[cont]>0){
            if(posiciones[cont]<menor){
                menor=posiciones[cont];
                pos=cont;
            }
        }
        cont++;
        cout<<"Salio segundo while"<<endl;
    }

    Autos* cercano = carros_pasando->buscar(pos);
    return cercano;

}



int Interseccion::getDistance(Autos *a, Autos *b)
{
    float ax = a->position().x(), ay=a->position().y();
    float bx=b->position().x(), by=b->position().y();
    int cont=0;
    while(ax!= bx && ay != by){
        if(ax!=bx){
            if(ax>bx){
                bx++;
            }else{
                ax++;
            }
        }
        if(ay!=by){
            if(ay>by){
                by++;
            }else{
                ay++;
            }
        }
        cont++;
    }
    return cont;
}

