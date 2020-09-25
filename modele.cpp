#include "modele.h"
#include "Player.h"
#include "wall.h"
#include "floore.h"
#include "screen.h"
#include "QDebug"
#include "QLabel"

Modele::Modele()
{
    // The player
    player = new Player(new QPointF( 450,450));


    // The screenlife
    screen = new Screen(new QPointF( 50,50));
    health = new Health(new QPointF( 50,100));
    number1 = new Number1(new QPointF( 85,105));
    number2= new Number2(new QPointF( 100,105));

    // The monsters
   

    Game_element.append(new Ballon_monster(new QPointF( 400,600))) ;
    Game_element.append(new Patatoes_monster(new QPointF( 1600,600))) ;
    Game_element.append(new Patatoes_monster(new QPointF( 1800,750))) ;
    Game_element.append(new The_Boss(new QPointF( 1000,800))) ;



    Game_element.append(player);


    //The weapons


    // The sounds
    Death_player= new QSoundEffect;
    Death_player->setSource(QUrl::fromLocalFile(":/assets/sound/attaque_epee2.wav"));
    Death_player->setVolume(0.30f);

    // The map
    Mapping(":/assets/map_data/map.json");
    Map_element.append(screen);
    Map_element.append(health);
    Map_element.append(number1);
    Map_element.append(number2);
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


QList<Graphic_element_alive *> Modele::getGame_element()
{   QMutex  mutex ;
    QMutexLocker locker(&mutex);
    return Game_element;
}

void Modele::setGame_element( QList<Graphic_element_alive *> &value)
{   QMutex  mutex ;
    QMutexLocker locker(&mutex);
    Game_element = value;
}

void Modele::RemoveGame_element(Graphic_element_alive * value)
{
    QMutex  mutex ;
        QMutexLocker locker(&mutex);
        Game_element.removeOne(value);
}




void Modele::RemoveProjectile_element(projetile * value)
{
    QMutex  mutex ;
    QMutexLocker locker(&mutex);
    Projectile_element.removeOne(value);
}


void Modele::play_sound()
{
    Death_player->play();
}


QList<projetile *> Modele::getProjectile_element()
{
    QMutex  mutex ;
    QMutexLocker locker(&mutex);
    return Projectile_element;
}


void Modele::addProjectile(projetile * value)
{
    QMutex  mutex ;
    QMutexLocker locker(&mutex);
    Projectile_element.append(value);
}

coffre::coffre(QPointF *point):Graphic_element(point)
{
    setDrawing(new QPixmap(":/chest.png"));
}
