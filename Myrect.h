#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QtMath>
#include <QObject>
#include <QGraphicsScene>
class Myrect : public QObject ,public QGraphicsRectItem  {
Q_OBJECT
public:
    void  keyPressEvent(QKeyEvent *event);
    Myrect(QGraphicsScene *Scene);
private :
    QGraphicsScene *Scene;
private slots :
    void rotation(QPointF *pos);
};





#endif // MYRECT_H
