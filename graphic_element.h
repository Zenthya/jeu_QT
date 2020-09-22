#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H
#include<QPointF>
#include<QMutex>
#include <QPixmap>
class Graphic_element
{
public:
    Graphic_element(QPointF *);
    QMutex mutex;

    QPointF &  getCoordonnee() ;
    void setCoordonnee( QPointF *value);

    QPixmap & getDrawing() ;
   virtual void setDrawing( QPixmap  *value);
    virtual QString type();

private :
    QPointF* Coordonnee;
    QPixmap*  Drawing;

};

#endif // GRAPHIC_ELEMENT_H
