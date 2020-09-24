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
    virtual QString type();




};



class Bow : public Weapon {

public :
    Bow(int dmg);
    QString type();

};

class Sword : public Weapon{
public:
    Sword(int dmg);
    QString type();
};

#endif // WEAPON_H
