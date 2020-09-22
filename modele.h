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


class Modele
{


public:
    Modele();
    QList<Graphic_element *> Game_element;
    QList<Graphic_element *> Map_element;

    Player  *player;
    void addProjectile(projetile  *);

    QList<projetile *> getProjectile_element();


    void RemoveProjectile_element( projetile *);

private:
    void   Mapping(QString datafile);
    QList<projetile  *> Projectile_element;

};

#endif // MODELE_H
