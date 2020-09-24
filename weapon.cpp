#include "weapon.h"
#include<QDebug>




Weapon::Weapon()
{
}

QString Weapon::type()
{
    return "Weapon";
}

Bow::Bow( int value){
    dmg = value;
}

QString Bow::type()
{
    return "Bow";
}
Sword::Sword(int value){
    dmg=value;
}

QString Sword::type(){
    return"Sword";
}
