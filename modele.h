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
    QList<Graphic_element_alive *> Game_element;
    QList<Graphic_element *> Map_element;

    Player  *player;
    Monster * Leballon;
    Sword Excalibur =Sword(8);
    void addProjectile(projetile  *);

    QList<projetile *> getProjectile_element();


    void RemoveProjectile_element( projetile *);
    void play_sound();
    QSoundEffect  * Death_player  ;


private:
    void   Mapping(QString datafile);
    QList<projetile  *> Projectile_element;

};

#endif // MODELE_H
