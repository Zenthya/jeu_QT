#ifndef PROJETILE_H
#define PROJETILE_H


#include <graphic_element.h>

class projetile : public Graphic_element{






public:
    projetile(QPointF *point,QPointF *Souris,int);
    void run();
    void setDrawing(QPixmap *);

    QVector2D  * Position ;
    qreal XPos;
    qreal YPos;
    qreal vitesse =10;
    qreal angle =0 ;
    int lifetime = 600;
    QPointF *Souris;
    int dmg;



};

#endif // PROJETILE_H
