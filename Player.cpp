#include "player.h"
#include "qdebug.h"

Player::Player(QPointF * point):Graphic_element_alive(point){
    setDrawing(new QPixmap(":image/player.png"));
    Weapon *excalibur = new Sword(10);
    setWeapon(*excalibur);
    this->life = 8;
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


void Player::animationAttack()
{
    QString path = ":/image/player_" + weapon->type() + "_" + getSens() + "_hand_walk.png";
    setDrawing(new QPixmap (path));
}

void Player::changeWeapon()
{
    if(weapon->type() == "sword") {
        Weapon *firefly = new Bow(10);
        setWeapon(*firefly);
        animationAttack();
    } else if(weapon->type() == "bow") {
        Weapon *excalibur = new Sword(10);
        setWeapon(*excalibur);
        animationAttack();
    }
}
