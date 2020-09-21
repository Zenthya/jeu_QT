#ifndef BACKGROUND_H
#define BACKGROUND_H

#include<graphic_element.h>
#include<QPixmap>

class Background : public Graphic_element   {
    public:
    QPixmap Drawing;
    Background(QPointF *, int typeOfBackground);
    };

#endif // BACKGROUND_H
