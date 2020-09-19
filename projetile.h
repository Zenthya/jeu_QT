#ifndef PROJETILE_H
#define PROJETILE_H

#include <QThread>
#include <QGraphicsRectItem>


class projetile : public QThread , public QGraphicsPixmapItem
{

    Q_OBJECT


signals :
    void timer ();

public:
    projetile(QGraphicsPixmapItem *Rect,QPointF * Souris);
    void run();
private :
    qreal YPos = 10;
    qreal XPos = -10;
    int lifetime = 0;

public slots :
     void move();

};

#endif // PROJETILE_H
