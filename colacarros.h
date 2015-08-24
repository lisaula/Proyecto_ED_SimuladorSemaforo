#ifndef COLACARROS_H
#define COLACARROS_H
#include "nodocarro.h"
#include "myitem.h"

class ColaCarros :public MyItem
{
public:
    NodoCarro *root, *end;
    int vacio;
    void push(Autos *c);
    void estaVacio();
    Autos* pop();
    Autos* first();
    void verificarSalio();
    void eliminar(Autos*);
    void logica();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);
    void limpiar();
    void anular();
    int size();
    Autos* buscar(int);
    ColaCarros(const QString &Filename,QGraphicsItem *parent=nullptr);
};

#endif // COLACARROS_H
