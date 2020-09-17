#include <Player.h>
#include<QDebug>
#include "projetile.h"
#include <QGraphicsScene>
#include <QGraphicsView>



void Player:: keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){

        setOffset(offset().x()-10,offset().y());

    }
     if(event->key()== Qt::Key_Right){
        setOffset(offset().x()+10,offset().y());
    }
     if(event->key()== Qt::Key_Up){
            setOffset(offset().x(),offset().y()-10);
        }
     if (event->key()== Qt::Key_Down){
            setOffset(offset().x(),offset().y()+10);

        }
     if (event->key()==Qt::Key_Space ){


        projetile *bullet = new projetile(this,&poseSouris);
         scene()->addItem(bullet);


    }




}

Player::Player(QGraphicsScene *Scene)
{

    setOffset(500,400);
    setPixmap(QPixmap(":image/player.png"));
    setZValue(1);
    connect(Scene,SIGNAL(mousepose(QPointF *)),this,SLOT(rotation(QPointF *)));



}
void Player::rotation(QPointF*pos){

   poseSouris = *pos ;



}
