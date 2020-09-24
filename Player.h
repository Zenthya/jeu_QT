#ifndef PLAYER_H
#define PLAYER_H

#include "graphic_element.h"
#include "weapon.h"

class Player : public Graphic_element_alive
{
public:
    Player(QPointF *);
    int getLife();
    void setLife(int value);
    int getAmmo();
    void setAmmo(int value);
    int lifetime_animation;
    bool attack;
    void animationAttack();
    void changeWeapon();
    int lifetime_animation=1000;
    bool attack =false;
    Weapon getWeapon();
    void setWeapon(Weapon &value);
    QString getSens() const;
    void setSens(const QString &value);

private :
    QString sens;
    int life ;
    int ammo;
    Weapon *weapon;
};

#endif // PLAYER_H
