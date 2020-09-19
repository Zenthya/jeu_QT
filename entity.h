#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QThread>


class Entity : public QThread ,public QGraphicsPixmapItem
{
public:
    Entity();
    Entity(QPointF*);

    int CollisionDetector();
};

#endif // ENTITY_H
