#include "semaforoh.h"

SemaforoH::SemaforoH(const QString &Filename,QGraphicsItem *parent):MyItem(Filename,parent)
{
    imgs[0]=QString(":Rojo.png");
    imgs[1]=QString(":Naranja.png");
    imgs[2]=QString(":verde.png");
    imgsV[0]=QString(":RojoV.png");
    imgsV[1]=QString(":NaranjaV.png");
    imgsV[2]=QString(":verdeV.png");
    activo=false;
    tiempo=0;
    frame=0;
    img_actual=0;
    nombre="";

}

bool SemaforoH::getActivo()
{
 return activo;
}
void SemaforoH::activar(int t){
    activo =true;
    tiempo=t;
}
void SemaforoH::desactivar(){
    activo =false;
}

void SemaforoH::flipHorizontal(bool horizontal, bool vertical, int num){
    if(num ==1){
        int cont =0;
        while(cont<3){
            QImage img(imgs[cont]);

            QImage image = img.mirrored(horizontal, vertical);

            QPixmap pix = QPixmap::fromImage(image);
            imgsU[cont]=pix;
            cont++;
        }
    }else{
        int cont =0;
        while(cont<3){
            QImage img(imgsV[cont]);

            QImage image = img.mirrored(horizontal, vertical);

            QPixmap pix = QPixmap::fromImage(image);
            imgsU[cont]=pix;
            cont++;
        }
    }
}
void SemaforoH::setName(string name){
    this->nombre=name;

    if(nombre == "Creenshaw Ave"){
        flipHorizontal(false,true,2);
        setSize(QSizeF(imgsU[0].size().width(),imgsU[0].size().height()));
        setPosition(QPointF(200.0,503.0));
    }else if(nombre == "Maple St"){
        flipHorizontal(true,false,1);
        setSize(QSizeF(imgsU[0].size().width(),imgsU[0].size().height()));
        setPosition(QPointF(122.0,100.0));
    }else if(nombre == "Adams Ave"){
        imgsU[0]=QPixmap(imgsV[0]);
        imgsU[1]=QPixmap(imgsV[1]);
        imgsU[2]=QPixmap(imgsV[2]);
        setSize(QSizeF(imgsU[0].size().width(),imgsU[0].size().height()));
        setPosition(QPointF(822.77,45.0));
    }else{
        imgsU[0]=QPixmap(imgs[0]);
        imgsU[1]=QPixmap(imgs[1]);
        imgsU[2]=QPixmap(imgs[2]);
        setSize(QSizeF(imgsU[0].size().width(),imgsU[0].size().height()));
        setPosition(QPointF(840.0,515.0));
    }
    setVelocity(QPointF(0.0,0.0));
}

void SemaforoH::logica(){
    if(activo){
        switch (tiempo) {
        case 228 ... 2500:
            img_actual=2;
            break;
        case 1 ... 227:
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
    this->setPixmap(imgsU[img_actual]);
    frame++;
}

