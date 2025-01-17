#include "graphic_element.h"
#include "QMutexLocker"

Graphic_element::Graphic_element(QPointF * pose)
{
    Coordonnee = pose;
}

Graphic_element::~Graphic_element()
{
    delete Drawing;
    delete Coordonnee;
}

const QPointF & Graphic_element ::getCoordonnee() const
{
    QMutexLocker locker(&mutex);
    return   * Coordonnee;
}

void Graphic_element::setCoordonnee( QPointF * value)
{
    QMutexLocker locker(&mutex);
    Coordonnee =  value;
}

QPixmap & Graphic_element::getDrawing()
{
    QMutexLocker locker(&mutex);
    return *Drawing;
}

void Graphic_element::setDrawing( QPixmap *value)
{
    QMutexLocker locker(&mutex);
    Drawing = value;
}
QString Graphic_element::type(){
    return "Graphic_element";
}

Graphic_element_alive::Graphic_element_alive(QPointF * point):Graphic_element(point)
{

}
