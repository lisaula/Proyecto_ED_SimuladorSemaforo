#include "widget.h"
#include "menu.h"
#include <QApplication>

#include <stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();


    return a.exec();
}
