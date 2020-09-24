#ifndef MONSTER_H
#define MONSTER_H
#include"graphic_element.h"

class Monster : public Graphic_element_alive
{
public:
    Monster(QPointF *,int );

};

#endif // MONSTER_H
