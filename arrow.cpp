#include "arrow.h"

arrow::arrow(QPointF *point,QPointF * Souris):projetile(point,Souris,2)
{

    setDrawing(new QPixmap(":image/arrow.png"));

}
fire_ball::fire_ball(QPointF *point,QPointF * Souris):projetile(point,Souris,1){
    setDrawing(new QPixmap(":/images/weapon/fire_ball.png"));
}
