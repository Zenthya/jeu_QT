#ifndef MODELE_H
#define MODELE_H
#include<wall.h>
#include"graphic_element.h"
#include<floore.h>
#include<wall.h>
#include<background.h>
#include <QJsonDocument>
#include <QJsonObject>

#include <QJsonArray>
#include <QFile>

class Modele
{
public:
    Modele();
    QList<Graphic_element *> wall_element;
    QList<Graphic_element *> Map_element;

private:
    void   Mapping(QString datafile);

};

#endif // MODELE_H
