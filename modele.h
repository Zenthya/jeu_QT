#ifndef MODELE_H
#define MODELE_H
#include<wall.h>
#include"graphic_element.h"
#include<floore.h>
#include<wall.h>
#include<player.h>
#include<background.h>
#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonArray>
#include <QFile>
#include <projetile.h>
#include<QMutex>
#include<QMutexLocker>
#include<monster.h>
#include<QObject>
#include <QSoundEffect>

class Modele
{


public:
    Modele();


    Player  *player;
    Monster * Leballon;
    Sword Excalibur =Sword(8);
    void addProjectile(projetile  *);
    QPixmap fireball =QPixmap(":/images/weapon/fire_ball.png");

    QList<projetile *> getProjectile_element();


    void RemoveProjectile_element( projetile *);
    void play_sound();
    QSoundEffect  * Death_player  ;
    QList<Graphic_element *> Map_element;



    QList<Graphic_element_alive *> getGame_element() ;
    void setGame_element( QList<Graphic_element_alive *> &value);
    void RemoveGame_element( Graphic_element_alive *);

private:
    void   Mapping(QString datafile);
    QList<Graphic_element_alive *> Game_element;

    QList<projetile  *> Projectile_element;

};
class hurt{

public :
    hurt(Graphic_element_alive *element,int life_time){
        this->element=element;
        this->lifetime =life_time;
    };
    ~hurt();
    Graphic_element_alive * element;
    int lifetime ;



};
class coffre:Graphic_element {

public :
    coffre(QPointF *);


};

#endif // MODELE_H
