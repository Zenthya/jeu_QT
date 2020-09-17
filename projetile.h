#ifndef PROJETILE_H
#define PROJETILE_H

#include <QThread>
#include <QGraphicsRectItem>


class projetile : public QThread , public QGraphicsRectItem
{

    Q_OBJECT


signals :
    void timer ();

public:
    projetile(QGraphicsRectItem *Rect,QPointF* poseSouris );
    void run();
private :
    qreal YPos = 10;
    qreal XPos = -10;

public slots :
     void move();
};

#endif // PROJETILE_H
