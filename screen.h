#ifndef SCREEN_H
#define SCREEN_H

#include "graphic_element.h"

class Screen : public Graphic_element_alive
{
public:
    Screen(QPointF *);
};

class Health : public Screen
{
public:
    Health(QPointF *);
};

class Number1 : public Screen
{
public:
    Number1(QPointF *);
};

class Number2 : public Screen
{
public:
    Number2(QPointF *);
};



#endif // SCREEN_H
