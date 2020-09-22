#include "floore.h"
#include <QGraphicsScene>


Floore::Floore(QPointF *point):Graphic_element(point)
{
    setDrawing(new QPixmap(":map/floore.png"));
}

QString Floore::type(){
    return "Floore";
}
