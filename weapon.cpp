#include "weapon.h"
#include<QDebug>


Weapon::Weapon()
{

}

QString Weapon::type()
{

}

Bow::Bow( int value)
{
    dmg = value;
}

Sword::Sword( int value)
{
    dmg = value;
}

QString Bow::type(){
    return "bow";
}

QString Sword::type(){
    return "sword";
}
