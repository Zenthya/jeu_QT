#ifndef MYRECT_H
#define MYRECT_H



#include <QKeyEvent>
#include <QtMath>

#include <QGraphicsScene>
#include <QPointF>
#include<entity.h>
#include<weapon.h>


class Player :  public Entity{
Q_OBJECT


public:
    void  keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    Weapon * Weapon  ;

    Player(QGraphicsScene *Scene);
private :
    int Key[4];
    QPointF  poseSouris ;


public slots :
    void sourispressed();
    void move();

};





#endif // MYRECT_H
