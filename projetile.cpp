#include "projetile.h"
#include <QDebug>
#include <QVector2D>
#include <QtMath>
#include <wall.h>
#include <QGraphicsScene>
#include <QPixmap>

projetile::projetile(QPointF *point,QPointF *Souris):Graphic_element(point)
{
    this->Souris = Souris ;
    qDebug()<<*point;
    qreal S =(point->x()-Souris->x()) ;
    qreal P =(point->y()-Souris->y()) ;
    Position = new QVector2D(S,P);
    QVector2D unitaire = Position->normalized().operator*=(vitesse);
    qDebug()<<unitaire;
    XPos = unitaire.x();
    YPos =unitaire.y();
    angle = qRadiansToDegrees(qAtan2(P,S)) -90;
}

void projetile::setDrawing(QPixmap * draw)
{
    Graphic_element::setDrawing(new QPixmap(draw->transformed(QTransform().rotate(angle))));
}



