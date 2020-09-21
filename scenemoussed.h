#ifndef SCENEMOUSSED_H
#define SCENEMOUSSED_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class scenemoussed : public QGraphicsScene
{
    Q_OBJECT
signals:
      void mousepose(QPointF *);
      void mousepressed();

public:
    scenemoussed(QObject*parent =0);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
protected:
      void drawBackground(QPainter * ,const QRectF &);
};

#endif // SCENEMOUSSED_H
