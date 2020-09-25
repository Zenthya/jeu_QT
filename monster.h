#ifndef MONSTER_H
#define MONSTER_H
#include"graphic_element.h"

class Monster : public Graphic_element_alive
{
public:
    Monster(QPointF *,int );

};


class Ballon_monster :public Monster{

public :
    Ballon_monster(QPointF* point):Monster(point,10){


    };
    QString type(){
        return "monster/monster_baloon";
    };

};

class Patatoes_monster :public Monster{

public :

    Patatoes_monster(QPointF* point);


    QString type(){
        return "monster/monster_potatoes";
    };


};
class The_Boss:public Monster{
     public:
    The_Boss(QPointF *);
    int status ;
    QString type(){
        return "monster/boss/boss_3";
    }

};

#endif // MONSTER_H
