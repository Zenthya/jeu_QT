#include "afficheur.h"
#include<QDebug>

Afficheur::Afficheur(QWidget *parent):QGraphicsView(parent)
{

    setMouseTracking(true);
    setFixedSize(1920,1080);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    
}

void Afficheur::setModele(Modele * setter)
{
    modele = setter;

}


Modele* Afficheur::getModele(){
    return modele;
}





ModifiedScene::ModifiedScene(QObject *parent): QGraphicsScene(parent){


    setSceneRect(0,0,10800,7200);
    setStickyFocus(true);


}

void ModifiedScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<event->scenePos();
}

void ModifiedScene::setModele(Modele *setter)
{
    modele = setter;
}

Modele *ModifiedScene::getModele()
{return modele;
}

void ModifiedScene::drawBackground(QPainter * Painter, const QRectF & rect)
{

    for(int i =0 ; i <modele->wall_element.length();i++){


    Painter->drawPixmap(modele->wall_element[i]->getCoordonnee(),modele->wall_element[i]->getDrawing());}

    for(int i=0 ; i <modele->Map_element.length();i++){

        Painter->drawPixmap(modele->Map_element[i]->getCoordonnee(),modele->Map_element[i]->getDrawing());
    }
}
