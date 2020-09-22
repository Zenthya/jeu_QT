#include "modifiedscene.h"

ModifiedScene::ModifiedScene(QObject *parent): QGraphicsScene(parent){


    setSceneRect(0,0,10800,7200);




}

void ModifiedScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   Conttrolleur->ReveivceEvent(event);

}



void ModifiedScene::setModele(Modele *setter)
{
    modele = setter;
}

Modele *ModifiedScene::getModele()
{return modele;
}






void ModifiedScene::keyPressEvent(QKeyEvent *event)
{

    Conttrolleur->ReveivceEvent(event);
}






void ModifiedScene::drawBackground(QPainter * Painter, const QRectF & )
{



    for(int i=0 ; i <modele->Map_element.length();i++){

        Painter->drawPixmap(modele->Map_element[i]->getCoordonnee(),modele->Map_element[i]->getDrawing());
    }
   Painter->drawPixmap(modele->player->getCoordonnee(),modele->player->getDrawing());
    qDebug()<<"afficheur :"<<modele->player->getCoordonnee();
}
