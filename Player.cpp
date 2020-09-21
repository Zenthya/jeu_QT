#include "player.h"

Player::Player(QPointF * point):Graphic_element(point){


    setDrawing(new QPixmap(":image/player.png"));

}

int Player::getLife()
{
    return life;
}

void Player::setLife(int value)
{
    life = value;
}

int Player::getAmmo()
{
    return ammo;
}

void Player::setAmmo(int value)
{
    ammo = value;
}
