#include "floor.h"

Floor::Floor()
{

    setPixmap(QPixmap(":image/floore_without_wall.png"));

}
Floor::Floor(QPointF offset){

    setPixmap(QPixmap(":image/floore_without_wall.png"));
    setPos(offset);
}
