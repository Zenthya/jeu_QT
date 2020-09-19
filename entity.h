#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>
#include <QObject>



class Entity :public QObject ,public QGraphicsPixmapItem
{
public:
    Entity();
    Entity(QPointF*);

    int CollisionDetector();
};

#endif // ENTITY_H
