#include "projetile.h"
#include <QDebug>




projetile::projetile(QGraphicsRectItem *Rect)
{
    setRect(Rect->x(),Rect->y(),10,50);

    connect(this,SIGNAL(timer()),this,SLOT(move()));
    start();
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));

}

void projetile::run()
{

    int time = 0;
    while(time < 400){
        msleep(20);
        emit timer();
        time+=10;
    }

}
 void projetile::move(){
    setPos(x(),y()-9);
}

