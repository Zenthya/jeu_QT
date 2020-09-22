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

class Modele
{
public:
    Modele();
    QList<Graphic_element *> Game_element;
    QList<Graphic_element *> Map_element;
    Player  *player;

private:
    void   Mapping(QString datafile);

};

#endif // MODELE_H
