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
    inter= new Interseccion("Rojo.png");
    mscene->addActor(inter);
    //inter->setScene(mscene);
//    inter->main->agregarCarro();
//    inter->adams->agregarCarro();

//    Autos*a = inter->main->cola1->first();
//    Autos*b = inter->adams->cola1->first();
//    int x = inter->getDistance(a,b);
//    inter->carros_pasando->push(a);
//    inter->carros_pasando->push(b);
//    Autos *ca= inter->carros_pasando->buscar(0);
//    cout<<a->tipo<<ca->tipo<<endl;
//    cout<<b->tipo<<endl;
//    Autos *coli= inter->ValidarMasCerca(b);

//    cout<<"Distacia: "<<x<<endl;
//    cout<<b->tipo<<" colisione con "<<coli->tipo<<endl;

//        ColaCarros* cola = new ColaCarros(":Rojo.png");
//        Autos *car = new Autos(":turismo.png");
//        car->setCalle("Adams Ave");
//                car->setDireccion(-1,1);
//                car->setVelSegunCalle(1,0);
//                car->setTipo(":turismo.png");

//                cola->push(car);
//        mscene->addActor(cola);
//    Calle * calle = new Calle(":Rojo.png");
//    calle->setearTipo("Maple St");

//    calle->agregarCarro();
//    calle->agregarCarro();
//    calle->activarSemaforo(1000);
//    mscene->addActor(calle);
//    cout<<calle->cola1->first()->tipo<<endl;
//    cout<<calle->cola1->root->carro->tipo<<endl;

//    //calle->activarSemaforo(1000);
//    calle->agregarCarro();
//    calle->agregarCarro();
//    calle->agregarCarro();
//    calle->agregarCarro();


    //Estrella* e = new Estrella(":green.png");
//    e->setPosition(QPointF(500.0,100.0));
//    e->setVelocity(QPointF(0,0));
//    e->setSize(QSizeF(50.0,50.0));
//    semaH= new SemaforoH(":Rojo.png");
//    semaH->setName("Creenshaw Ave");

//    semaH->setVelocity(QPointF(0.0,0.0));
//    //semaH->setSize(QSizeF(95.0,41.0));
//    semaH->activar(1000);
    //mscene->addActor(semaH);
////    Autos * tur = new Autos(":turismo");
////    tur->setTipo("turismo");
//    ColaCarros * cola = new ColaCarros("Creenshaw Ave");
//    Autos * tur = new Autos(":ambulancia.png");



//    Autos * cam = new Autos(":camion.png");
//    cola->push(cam);
//    cola->push(tur);

//    mscene->addActor(e);
//    mscene->addActor(semaH);
//    Autos* turis= new Autos(":turismo.png");
//    //maple 445,130
//    //creen 230,434
//        //turis->setPosition(QPointF(230,434.5));
//        Autos* cam= new Autos(":camion.png");
//        Autos* amb= new Autos(":ambulancia.png");
//        turis->setCalle("Adams Ave");
//        turis->setDireccion(-1,1);
//        turis->setVelSegunCalle(1,0);
//        turis->setTipo(":turismo.png");

//        //cam->setPosition(QPointF(888,200.5));
//        cam->setCalle("Adams Ave");
//        cam->setDireccion(-1,1);
//        cam->setVelSegunCalle(1,0);
//        cam->setTipo(":camion.png");

//        //amb->setPosition(QPointF(988,200.5));
//        amb->setCalle("Adams Ave");
//        amb->setDireccion(-1,1);
//        amb->setVelSegunCalle(1,0);
//        amb->setTipo(":ambulancia.png");
    //    cout<<amb->prioridad<<endl;

//    turis->setVelocity(QPointF(1.0,1.0));


////    mscene->addActor(turis);
////    mscene->addActor(cam);
////    mscene->addActor(amb);


//    Cola *col= new Cola(":turismo.png");
//    col->setName("Creenshaw Ave");
//    col->push(turis);
//    cout<<col->first()->tipo<<endl;
//    mscene->addActor(col);
//    col->push(cam);
//    cout<<col->first()->tipo<<endl;
//    col->push(amb);
//    cout<<col->first()->tipo<<endl;
////    cout<<col->root->sig->carro->tipo<<endl;
////    cout<<col->root->sig->sig->carro->tipo<<endl;
//    mscene->addActor(col->pop());
//    cout<<col->first()->tipo<<endl;
//        Autos* turis2= new Autos(":turismo.png");
//        turis2->setCalle("Adams Ave");
//        turis2->setDireccion(-1,1);
//        turis2->setVelSegunCalle(1,0);
//        turis2->setTipo(":turismo.png");
//        col->push(turis2);

//    cout<<"X: "<<turis->position().x()<<"Y: "<<turis->position().y()<<endl;
}

Widget::~Widget()
{
    delete ui;
}
