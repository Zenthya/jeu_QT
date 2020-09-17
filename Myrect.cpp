#include <Myrect.h>
#include<QDebug>
#include "projetile.h"
#include <QGraphicsScene>
#include <QGraphicsView>


void Myrect:: keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){

        setPos(x()-10,y());

    }
    else if(event->key()== Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Up){
            setPos(x(),y()-10);
        }
    else if (event->key()== Qt::Key_Down){
            setPos(x(),y()+10);

        }
    else if (event->key()==Qt::Key_Space){

        // le player tire
        //creation du thread porjectile
        projetile *bullet = new projetile(this);
        scene()->addItem(bullet);

    }
}

Myrect::Myrect(QGraphicsScene *Scene)
{
    setRect(0,0,100,100);
    setPos(x()+500,y()+400);
    connect(Scene,SIGNAL(mousepose(QPointF *)),this,SLOT(rotation(QPointF *)));


}

void Myrect::rotation(QPointF *pos)
{

    QPointF A =  QPointF(x(),y());
    QPointF B =  QPointF(x()+100,y());

    qreal AB = qSqrt(qPow((B.x()-A.x()),2)+qPow((B.y()-A.y()),2)) ;
    qreal BS = qSqrt(qPow(-B.x()+pos->x(),2)+qPow(-B.y()+pos->y(),2));
    qreal AS = qSqrt(qPow(-A.x()+pos->x(),2)+qPow(-A.y()+pos->y(),2));

    qreal angle =qAcos((-qPow(BS,2)+qPow(AB,2)+qPow(AS,2))/(2*AB*AS));
    setRotation(qRadiansToDegrees(angle));


}
