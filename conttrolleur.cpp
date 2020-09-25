#include "conttrolleur.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <graphic_element.h>
#include <arrow.h>
#include "QtDebug"
#include <monster.h>
#include <QSoundEffect>
#include <QRectF>
#include <QElapsedTimer>

Conttrolleur::Conttrolleur()
{

}
void Conttrolleur::setModele(Modele * value)
{
    modele=value;
    connect(this,&Conttrolleur::sound_death,modele->Death_player,&QSoundEffect::play);
}

Modele *Conttrolleur::getModele()
{
    return this->modele;
}

void Conttrolleur::ReveivceEvent(QEvent *event)
{
    if(event->type()== QEvent::GraphicsSceneMousePress ){
        MousePressDetection(event);
    }

    if(event->type()== QEvent::GraphicsSceneMouseMove){
        if(static_cast<QGraphicsSceneMouseEvent* >(event)->scenePos().x() < modele->player->getCoordonnee().x()) {
            modele->player->setSens("left");
        } else {
            modele->player->setSens("right");
        }
        if (!modele->player->attack)
        {
            modele->player->animationAttack();
        }
    }
    if(event->type()== QEvent::KeyPress ){
        switch (static_cast<QKeyEvent*>(event)->key()) {
        case Qt::Key_Z:
            Key.append(&Haut);
            break;
        case Qt::Key_Q:
            Key.append(&Gauche);
            break;
        case Qt::Key_S:
            Key.append(&Bas);
            break;
        case Qt::Key_D:
            Key.append(&Droite);
            break;
        case Qt::Key_E:
            modele->player->changeWeapon();
            break;
        }
    }
    if(event->type()== QEvent::KeyRelease ){
        switch (static_cast<QKeyEvent*>(event)->key()) {
        case Qt::Key_Z:
            Key.removeOne(&Haut);
            break;
        case Qt::Key_Q:
            Key.removeOne(&Gauche);
            break;
        case Qt::Key_S:
            Key.removeOne(&Bas);
            break;
        case Qt::Key_D:
            Key.removeOne(&Droite);
            break;
        }
    }
}


void Conttrolleur::Deplacementjoueur(QString *event)
{
    QPointF   position_player = modele->player->getCoordonnee();
    QPointF   position_screen = modele->screen->getCoordonnee();
    if(*event == QString("haut")){
        position_player.setY(position_player.y()-5);
    }else if(*event == QString("bas") ){
        position_player.setY(position_player.y()+5);
    }else if(*event == QString("gauche")){
        position_player.setX(position_player.x()-5);
    }else if(*event == QString("droite")){
        position_player.setX(position_player.x()+5);
    }
    QPointF position_pied = QPointF(position_player.x(),position_player.y()+modele->player->getDrawing().height());
    if(Controle_out_map(position_pied)){
        Afficheur->centerOn(position_player);
        modele->player->setCoordonnee(new QPointF(position_player));
        if(position_screen.y() >= 50 and position_screen.x() >= 50){
            UpdateScreenPosition(position_screen, position_player);
        }
    }
}

bool Conttrolleur::Controle_out_map(QPointF  position )
{
    for(int i=0; i<modele->Map_element.length();i++){
        Graphic_element * element_carte = modele->Map_element[i];
        if(element_carte->type()==QString("Wall") ||element_carte->type()==QString("Background")){
            if( element_carte->getCoordonnee().x()<=position.x() &&
                    element_carte->getCoordonnee().x()+element_carte->getDrawing().width() > position.x()  &&
                    element_carte->getCoordonnee().y()<=position.y()  &&
                    element_carte->getCoordonnee().y()+element_carte->getDrawing().height() >=position.y()) {

                return false;
            }
        }
    }
    return true ;
}

bool Conttrolleur::player_attack_chest()
{
        QList<Graphic_element *> tab = modele->getChest_element();
        tab.removeOne(modele->player);
    for(int i=0;i<tab.length();i++ ){
        Graphic_element * mob_element= tab[i];
        QRectF bounding_mob = QRectF(mob_element->getCoordonnee(),mob_element->getDrawing().size());
        QRectF player_sword;
        QPointF sens ;
        if(modele->player->getSens()==QString("left")){
            sens= QPointF(20,0);
        }else{
            sens= QPointF(10,0).operator-=(QPointF(modele->player->getDrawing().width(),0));
        }
            player_sword = QRectF(QPointF(modele->player->getCoordonnee()).operator-=( sens),QSize(modele->player->getDrawing().width()/4,modele->player->getDrawing().height()));
        if(bounding_mob.intersects(player_sword)){
           modele->player->setAmmo(10);
         return true ;
    }
    }return false;}


