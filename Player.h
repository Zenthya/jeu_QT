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
    Weapon getWeapon();
    void setWeapon(Weapon &value);
    QString getSens()const;
    void setSens(const QString &value);

    QString type();
    QString getState() const;
    void setState(const QString &value);
    int lifetime_animation=1000;
    bool attack =false;
    Weapon *weapon;

    QString sens;


private :

    int ammo;
    QString state;
   
};

#endif // PLAYER_H
