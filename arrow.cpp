#include "arrow.h"

arrow::arrow(QPointF *point,QPointF * Souris):projetile(point,Souris,2)
{

    setDrawing(new QPixmap(":image/arrow.png"));

}
