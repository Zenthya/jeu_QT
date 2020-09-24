#include "monster.h"

Monster::Monster(QPointF * point,int life):Graphic_element_alive(point)
{
    setDrawing(new QPixmap(":image/ennemi2.png"));
    this->life =life;
}
