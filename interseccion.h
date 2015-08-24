#ifndef INTERSECCION_H
#define INTERSECCION_H
#include "calle.h"
#include "myscene.h"
#include "myitem.h"
#include "background.h"
#include "colacarros.h"
#include "pila.h"
class Interseccion : public MyItem
{
public:
    ColaCarros* carros_pasando;
    Calle *main,*maple,*creenshow,*adams;
    Pila* pila;
    void cruzar();
    Interseccion(const QString &Filename,QGraphicsItem *parent=nullptr);
    MyScene* getScene();
    void logica();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);
    void setScene(MyScene *);
    void liberarAutos();
    void validarSemaforos();
    void validarBus(Calle* calle);
    void ValidarBusSegunCalle();
    Autos* ValidarMasCerca(Autos*c);
    int getDistance(Autos*,Autos*);
private:
    int frame;
    MyScene *scn;
//    ColaCarros* carros_pasando;
    bool colision;
    Autos* colisiono;

};

#endif // INTERSECCION_H
