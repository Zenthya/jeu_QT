#include "screen.h"


Screen::Screen(QPointF * point):Graphic_element(point)
{
    setDrawing(new QPixmap(":/assets/images/healt/healt_10.png"));
}

Health::Health(QPointF * point):Screen(point)
{
    setDrawing(new QPixmap(":/assets/images/arrow_count.png"));
}

Number1::Number1(QPointF * point):Screen(point)
{
    setDrawing(new QPixmap(":/assets/images/number/2.png"));
}

Number2::Number2(QPointF * point):Screen(point)
{
    setDrawing(new QPixmap(":/assets/images/number/0.png"));
}

Chest::Chest(QPointF * point):Screen(point)
{
    setDrawing(new QPixmap(":/assets/images/object/chest.png"));
}


