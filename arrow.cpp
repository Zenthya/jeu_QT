#include "arrow.h"

arrow::arrow(QPointF *point,QPointF * Souris):projetile(point,Souris,2)
{
    setDrawing(new QPixmap(":/assets/images/weapon/arrow.png"));
}
fire_ball::fire_ball(QPointF *point,QPointF * Souris):projetile(point,Souris,1){
    setDrawing(new QPixmap(":/assets/images/weapon/fire_ball.png"));
}
big_fire_ball::big_fire_ball(QPointF *point,QPointF * Souris):projetile(point,Souris,3){
    setDrawing(new QPixmap(":/assets/images/weapon/big_fire_ball.png"));
}
