#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>
#include<QPointF>
#include <QSizeF>
#include <QPixmap>

class MyItem : public QGraphicsItem
{
public:
    QPixmap pixmap;
    MyItem(const QString &Filename,QGraphicsItem *parent=nullptr);
    inline void setPosition(const QPointF &pos);
    inline void setVelocity(const QPointF &vel);
    inline void setSize(const QSizeF &size);
    inline void setVelMax(const QPointF &r);
    inline QPointF position() const;
    inline QPointF velocity() const;
    inline QSizeF size() const;
    inline QString filename() const;
    virtual void logica()=0;
    QPixmap getPixmap(){
        return pixmap;
    }
    void setPixmap(QPixmap p);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);
private:
    QPointF mPos;
    QPointF mVel;
    QSizeF mSize;
    QPointF vel_max;
    QString mFilename;
};

void MyItem::setPosition(const QPointF &pos)
{
    mPos = pos;
}

void MyItem::setVelocity(const QPointF &vel)
{
//    float vx =vel.x(),vy=vel.y();
//    float vx_max=vel_max.x(),vy_max=vel_max.y();
//    if(vx<0)vx*-1;if(vx_max<0)vx_max*-1;if(vy_max<0)vy_max*-1;if(vy<0)vy*-1;
//    if(vx>=vx_max || vy>=vy_max){
//        mVel=vel_max;
//    }else{
//        mVel = vel;
//    }
      mVel=vel;
}

void MyItem::setSize(const QSizeF &size)
{
    mSize = size;
}

void MyItem::setVelMax(const QPointF &r)
{
    vel_max=r;
}

QPointF MyItem::position() const
{
    return mPos;
}

QPointF MyItem::velocity() const
{
    return mVel;
}

QSizeF MyItem::size() const
{
    return mSize;
}

QString MyItem::filename() const
{
    return mFilename;
}

#endif // MYITEM_H
