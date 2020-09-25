#include "Player.h"
#include "qdebug.h"

Player::Player(QPointF * point):Graphic_element_alive(point){
    setDrawing(new QPixmap(":/assets/images/player/player_left.png"));
    Weapon *excalibur = new Sword(10);
    setWeapon(*excalibur);
    this->life = 8;
    this->ammo = 20;
    qDebug() << weapon->type();
}

int Player::getAmmo()
{
    return ammo;
}

void Player::setAmmo(int value)
{
    ammo = value;
}

Weapon Player::getWeapon()
{
    return *weapon;
}

void Player::setWeapon(Weapon &value)
{
    weapon = &value;
}

QString Player::getSens() const
{
    return sens;
}

void Player::setSens(const QString &value)
{
    sens = value;
}

QString Player::type()
{
    return "player_" + weapon->type() + "/player_" + weapon->type() + "_" + getSens() + "_hand_" + getState() ;
}

QString Player::getState() const
{
    return state;
}

void Player::setState(const QString &value)
{
    state = value;

}


void Player::animationAttack()
{
    QString path = ":/assets/images/player_" + weapon->type() + "/player_" + weapon->type() + "_" + getSens() + "_hand_state1.png";
    setDrawing(new QPixmap (path));

}


void Player::changeWeapon()
{
    if(weapon->type() == "sword") {
        Weapon *firefly = new Bow(5);
        setWeapon(*firefly);
        animationAttack();
    } else if(weapon->type() == "bow") {
        Weapon *excalibur = new Sword(1);
        setWeapon(*excalibur);
        animationAttack();
    }
}
