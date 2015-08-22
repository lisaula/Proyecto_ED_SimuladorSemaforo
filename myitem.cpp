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

void MyItem::flip(bool horizontal, bool vertical)
{
    QImage img(mFilename);

    QImage image = img.mirrored(horizontal, vertical);

    QPixmap pix = QPixmap::fromImage(image);
    setPixmap(pix);
}

void MyItem::rotate(int r)
{
    QTransform transform;
    QTransform trans = transform.scale(sqrt(pixmap.size().width()), sqrt(pixmap.size().height()));
    trans = transform.rotate(r);

    QPixmap transPixmap = QPixmap(pixmap.transformed(trans));
    setPixmap((transPixmap));
}
