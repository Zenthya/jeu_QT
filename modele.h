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
#include <screen.h>

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



    Screen *screen;
    Health *health;
    Number1 *number1;
    Number2 *number2;
    Chest *chest;
    Monster * Leballon;
    Sword Excalibur =Sword(8);
    void addProjectile(projetile  *);
    QPixmap fireball =QPixmap(":/images/weapon/fire_ball.png");
    QMutex mutex1;
    QList<projetile *> getProjectile_element();


    void RemoveProjectile_element( projetile *);
    void play_sound();
    QSoundEffect  * Death_player  ;
    QList<Graphic_element *> Map_element;

    QList<Graphic_element *> getMap_element() ;
    void setMap_element( QList<Graphic_element *> &value);

    QList<Graphic_element_alive *> getGame_element() ;
    void setGame_element( QList<Graphic_element_alive *> &value);
    void RemoveGame_element( Graphic_element_alive *);

    QList<Graphic_element *> getChest_element();
    void setChest_element(QList<Graphic_element *> &value);
    void RemoveChest_element( Graphic_element *);

    Player *getPlayer() ;
    void setPlayer(Player *value);

private:
    void   Mapping(QString datafile);
    QList<Graphic_element_alive *> Game_element;

    QList<projetile  *> Projectile_element;

    QList<Graphic_element *> Chest_element;
    Player  *player;

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
