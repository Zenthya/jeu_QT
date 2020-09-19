#include "scenemoussed.h"
#include <QDebug>
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
