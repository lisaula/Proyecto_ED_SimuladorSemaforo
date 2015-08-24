#ifndef WIDGET_H
#define WIDGET_H
#include <iostream>
#include <QWidget>
#include "estrella.h"
#include <QImage>
#include "background.h"
#include"semaforoh.h"
#include "autos.h"
#include "colacarros.h"
#include "calle.h"
#include "cola.h"
#include "interseccion.h"
using namespace std;
namespace Ui {
class Widget;
}

class MyScene;
class MyThread;
class Widget : public QWidget
{
    Q_OBJECT

public:
    void insertarActores();
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:
    void update();

private:
    Ui::Widget *ui;
    Background* b;
    MyScene *mscene;
    MyThread *thread;
    QImage image;
    SemaforoH * semaH;
    Interseccion *inter;
};

#endif // WIDGET_H
