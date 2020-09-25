#ifndef ARROW_H
#define ARROW_H

#include <projetile.h>


class arrow : public projetile
{
public:
    arrow(QPointF *,QPointF *);
};
class fire_ball: public projetile{
public:
    fire_ball(QPointF *,QPointF *);
};


#endif // ARROW_H
