#include "monster.h"

Monster::Monster(QPointF * point,int life):Graphic_element_alive(point)
{
    setDrawing(new QPixmap(":/assets/images/monster/monster_baloon.png"));
    this->life =life;
}

Patatoes_monster::Patatoes_monster(QPointF *point):Monster(point,3)
{
    setDrawing(new QPixmap(":/assets/images/monster/monster_potatoes.png"));
    cadence= 100;
}

The_Boss::The_Boss(QPointF *point ):Monster(point,3)
{
    setDrawing(new QPixmap(":/assets/images/monster/boss/boss_1.png"));
    cadence= 70;
}
