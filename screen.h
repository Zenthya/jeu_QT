#ifndef SCREEN_H
#define SCREEN_H

#include "graphic_element.h"

class Screen : public Graphic_element
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

class Chest : public Screen
{
public:
    Chest(QPointF *);
};


#endif // SCREEN_H
