#include "scenemoussed.h"
#include <QDebug>
scenemoussed::scenemoussed(QObject *parent): QGraphicsScene(parent)
{
    setSceneRect(0,0,1080,800);
}

void scenemoussed::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<"postion sortant de la scene"<< event->scenePos();
    QPointF mouse = event->scenePos();


    emit mousepose(&mouse);

}