bool Conttrolleur::player_attack()
{
        QList<Graphic_element_alive *> tab = modele->getGame_element();
        tab.removeOne(modele->player);
    for(int i=0;i<tab.length();i++ ){
        Graphic_element_alive * mob_element= tab[i];
        QRectF bounding_mob = QRectF(mob_element->getCoordonnee(),mob_element->getDrawing().size());
        QRectF player_sword;
        QPointF sens ;
        if(modele->player->getSens()==QString("left")){
            sens= QPointF(20,0);
        }else{
            sens= QPointF(10,0).operator-=(QPointF(modele->player->getDrawing().width(),0));
        }
            player_sword = QRectF(QPointF(modele->player->getCoordonnee()).operator-=( sens),QSize(modele->player->getDrawing().width()/4,modele->player->getDrawing().height()));
        if(bounding_mob.intersects(player_sword)){
            mob_element->life -=modele->player->getWeapon().dmg;
            List_hurt.append(new hurt(mob_element,300));
         if(mob_element->life<0){
             modele->RemoveGame_element(mob_element);
         }
         return true ;
    }
    }return false;}

void Conttrolleur::animate_player_sword(int  life_time, bool attack)
{

    QString weapon_selected = modele->player->weapon->type();
    QString direction_selected = modele->player->getSens();
    if(attack){
        if(!modele->Death_player->isPlaying()){
            emit sound_death();
        }
        if(life_time>400){
            modele->player->setDrawing( new QPixmap(":/assets/images/player_" + weapon_selected + "/player_" + weapon_selected + "_" + direction_selected + "_hand_state2.png"));
            modele->player->setState("state2");
            modele->player->lifetime_animation -=200;
        }else if(life_time<=400 && life_time>0){
            modele->player->setDrawing( new QPixmap(":/assets/images/player_" + weapon_selected + "/player_" + weapon_selected + "_" + direction_selected + "_hand_state3.png"));
            modele->player->setState("state3");
            modele->player->lifetime_animation -=200;
        }else if(life_time<=0){
            modele->player->setDrawing( new QPixmap(":/assets/images/player_" + weapon_selected + "/player_" + weapon_selected + "_" + direction_selected + "_hand_state1.png"));
            modele->player->setState("state1");
            modele->player->attack=false;
            modele->player->lifetime_animation=1000;
        }
    }
}

void Conttrolleur::hurt_animation(Graphic_element_alive * element,int  *life_time)
{
    QString data = element->type();
    QString data_hurt =":/assets/images/"+data+"_hurt.png";

    if(*life_time >= 50){
            *life_time -=50;
            element->setDrawing( new QPixmap(data_hurt));

    }else{
        *life_time -=50;
        element->setDrawing( new QPixmap(":/assets/images/"+data+".png"));
    }

}

