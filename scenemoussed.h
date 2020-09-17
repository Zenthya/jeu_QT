#ifndef SCENEMOUSSED_H
#define SCENEMOUSSED_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class scenemoussed : public QGraphicsScene
{
    Q_OBJECT
signals:
      void mousepose(QPointF *);

public:
    scenemoussed(QObject*parent =0);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;
};

#endif // SCENEMOUSSED_H
