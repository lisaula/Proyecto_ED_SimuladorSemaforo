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
    setVisible(false);

}

void Widget::insertarActores(){
    inter= new Interseccion("Rojo.png");
    mscene->addActor(inter);
}

Interseccion *Widget::getInterseccion()
{
    return inter;
}

Widget::~Widget()
{
    delete inter;
    delete mscene;
    delete thread;
    delete ui;
}
