#ifndef LOG_H
#define LOG_H
#include "interseccion.h"
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QString>
#include <QWidget>

namespace Ui {
class Log;
}

class Log : public QWidget
{
    Q_OBJECT

public:
    void setInterseccion(Interseccion * i);
    void insertarLog();
    explicit Log(QWidget *parent = 0);
    ~Log();

private:
    Ui::Log *ui;
    Interseccion * i;
};

#endif // LOG_H
