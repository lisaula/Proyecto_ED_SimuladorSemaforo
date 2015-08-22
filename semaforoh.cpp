#include "semaforoh.h"

SemaforoH::SemaforoH(const QString &Filename,QGraphicsItem *parent):MyItem(Filename,parent)
{
    imgs.push_back(QPixmap(Filename));
    imgs.push_back(QString(":Naranja.png"));
    imgs.push_back(QString(":verde.png"));
    activo=false;
    tiempo=0;
    frame=0;
    img_actual=0;

}
void SemaforoH::activar(int t){
    activo =true;
    tiempo=t;
}
void SemaforoH::desactivar(){
    activo =false;
}

void SemaforoH::flipHorizontal(){
    QPixmap r1=imgs[0],r2=imgs[1],r3=imgs[2];
    QImage i= r1.toImage(), i2=r2.toImage(),i3=r3.toImage();
    i.scaled(QSize(-1,0));
    i2.scaled(QSize(-1,0));
    i3.scaled(QSize(-1,0));
    imgs[0].fromImage(i);
    imgs[1].fromImage(i2);
    imgs[2].fromImage(i3);
}

void SemaforoH::logica(){
    if(activo){
        switch (tiempo) {
        case 300 ...10000:
            img_actual=2;
            break;
        case 1 ... 299:
            img_actual=1;
            break;
        default:
            img_actual=0;
            activo=false;
            tiempo=0;
            break;
        }
        tiempo--;
    }
    this->setPixmap(imgs[img_actual]);
    frame++;
}

