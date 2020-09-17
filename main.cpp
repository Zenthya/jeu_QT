

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Myrect.h>
#include <mouscontroller.h>
#include "scenemoussed.h"
#include <QPushButton>



int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    // la scene
    scenemoussed *scene = new scenemoussed;

    // rectangle pour commencer
    Myrect * rect = new Myrect(scene);

    scene->addItem(rect);


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
