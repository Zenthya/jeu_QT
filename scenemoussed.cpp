#include "scenemoussed.h"
#include <QDebug>
#include <QPainter>
scenemoussed::scenemoussed(QObject *parent): QGraphicsScene(parent)
{
    setSceneRect(0,0,10800,7200);
    setStickyFocus(true);
}

void scenemoussed::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<"postion sortant de la scene"<< event->scenePos();
    QPointF mouse = event->scenePos();


    emit mousepose(&mouse);

}


void scenemoussed::mousePressEvent(QGraphicsSceneMouseEvent *event){


    emit mousepressed();
}

void scenemoussed::drawBackground(QPainter *Painter,const QRectF  &rect)
{
    this->addPixmap(QPixmap(":image/player"));
    Painter->drawPixmap(QPointF(150,300),QPixmap(":image/player"));
}
