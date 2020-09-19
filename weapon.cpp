#include "weapon.h"
#include<QDebug>




Weapon::Weapon(QGraphicsScene *Scene)
{
      connect(Scene,SIGNAL(mousepose(QPointF *)),this,SLOT(souris(QPointF *)));

      this->Scene=Scene;
}


 void Weapon::souris(QPointF * souris){


    sourispose=*souris;


}
void Weapon::fire(QGraphicsPixmapItem *){

    qDebug("désarmé");
}

 Bow::Bow(QGraphicsScene *Scene):Weapon(Scene){

 }
 void Bow::fire(QGraphicsPixmapItem *player){

     projetile  * arrow= new projetile(player,&sourispose) ;
     Scene->addItem(arrow);


 }
