#ifndef PLAYER_H
#define PLAYER_H

#include "graphic_element.h"
#include "weapon.h"

class Player : public Graphic_element
{
public:
    Player(QPointF *);

    int getLife();
    void setLife(int value);

    int getAmmo();
    void setAmmo(int value);
    int lifetime_animation;
    bool attack;

private :
    int life ;
    int ammo;
};

#endif // PLAYER_H
