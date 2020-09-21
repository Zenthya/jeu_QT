#ifndef MODELE_H
#define MODELE_H
#include<wall.h>
#include"graphic_element.h"

class Modele
{
public:
    Modele();
    QList<Graphic_element *> wall_element;
};

#endif // MODELE_H
