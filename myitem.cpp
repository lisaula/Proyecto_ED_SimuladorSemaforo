#include "myitem.h"
#include<QPainter>
MyItem::MyItem(const QString &Filename,QGraphicsItem *parent): QGraphicsItem(parent)
{
    mFilename = Filename;
    pixmap= QPixmap(mFilename);

}

QRectF MyItem::boundingRect() const
{
    return QRectF(mPos.x(),mPos.y(),mSize.width(),mSize.height());
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                   QWidget *)
{
    painter->drawPixmap(mPos.x(), mPos.y(), mSize.width(),mSize.height(),
                           pixmap);
}
void MyItem::setPixmap(QPixmap p){
    pixmap = p;
}
