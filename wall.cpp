#include "wall.h"
#include <QGraphicsScene>
Wall::Wall(QPointF * point):Graphic_element(point)
{

  setDrawing( new QPixmap(":image/wall_middle.png"));







}
