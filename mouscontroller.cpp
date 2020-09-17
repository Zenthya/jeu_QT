#include "mouscontroller.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QEvent>
#include <QScrollBar>





    MousController::MousController(QWidget *parent):QGraphicsView(parent)
{

 setMouseTracking(true);
 setFixedSize(1080,800);
 setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}


