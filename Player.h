#ifndef PLAYER_H
#define PLAYER_H

#include "graphic_element.h"
#include "weapon.h"

class Player : public Graphic_element_alive
{
public:
    Player(QPointF *);

    void setLife(int value);
    int getAmmo();
    void setAmmo(int value);
    void animationAttack();
    void changeWeapon();
    int lifetime_animation=1000;
    bool attack =false;
    Weapon getWeapon();
    void setWeapon(Weapon &value);
    QString getSens() const;
    void setSens(const QString &value);
    QString sens;
    QString type();

private :

    int ammo;
    Weapon *weapon;
};

#endif // PLAYER_H
