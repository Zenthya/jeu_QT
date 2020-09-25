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
    void animationAttack();
    void changeWeapon();
    Weapon getWeapon();
    void setWeapon(Weapon &value);
    QString getSens()const;
    void setSens(const QString &value);
    QString getPath();
    QString getState() const;
    void setState(const QString &value);
    int lifetime_animation=1000;
    bool attack =false;
    Weapon *weapon;

private :
    int life ;
    int ammo;
    QString state;
    QString sens;
};

#endif // PLAYER_H
