

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Player.h>
#include <mouscontroller.h>
#include "scenemoussed.h"
#include <QPushButton>
#include <wall.h>
#include <wall_face.h>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    // la scene
    scenemoussed *scene = new scenemoussed;

    // rectangle pour commencer
   Player * rect = new Player(scene);
    Wall *wall1 =new Wall();
    Wall *wall_face =new Wall_face();
    scene->addItem(rect);
    scene ->addItem(wall1);
    scene->addItem(wall_face);
    wall1->setOffset(400,200);
    wall_face->setOffset(450,200);



    //activation de la souris
    MousController * mouse = new MousController() ;
    mouse->setScene(scene);

    // l'item a besoin d'être focus pour recevoir des events
    rect->setFlags(QGraphicsItem :: ItemIsFocusable);

    rect->setFocus();
    mouse->centerOn(rect);
    mouse->show();


    return a.exec();
}
