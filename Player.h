#ifndef PLAYER_H
#define PLAYER_H

#include "graphic_element.h"
#include "weapon.h"

class Player : public Graphic_element_alive
{
public:
    Player(QPointF *);



    int getAmmo();
    void setAmmo(int value);
    int lifetime_animation=1000;
    bool attack =false;
    bool sens=true;

    Weapon *getWeapon();
    void setWeapon(Weapon *value);


private :
    Weapon *weapon;

    int ammo;
};

#endif // PLAYER_H
