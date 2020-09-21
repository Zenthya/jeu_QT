#include "wall.h"
#include <QGraphicsScene>
Wall::Wall(QPointF *point, int typeOfWall):Graphic_element(point)
{
    if(typeOfWall == 0){
        setDrawing( new QPixmap(":map/wall_corner_left.png"));
    } else if (typeOfWall == 1) {
        setDrawing(new QPixmap(":map/wall_middle.png"));
    } else if (typeOfWall == 2) {
        setDrawing(new QPixmap(":map/wall_corner_right.png"));
    } else if (typeOfWall == 3) {
        setDrawing(new QPixmap(":map/wall_double_corner.png"));
    }
}
