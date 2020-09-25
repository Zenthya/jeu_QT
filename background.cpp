#include "background.h"
#include <QGraphicsScene>
Background::Background(QPointF *point, int typeOfBackground):Graphic_element(point)
{
    if(typeOfBackground == 0){
        setDrawing(new QPixmap(":/assets/images/map/background_left_corner.png"));
    } else if (typeOfBackground == 1) {
        setDrawing(new QPixmap(":/assets/images/map/background.png"));
    } else if (typeOfBackground == 2) {
        setDrawing(new QPixmap(":/assets/images/map/background_right_corner.png"));
    } else if (typeOfBackground == 3) {
        setDrawing(new QPixmap(":/assets/images/map/background_double_corner.png"));
    }
}

QString Background::type()
{
    return "Background";
}
