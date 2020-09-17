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
    projetile(QGraphicsRectItem *Rect);
    void run();
public slots :
     void move();
};

#endif // PROJETILE_H
