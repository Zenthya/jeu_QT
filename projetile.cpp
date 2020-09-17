#include "projetile.h"
#include <QDebug>
#include <QVector2D>
#include <QtMath>



projetile::projetile(QGraphicsRectItem *Rect,QPointF * Souris)
{
    setRect(Rect->x(),Rect->y(),10,50);
    // calcul des mouvement a effectuer pour le projectile
    qreal vitesse = 10 ;

    qreal S =(Rect->x()-Souris->x()) ;
    qreal P =(Rect->y()-Souris->y()) ;
    qreal normeSP =qSqrt((S*S)+(P*P));

     YPos = (P/normeSP)*vitesse;
     XPos = (S/normeSP)*vitesse;

      qreal angle = qRadiansToDegrees(qAtan2(P,S)) -90;
   setRotation(angle);
   setTransformOriginPoint(Rect->x(),Rect->y());


    //demarrage du thread
    connect(this,SIGNAL(timer()),this,SLOT(move()));
    start();
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));





}

void projetile::run()
{

    int time = 0;
    while(time < 400){
        msleep(20);
        emit timer();
        time+=10;
    }

}
 void projetile::move(){
    setPos(x()-XPos,y()-YPos);
}

