#ifndef WALL_H
#define WALL_H


#include<QPixmap>
#include<graphic_element.h>


class Wall : public Graphic_element   {
    public:
    QPixmap Drawing;
    Wall(QPointF *, int typeOfWall);
    QString type();
    };
#endif // WALL_H
