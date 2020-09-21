#include "modele.h"
#include "player.h"

Modele::Modele()
{

    
 wall_element.append(new Wall( new QPointF(150,300)));
 wall_element.append(new Player(new QPointF(100,300)));
}
