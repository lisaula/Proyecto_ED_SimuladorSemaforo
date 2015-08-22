#ifndef SEMAFOROH_H
#define SEMAFOROH_H
#include "myitem.h"
#include <vector>
#include<iostream>
using namespace std;
class SemaforoH :public MyItem
{
public:

    void activar(int t);
    void desactivar();
    void logica();
    void flipHorizontal();
    vector<QPixmap>imgs;
    SemaforoH(const QString &Filename,QGraphicsItem *parent=nullptr);
private:
    bool activo;
    int tiempo;
    int img_actual;int frame;
};

#endif // SEMAFOROH_H
