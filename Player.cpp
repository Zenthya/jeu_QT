#include <Player.h>
#include<QDebug>
#include "projetile.h"
#include <QGraphicsScene>
#include <QGraphicsView>



void Player:: keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Z){

        Key[0]=10;
    }
     if(event->key()== Qt::Key_Q){
       Key[1]=10;
    }
     if(event->key()== Qt::Key_D){

        Key[2]=10;



        }
     if (event->key()== Qt::Key_S){
            Key[3]=10;

        }

    emit move();



}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Z){

        Key[0]=0;
    }
     if(event->key()== Qt::Key_Q){
       Key[1]=0;
    }
     if(event->key()== Qt::Key_D){

        Key[2]=0;



        }
     if (event->key()== Qt::Key_S){
            Key[3]=0;

        }
     emit move();

}

Player::Player(QGraphicsScene * Scene)
{

    setPos(400,300);
    setPixmap(QPixmap(":image/player.png"));
    setZValue(1);
    connect(Scene,SIGNAL(mousepressed()),this,SLOT(sourispressed()));





}


void Player::sourispressed(){
   // Weapon->fire(this);

}
void Player::move(){

        QPointF newpose = QPointF(x()+Key[2]-Key[1],y()+Key[3]-Key[0]);
        QPointF phantomePos = QPointF(newpose.x(),newpose.y()+32);
        Entity   * Phantom =new Entity(&phantomePos);
        scene()->addItem(Phantom);

        if(Phantom->CollisionDetector()==1){
            setPos(newpose);
        }


}
