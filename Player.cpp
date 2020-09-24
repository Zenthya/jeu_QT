#include "player.h"

Player::Player(QPointF * point):Graphic_element_alive(point){


    setDrawing(new QPixmap(":/images/player_sword/player_sword_left_hand_up.png"));
    this->life = 8;
    setWeapon(new Bow(8));

}


int Player::getAmmo()
{
    return ammo;
}

void Player::setAmmo(int value)
{
    ammo = value;
}

Weapon *Player::getWeapon()
{
    return weapon;
}

void Player::setWeapon(Weapon *value)
{
    weapon = value;
}
