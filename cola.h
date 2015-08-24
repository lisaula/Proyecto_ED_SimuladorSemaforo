#ifndef COLA_H
#define COLA_H
#include "nodocarro.h"
#include "myitem.h"
#include <QPainter>


class Cola : public MyItem
{
public:
    bool pasar, poped;
    void popeo();
    void activarPasar(bool);
    NodoCarro *root, *end;
    string nombre;
    void setName(string name);
    void push(Autos *c);
    Autos* pop();
    Autos* first();
    Autos* getsegunpos(int p);
    void setearPos(Autos*);
    void tomarPosicion(Autos*,Autos*);
    void limpiar();
    void anular();
    int size();
    bool InFirst(Autos *c);
    void desplazar(Autos*);
    void desplazarAnt(Autos* c);
    Cola(const QString &Filename,QGraphicsItem *parent=nullptr);
    void logica();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);
    ~Cola();
private:
    int cx,cy,frame;
};

#endif // COLA_H
