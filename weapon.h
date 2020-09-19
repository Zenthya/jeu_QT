#ifndef WEAPON_H
#define WEAPON_H

#include <QGraphicsScene>
#include <QObject>
#include<projetile.h>


class  Weapon : public QObject
{

    Q_OBJECT

public:
    Weapon(QGraphicsScene *Scene);
    QPointF sourispose ;
    QGraphicsScene *Scene;
    virtual void fire(QGraphicsPixmapItem* );

public slots :
     void  souris(QPointF *);

};



class Bow : public Weapon {
     Q_OBJECT
public :
    Bow(QGraphicsScene *Scene);
    void fire(QGraphicsPixmapItem *);

};

#endif // WEAPON_H
