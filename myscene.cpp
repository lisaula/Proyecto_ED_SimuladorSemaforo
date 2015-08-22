#include "myscene.h"
#include "myitem.h"
#include "defines.h"


MyScene::MyScene(QObject *parent)
    :QGraphicsScene(XPOS,YPOS,WIDTH,HEIGHT, parent)
{
    addRect(XPOS,YPOS,WIDTH,HEIGHT,QPen(Qt::black));
    frame =0;
}

void MyScene::onUpdate()
{
    for(int x=0;x<actores.size();x++){
        actores[x]->logica();
    }
    frame++;
    update();
}

void MyScene::addActor(MyItem *actor){
    actores.push_back(actor);
    addItem(actor);
}

