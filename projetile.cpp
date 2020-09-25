#include "projetile.h"
#include <QDebug>
#include <QVector2D>
#include <QtMath>
#include <wall.h>
#include <QGraphicsScene>
#include <QPixmap>

projetile::projetile(QPointF *point,QPointF *Souris,int dmg):Graphic_element(point)
{
    this->Souris = Souris ;
    this->dmg=dmg;
    qreal S =(point->x()-Souris->x()) ;
    qreal P =(point->y()-Souris->y()) ;
    Position = new QVector2D(S,P);
    QVector2D unitaire = Position->normalized().operator*=(vitesse);
    XPos = unitaire.x();
    YPos =unitaire.y();
    angle = qRadiansToDegrees(qAtan2(P,S)) -90;
}

projetile::~projetile()
{

}


void projetile::setDrawing(QPixmap * draw)
{
   // Graphic_element::setDrawing(new QPixmap(draw->transformed(QTransform().rotate(angle))));
    Graphic_element::setDrawing(draw);
}



