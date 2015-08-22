#include "widget.h"
#include "ui_widget.h"
#include "myscene.h"
#include "mythread.h"

#define MSEC 10
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mscene = new MyScene(this);
    thread = new MyThread(this);
    b=new Background(":Background.png");
    mscene->addActor(b);
    insertarActores();
    ui->graphicsView->setScene(mscene);

    layout()->setMargin(0);

    connect(thread,&MyThread::already,[&]() {emit update();});
    connect(this, &Widget::update, mscene, &MyScene::onUpdate);
    thread->start(MSEC,QThread::HighestPriority);
    cout<<this->size().width()<<endl;
    cout<<this->size().height()<<endl;

}

void Widget::insertarActores(){
    Estrella* e = new Estrella(":green.png");
    e->setPosition(QPointF(0.0,0.0));
    e->setVelocity(QPointF(1.0,1.0));
    e->setSize(QSizeF(50.0,50.0));
    e->Invertir();
    semaH= new SemaforoH(":Rojo.png");
    semaH->setPosition(QPointF(122.0,100.0));
    semaH->setVelocity(QPointF(0.0,0.0));
    semaH->setSize(QSizeF(95.0,41.0));
    semaH->flipHorizontal();
    semaH->activar(1000);
//    Autos * tur = new Autos(":turismo");
//    tur->setTipo("turismo");
    ColaCarros * cola = new ColaCarros();
    Autos * tur = new Autos(":ambulancia.png");



    Autos * cam = new Autos(":camion.png");
    cola->push(cam);
    cola->push(tur);
    cout<<cola->first()->tipo<<endl;
    cout<<cola->root->sig->carro->tipo<<endl;

    mscene->addActor(e);
    mscene->addActor(semaH);
    mscene->addActor(cola->first());
    mscene->addActor(cola->root->sig->carro);
    cola->pop();
    cout<<cola->first()->tipo<<endl;


}

Widget::~Widget()
{
    delete ui;
}
