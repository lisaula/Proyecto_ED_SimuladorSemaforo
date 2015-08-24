#include "log.h"
#include "ui_log.h"

Log::Log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
}

void Log::setInterseccion(Interseccion * i){
    this->i=i;
    insertarLog();
}

void Log::insertarLog()
{
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString texto = i->pila->imprimir();
    text->setText(texto);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

Log::~Log()
{
    delete i;
    delete ui;

}
