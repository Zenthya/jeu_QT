#include "arrow.h"

arrow::arrow(QPointF *point,QPointF * Souris):projetile(point,Souris)
{

    setDrawing(new QPixmap(":image/arrow.png"));

}
