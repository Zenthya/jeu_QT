#include "modele.h"
#include "player.h"
#include "wall.h"
#include "floore.h"


Modele::Modele()
{
    player = new Player(new QPointF( 450,450));



    Mapping(":map/map.json");


}

void  Modele::Mapping(QString datafile)
{

    QString val;
    QFile file;
    file.setFileName(datafile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("layers"));
    QJsonArray item = value[0].toObject().value(QString("data")).toArray();
    int position_x = 0;
    int position_y = 0;
    for(int j = 0; j < 1177; j++) {
    if (item[j] == 1)
    {
    Wall *wall =new Wall(new QPointF(position_x,position_y),0);
        Map_element.append(wall);
    }
    else if (item[j] == 2)
    {
    Wall *wall =new Wall(new QPointF(position_x,position_y),2);
    Map_element.append(wall);
    }
    else if (item[j] == 3)
    {
    Floore *floor =new Floore( new QPointF(position_x,position_y));
    Map_element.append(floor);
    }
    else if (item[j] == 4)
    {
    Wall *wall =new Wall(new QPointF(position_x,position_y),1);
    Map_element.append(wall);

    }
    else if (item[j] == 5)
    {
    Background *background =new Background(new QPointF(position_x,position_y),2);
    Map_element.append(background);
    }
    else if (item[j] == 6)
    {
        Background *background =new Background(new QPointF(position_x,position_y),0);
        Map_element.append(background);;
    }
    else if (item[j] == 7)
    {
        Background *background =new Background(new QPointF(position_x,position_y),1);
        Map_element.append(background);
    }
    else if (item[j] == 8)
    {
    Background *background =new Background(new QPointF(position_x,position_y),3);
    Map_element.append(background);
    }
    else if (item[j] == 9)
    {
    Wall *wall =new Wall(new QPointF(position_x,position_y),3);
    Map_element.append(wall);
    }
    position_x = position_x + 200;
    if (position_x >= 8400)
    {

    position_x = 0;
    position_y = position_y + 200;
    }
    }



}

void Modele::RemoveProjectile_element(projetile * value)
{   QMutex  mutex ;
    QMutexLocker locker(&mutex);
    Projectile_element.removeOne(value);
}

QList<projetile *> Modele::getProjectile_element()
{   QMutex  mutex ;
    QMutexLocker locker(&mutex);
    return Projectile_element;
}



void Modele::addProjectile(projetile * value)
{   QMutex  mutex ;
    QMutexLocker locker(&mutex);
    Projectile_element.append(value);
}
