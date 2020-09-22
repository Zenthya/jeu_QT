#include "conttrolleur.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <graphic_element.h>
#include <arrow.h>

Conttrolleur::Conttrolleur()
{

}
void Conttrolleur::setModele(Modele * value)
{
    modele=value;
}

Modele *Conttrolleur::getModele()
{
    return this->modele;
}

void Conttrolleur::ReveivceEvent(QEvent *event)
{
    switch(event->type()){

    case QEvent::GraphicsSceneMousePress :

       modele->addProjectile(new arrow(new QPointF(modele->player->getCoordonnee()),new QPointF(static_cast<QGraphicsSceneMouseEvent* >(event)->scenePos())));
       //event du clique
       //mettre la fonction attaquer ici
        break;
    case QEvent::KeyPress :

        switch (static_cast<QKeyEvent*>(event)->key()) {
            case Qt::Key_Z:
               Deplacementjoueur("haut");
               break;
            case Qt::Key_Q:
                Deplacementjoueur("droite");
                break;
            case Qt::Key_S:
                Deplacementjoueur("bas");
                break;
            case Qt::Key_D:
                Deplacementjoueur(QString("gauche"));
                break;
        }

    }
}



void Conttrolleur::Deplacementjoueur(QString event)
{
    qDebug()<<"event appelé";

    QPointF   position = modele->player->getCoordonnee();
    if(event == QString("haut")){

        position.setY(position.y()-10);
   }else if(event == QString("bas") ){
        position.setY(position.y()+10);
    }else if(event == QString("gauche")){
        position.setX(position.x()+10);

    }else if(event == QString("droite")){
        position.setX(position.x()-10);
    }

    bool avancer =true ;
    QPointF position_pied = QPointF(position.x(),position.y()+modele->player->getDrawing().height());
    for(int i=0; i<modele->Map_element.length();i++){
        Graphic_element * element = modele->Map_element[i];
      if(element->type()==QString("Wall") ||element->type()==QString("Background")){

          if(element->getCoordonnee().x()<=position_pied.x()+modele->player->getDrawing().width() &&
              element->getCoordonnee().x()+element->getDrawing().width() > position_pied.x()  &&
              element->getCoordonnee().y()<=position_pied.y()  &&
              element->getCoordonnee().y()+element->getDrawing().height() >=position_pied.y()
                   ){

              avancer = false ;


           }


    }


    }
    if(avancer){
        modele->player->setCoordonnee(new QPointF(position));
        Afficheur->scene()->update();
        Afficheur->centerOn(position);
    }




}


void Conttrolleur::run(){


    while(true){
        msleep(20);
           Afficheur->scene()->update();
        for(int i =0 ; i<modele->getProjectile_element().length();i++){
           projetile  * element = modele->getProjectile_element()[i];
            if(element->lifetime> 0){

                QPointF   position = element->getCoordonnee();
                position.setX(position.x()-element->XPos);
                position.setY(position.y()-element->YPos);
                element->setCoordonnee(new QPointF(position));
                element->lifetime -=10;
                if(element->lifetime == 0){
                        modele->RemoveProjectile_element(element);
                }



            }


        }


    }




}

