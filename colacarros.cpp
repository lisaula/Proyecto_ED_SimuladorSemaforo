#include "colacarros.h"

ColaCarros::ColaCarros()
{
    root=NULL;
    end=NULL;
}

void ColaCarros::push(Autos *c){

    if(!root){
        root = new NodoCarro(c);
        end = root;
    }else{
        if(!desplazar(c)){
            end->sig=new NodoCarro(c);
            end->sig->ant=end;
            end=end->sig;
        }
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

bool ColaCarros::desplazar(Autos *c)
{
    if(c->prioridad){
        NodoCarro* s = new NodoCarro(c);
        s->sig=root;
        root->ant=s;
        root=s;
        return true;
    }
    return false;
}

float ColaCarros::sumaHeight()
{
    float suma=0;
    NodoCarro*  temp = root;
    while(temp){
        suma+=temp->carro->size().height();
        cout<<"Sumas "<<suma<<endl;
        temp=temp->sig;
    }
    return suma;
}

float ColaCarros::sumaWidth()
{
    float suma=0;
    NodoCarro*  temp = root;
    while(temp){
        suma+=temp->carro->size().width();
        cout<<"Sumas "<<suma<<endl;
        temp=temp->sig;
    }
    return suma;

}




