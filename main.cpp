

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Player.h>
#include <mouscontroller.h>
#include "scenemoussed.h"
#include <QPushButton>
#include <wall.h>
#include <wall_face.h>
#include <floor.h>
#include <QObject>


int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    // la scene
    scenemoussed *kiki = new scenemoussed;

    // rectangle pour commencer
   Player * rect = new Player(kiki);
    kiki->addItem(rect);
    rect->Weapon= new Bow(kiki);

   //section test de carte
    Wall *wall1 =new Wall_face();
    Wall *wall_face =new Wall_face();

    kiki ->addItem(wall1);
    kiki->addItem(wall_face);
    wall1->setPos(400,200);
    wall_face->setPos(450,200);


    Floor  *floore1 = new Floor(QPointF(400,250));
    Floor  *floore2 = new Floor(QPointF(450,250));
    Floor  *floore3 = new Floor(QPointF(400,300));
    Floor  *floore4 = new Floor(QPointF(450,300));
    kiki->addItem(floore1);
    kiki->addItem(floore2);
    kiki->addItem(floore3);
    kiki->addItem(floore4);



    //activation de la souris
    MousController * mouse = new MousController() ;
    mouse->setScene(kiki);

    // l'item a besoin d'être focus pour recevoir des events
    rect->setFlags(QGraphicsItem :: ItemIsFocusable);


    rect->setFocus();

    mouse->centerOn(rect);
    mouse->show();


    return a.exec();
}
