#ifndef SEMAFOROH_H
#define SEMAFOROH_H
#include "myitem.h"
#include<iostream>
using namespace std;
class SemaforoH :public MyItem
{
public:

    int tiempo;
    void activar(int t);
    void desactivar();
    void logica();
    void flipHorizontal(bool, bool, int n);
    void setName(string nombre);
    QString imgs[3];
    QString imgsV[3];
    QPixmap imgsU[3];
    SemaforoH(const QString &Filename,QGraphicsItem *parent=nullptr);
    bool getActivo();
private:
    string nombre;
    bool activo;
    int img_actual;int frame;
};

#endif // SEMAFOROH_H