void Conttrolleur::run(){

     bool monstre_touche =false;

      int last_time=0;
      QElapsedTimer timer;
      timer.start();

    while(true){
        Afficheur->scene()->update();
        msleep(30);


        life_cadence+=1;



        for(int i =0 ; i<modele->getProjectile_element().length();i++){

            projetile  * element = modele->getProjectile_element()[i];

                QPointF   position = element->getCoordonnee();
                position.setX(position.x()-element->XPos);
                position.setY(position.y()-element->YPos);



                last_time=timer.elapsed();
                for(int i=0; i<modele->getGame_element().length();i++){
                    Graphic_element_alive * mob_element = modele->getGame_element()[i];


                      if(mob_element->getCoordonnee().x()<=position.x() &&
                          mob_element->getCoordonnee().x()+mob_element->getDrawing().width() > position.x()  &&
                          mob_element->getCoordonnee().y()<=position.y()  &&
                          mob_element->getCoordonnee().y()+mob_element->getDrawing().height() >=position.y()
                               ){
                          modele->RemoveProjectile_element(element);
                          element->~projetile();


                          mob_element->life-=element->dmg;

                          List_hurt.append(new hurt(mob_element,300));


                          if(mob_element->life<0){

                              modele->RemoveGame_element(mob_element);
                          }

                }


                }

                if(Controle_out_map(position)){
                element->setCoordonnee(new QPointF(position));}
                element->lifetime -=10;
                if(element->lifetime == 0){
                    modele->RemoveProjectile_element(element);
                    element->~projetile();
                }


        }

        
        animate_player_sword(modele->player->lifetime_animation,modele->player->attack);

        for(int i=0;i<Key.length();i++){
            Deplacementjoueur(Key[i]);
        }
        if(modele->player->attack && !monstre_touche){
            monstre_touche= player_attack();
        }else if(!modele->player->attack && monstre_touche){
            monstre_touche=false;
        }





        for(int i=0;i<List_hurt.length();i++){
            hurt_animation(List_hurt[i]->element,&List_hurt[i]->lifetime);
            if(List_hurt[i]->lifetime<0){
                List_hurt.removeOne(List_hurt[i]);
            }

        }

        for(int i=0;i<modele->getGame_element().length();i++){
            Graphic_element_alive *mob = modele->getGame_element()[i];
            int height= mob->getDrawing().height();
            int width =mob->getDrawing().width();

            if(mob->type()==QString("monster/monster_potatoes")){
                if(life_cadence%mob->cadence==0){
                    modele->addProjectile(new fire_ball(new QPointF(QPointF(mob->getCoordonnee()).operator+=(QPointF(0,height/2))),   new QPointF( QPointF(mob->getCoordonnee()).operator+=(QPointF(-20,height/2)))));
                    modele->addProjectile(new fire_ball(new QPointF(QPointF(mob->getCoordonnee()).operator+=(QPointF(width/2,0))),   new QPointF( QPointF(mob->getCoordonnee()).operator+=(QPointF(width/2,-20)))));
                    modele->addProjectile(new fire_ball(new QPointF(QPointF(mob->getCoordonnee()).operator+=(QPointF(width,height/2))),   new QPointF( QPointF(mob->getCoordonnee()).operator+=(QPointF(width+20,height/2)))));
                    modele->addProjectile(new fire_ball(new QPointF(QPointF(mob->getCoordonnee()).operator+=(QPointF(width/2,height))),   new QPointF( QPointF(mob->getCoordonnee()).operator+=(QPointF(width/2,height+20)))));
                }
                if(life_cadence==10000){
                    life_cadence=0;
                }
            }

        }}

}


void Conttrolleur::MousePressDetection(QEvent *event)
{
    if (modele->player->weapon->type() == "bow" and modele->player->getAmmo() >= 0 ) {
        modele->addProjectile(new arrow(new QPointF(modele->player->getCoordonnee()),new QPointF(static_cast<QGraphicsSceneMouseEvent* >(event)->scenePos())));
        int number_arrow = modele->player->getAmmo();
        if (number_arrow <=9){
            modele->number1->setDrawing( new QPixmap(":/assets/images/number/0.png"));
            //            modele->number1->setPix
            modele->number2->setDrawing( new QPixmap(":/assets/images/number/" + QString::number(number_arrow) + ".png"));
        } else if(number_arrow > 9){
            modele->number1->setDrawing( new QPixmap(":/assets/images/number/" + QString::number(number_arrow)[0] + ".png"));
            modele->number2->setDrawing( new QPixmap(":/assets/images/number/" + QString::number(number_arrow)[1] + ".png"));
        }
        modele->player->setAmmo(number_arrow - 1);
        modele->player->attack= true;
    }
    if(modele->player->weapon->type() == "sword"){
        modele->player->attack= true;
    }
}

void Conttrolleur::UpdateScreenPosition(QPointF position_screen, QPointF position_player)
{
    if(position_player.x() > 960 and  position_player.x() < 7440) {
        position_screen.setX(position_player.x()-910);
    } else if(position_player.x() > 7440) {
        position_screen.setX(6530);
    } else {
        position_screen.setX(50);
    }
    if(position_player.y() > 540 and position_player.y() < 5060) {
        position_screen.setY(position_player.y()-490);
    } else if(position_player.y() > 5060) {
        position_screen.setY(4570);
    } else {
        position_screen.setY(50);
    }
    modele->screen->setCoordonnee(new QPointF(position_screen));
    modele->health->setCoordonnee(new QPointF(position_screen.x(), position_screen.y() + 50));
    modele->number1->setCoordonnee(new QPointF(position_screen.x() + 35, position_screen.y() + 55));
    modele->number2->setCoordonnee(new QPointF(position_screen.x() + 50, position_screen.y() + 55));
}

