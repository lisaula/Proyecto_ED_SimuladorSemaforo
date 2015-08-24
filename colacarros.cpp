#include "colacarros.h"

ColaCarros::ColaCarros(const QString &Filename,QGraphicsItem *parent):MyItem(Filename,parent)
{
    root=NULL;
    end=NULL;
    vacio = 0;
}

ColaCarros::~ColaCarros()
{
    delete root;
    delete end;
}

void ColaCarros::push(Autos *c){

    if(!root){
        root = new NodoCarro(c);
        end = root;
    }else{
            end->sig=new NodoCarro(c);
            //end->sig->ant=end;
            end=end->sig;
    }
}

void ColaCarros::estaVacio()
{
    NodoCarro* temp = root;
    int cont=0;
    while(temp){
        Autos* c = temp->carro;
        if(c->tipo==":bus.png"){
            cont++;
        }
        temp = temp->sig;
    }
    vacio=size()-cont;
    if(vacio<0){
        vacio=0;
    }
}

Autos* ColaCarros::pop(){
    if(!root)
        return NULL;

    NodoCarro* temp = root;
    root = root->sig;
    temp->ant=NULL;
    temp->sig=NULL;
    Autos *t =temp->carro;
    return t;
}

Autos* ColaCarros::first(){
    return root->carro;
}

void ColaCarros::verificarSalio()
{
    NodoCarro* temp = root;
    while(temp){
        Autos* c = temp->carro;
        if(c->salio){
            eliminar(c);
        }
        temp = temp->sig;
    }
}

void ColaCarros::eliminar(Autos *carro)
{
    if(root){
        if(root->carro->tipo==carro->tipo){
            NodoCarro* temp = root;
            root = temp->sig;
            delete temp;
        }else{
            NodoCarro* temp = root;
            while(temp){
                if(temp->sig!=NULL && temp->sig->carro->tipo==carro->tipo){
                    NodoCarro* t = temp->sig;
                    temp->sig = t->sig;
                    delete t;break;
                }else{
                    temp = temp->sig;
                }
            }
        }
    }
}

void ColaCarros::logica()
{
    NodoCarro* temp = root;
    while(temp){
        Autos* c = temp->carro;
        //painter->drawPixmap(c->position().x(),c->position().y(), c->size().width(),c->size().height(),
                               //c->getPixmap());
        c->logica();
        temp = temp->sig;
    }
    estaVacio();
}

void ColaCarros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    NodoCarro* temp = root;
    while(temp){
        Autos* c = temp->carro;
        //painter->drawPixmap(c->position().x(),c->position().y(), c->size().width(),c->size().height(),
                               //c->getPixmap());
        c->paint(painter, option, widget);
        temp = temp->sig;
    }
}


void ColaCarros::limpiar(){
    if(root){
        pop();
        limpiar();
    }
}


void ColaCarros::anular(){
    if(root){
        delete pop();
        anular();
    }
}

int ColaCarros::size(){
    int cont=0;
    NodoCarro *temp = root;
    while(temp){
        temp=temp->sig;
        cont++;
    }
    return cont;
}

Autos *ColaCarros::buscar(int c)
{
    NodoCarro *temp = root;
    int cont=0;
    while(temp){
        if(cont==c){
            return temp->carro;
        }
        temp=temp->sig;
        cont++;
    }
    return NULL;
}




