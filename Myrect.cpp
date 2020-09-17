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
    else if (event->key()==Qt::Key_Space ){


        projetile *bullet = new projetile(this,&poseSouris);
         scene()->addItem(bullet);

    }




}

Myrect::Myrect(QGraphicsScene *Scene)
{
    setRect(0,0,100,100);
    setPos(x()+500,y()+400);

    connect(Scene,SIGNAL(mousepose(QPointF *)),this,SLOT(rotation(QPointF *)));



}
void Myrect::rotation(QPointF*pos){

   poseSouris = *pos ;



}
