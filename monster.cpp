#include "monster.h"

Monster::Monster(QPointF * point,int life):Graphic_element_alive(point)
{
    setDrawing(new QPixmap(":/assets/images/monster/monster_baloon.png"));
    this->life =life;
}
