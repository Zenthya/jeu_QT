#include "entity.h"
#include<floor.h>
#include<QGraphicsScene>

Entity::Entity()
{

}

Entity::Entity(QPointF * pos)
{

    setPos(*pos);


}



int Entity::CollisionDetector(){
    QList<QGraphicsItem*> collisionItem = collidingItems(Qt::IntersectsItemBoundingRect);

            for(int i ; i < collisionItem.length();i++){

                if(typeid (*collisionItem[i]) == typeid(Floor)){
                    return 1;
                }else if (typeid (*collisionItem[i]) == typeid(this)){
                return 2 ;}


            }

    return 0;



}
