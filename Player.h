#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QtMath>
#include <QObject>
#include <QGraphicsScene>
#include <QPointF>
class Player : public QObject ,public QGraphicsPixmapItem  {
Q_OBJECT
public:
    void  keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *event);
    Player(QGraphicsScene *Scene);
private :
    QGraphicsScene *Scene;
    QPointF  poseSouris ;

private slots :
    void rotation(QPointF *pos);
};





#endif // MYRECT_H
