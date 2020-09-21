#ifndef FLOORE_H
#define FLOORE_H


#include<QPixmap>
#include<graphic_element.h>


class Floore : public Graphic_element   {
    public:
    QPixmap Drawing;
    Floore(QPointF *);
    };
#endif // WALL_H

