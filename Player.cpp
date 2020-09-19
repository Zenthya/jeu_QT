#include <Player.h>
#include<QDebug>
#include "projetile.h"
#include <QGraphicsScene>
#include <QGraphicsView>



void Player:: keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Left){

        setPos(x()-10,y());
    }
     if(event->key()== Qt::Key_Right){
        setPos(x()+10,y());
    }
     if(event->key()== Qt::Key_Up){

            setPos(x(),y()-10);

            QPointF phantome = QPointF(x(),y()+32);
            Entity   * pipi =new Entity(&phantome);
            scene()->addItem(pipi);
            qDebug()<<pipi->CollisionDetector();

        }
     if (event->key()== Qt::Key_Down){
            setPos(x(),y()+10);

        }





}

Player::Player(QGraphicsScene * Scene)
{

    setPos(400,300);
    setPixmap(QPixmap(":image/player.png"));
    setZValue(1);
    connect(Scene,SIGNAL(mousepressed()),this,SLOT(sourispressed()));





}


void Player::sourispressed(){
    Weapon->fire(this);

}
