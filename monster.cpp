#include "monster.h"

Monster::Monster(QPointF * point,int life):Graphic_element_alive(point)
{
    setDrawing(new QPixmap(":image/ennemi2.png"));
    this->life =life;
}

Patatoes_monster::Patatoes_monster(QPointF *point):Monster(point,3)
{
    setDrawing(new QPixmap(":/images/monster/monster_potatoes.png"));
    cadence= 100;
}
