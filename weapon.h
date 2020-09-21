#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsScene>
#include <QObject>
#include<projetile.h>


class  Weapon
{



public:
    Weapon();
    int dmg ;




};



class Bow : public Weapon {

public :
    Bow(int dmg);


};

#endif // WEAPON_H
