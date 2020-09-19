#include "projetile.h"
#include <QDebug>
#include <QVector2D>
#include <QtMath>
#include <wall_face.h>
#include <QGraphicsScene>

projetile::projetile(QGraphicsPixmapItem *Rect,QPointF * Souris)
{
    setOffset(Rect->x()+2,Rect->y()+17);
    // calcul des mouvement a effectuer pour le projectile
    qreal vitesse = 10 ;

    qreal S =(Rect->x()-Souris->x()) ;
    qreal P =(Rect->y()-Souris->y()) ;
    qreal normeSP =qSqrt((S*S)+(P*P));

     YPos = (P/normeSP)*vitesse;
     XPos = (S/normeSP)*vitesse;

      qreal angle = qRadiansToDegrees(qAtan2(P,S)) -90;
    setRotation(angle);
    setTransformOriginPoint(Rect->x()+2,Rect->y()+17);


    //
    setPixmap(QPixmap(":image/arrow.png"));



    //demarrage du thread
    connect(this,SIGNAL(timer()),this,SLOT(move()));
    start();
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));





}

void projetile::run()
{


    while(lifetime < 400){
        msleep(20);
        emit timer();
        lifetime+=10;
    }

}
 void projetile::move(){
     //test collision
     QList<QGraphicsItem *> CollindingItem = collidingItems();

     for(int i  = 0 ; i <CollindingItem.length(); ++i ){

         if(typeid(*CollindingItem[i]) == typeid(Wall_face)){
            scene()->removeItem(this);
            lifetime =400;
            return;
         }


     }


    setPos(x()-XPos,y()-YPos);
}

