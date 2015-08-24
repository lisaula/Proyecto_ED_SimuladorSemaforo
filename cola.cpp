#include "cola.h"
Cola::Cola(const QString &Filename,QGraphicsItem *parent): MyItem (Filename, parent)
{
    root=NULL;
    end=NULL;
    pasar=false;
    poped=false;
    frame=0;
}

void Cola::logica()
{
    frame++;
    NodoCarro* temp = root;
    while(temp){
        Autos* c = temp->carro;
        //painter->drawPixmap(c->position().x(),c->position().y(), c->size().width(),c->size().height(),
                               //c->getPixmap());
        c->logica();
        temp = temp->sig;
        if(frame%500==0)
        popeo();
    }
//    if(frame%500==0)
//        popeo();
}

void Cola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

Cola::~Cola()
{
    delete root;
    delete end;
}

void Cola::popeo()
{
    if(poped){
        int n=size();
        if(n>0){
            NodoCarro* pri=root;
            pri->carro->setPosition(QPointF(cx,cy));
            n-=1;
            while(n){
                QPointF old = QPointF(pri->carro->position().x(),pri->carro->position().y());
                pri->sig->carro->setPosition(old);
                pri=pri->sig;
                n--;
            }
        }
    }
    poped=false;
}

void Cola::activarPasar(bool a)
{
    NodoCarro * temp= root;
    while(temp){
        temp->carro->cruzar(a);
        temp=temp->sig;
    }
}

void Cola::setName(string name)
{
    this->nombre = name;
    if(nombre == "Creenshaw Ave"){
        cx=H_POSX_ID;
        cy=H_POSY2;
    }else if(nombre == "Adams Ave"){
        cx= H_POSX_DI;
        cy = H_POSY1;
    }else if(nombre == "Main St"){
        cx=V_POSX2;
        cy=V_POSY_BA;
    }else{
        cx=V_POSX1;
        cy=V_POSY_AB;
    }
}

void Cola::push(Autos *c){

    if(!root){
        c->setPosition(QPointF(cx,cy));
        root = new NodoCarro(c);
        end = root;
    }else{
        int si = size();
        if(c->prioridad==true){
            tomarPosicion(c,root->carro);
            desplazar(c);
            InFirst(c);
        }else{
        setearPos(c);
        end->sig=new NodoCarro(c);
        end->sig->ant=end;
        end=end->sig;
        }
    }
}

Autos* Cola::pop(){
    if(!root)
        return NULL;

    NodoCarro* temp = root;
    root = root->sig;
    temp->ant=NULL;
    temp->sig=NULL;
    Autos *t =temp->carro;
    poped=true;
    return t;
}

Autos* Cola::first(){
    return root->carro;
}

Autos* Cola::getsegunpos(int p)
{
    NodoCarro* nodo= root;
    int s=size();
    int cont=0;
    while(s>0){
        cont++;
        if(p==cont)
            return nodo->carro;

        nodo= nodo->sig;
        s--;
    }
}

void Cola::setearPos(Autos *c)
{
    Autos* ult = end->carro;
    float x= ult->position().x();
    float y= ult->position().y();
    float h=c->size().height()+5;
    float w=c->size().width()+5;
    if(nombre=="Creenshaw Ave"){
        c->setPosition(QPointF(x-w-10,y));
    }else if(nombre =="Adams Ave" ){
        c->setPosition(QPointF(x+ult->size().width()+5,y));
    }else if(nombre == "Main St"){
        cout<<"Entrp setearpos Main"<<endl;
        c->setPosition(QPointF(x,y+h));
    }else{
        cout<<"Entrp setearpos maple"<<endl;
        c->setPosition(QPointF(x,y-ult->size().height()-5));
    }
}

void Cola::tomarPosicion(Autos *a, Autos *c)
{
    a->setPosition(c->position());
}

void Cola::limpiar(){
    if(root){
        pop();
        limpiar();
    }
}


void Cola::anular(){
    if(root){
        delete pop();
        anular();
    }
}

int Cola::size(){
    int cont=0;
    NodoCarro *temp = root;
    while(temp){
        temp=temp->sig;
        cont++;
    }
    return cont;
}

bool Cola::InFirst(Autos *c)
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

void Cola::desplazar(Autos* c)
{
    float w= c->size().width()+5;
    float h= c->size().height()+5;
    int si = size();
    if(nombre=="Creenshaw Ave"){

        while(si>0){
            Autos* c=getsegunpos(si);
            c->setPosition(QPointF(c->position().x()-w,c->position().y()));
            si--;
        }
    }else if(nombre == "Adams Ave"){
        while(si>0){
            Autos* c=getsegunpos(si);
            cout<<c->tipo<<endl;
            c->setPosition(QPointF(c->position().x()+w,c->position().y()));
            si--;
        }
    }else if(nombre == "Main St"){
        while(si>0){
            Autos* c=getsegunpos(si);
            c->setPosition(QPointF(c->position().x(),c->position().y()+h));
            si--;
        }
    }else{
        while(si>0){
            Autos* c=getsegunpos(si);
            c->setPosition(QPointF(c->position().x(),c->position().y()-h));
            si--;
        }
    }
}




