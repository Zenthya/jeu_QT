

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Player.h>

#include "scenemoussed.h"
#include <QPushButton>
#include <wall.h>
#include <wall_face.h>
#include <floore.h>
#include <QObject>
#include<afficheur.h>
#include<controller.h>
#include<modele.h>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

            Afficheur  * afficheur = new Afficheur;
            Controller * controlleur = new Controller();
            Modele  *modele =new Modele();
            ModifiedScene * scene = new ModifiedScene;
            scene->setModele(modele);
            afficheur->setScene(scene);
            afficheur->centerOn(0,0);

            afficheur->show();
    
    
    
    
    




//    // rectangle pour commencer
//   Player * rect = new Player(kiki);
//    kiki->addItem(rect);
//    rect->Weapon= new Bow(kiki);
//    rect->start();

//   //section test de carte





//    Floor  *floore1 = new Floor(QPointF(400,250));
//    Floor  *floore2 = new Floor(QPointF(450,250));
//    Floor  *floore3 = new Floor(QPointF(400,300));
//    Floor  *floore4 = new Floor(QPointF(450,300));
//    kiki->addItem(floore1);
//    kiki->addItem(floore2);
//    kiki->addItem(floore3);
//    kiki->addItem(floore4);



//    //activation de la souris
//   MousController * mouse = new MousController() ;
//    mouse->setScene(kiki);

//    // l'item a besoin d'être focus pour recevoir des events
//    rect->setFlags(QGraphicsItem :: ItemIsFocusable);


//    rect->setFocus();

//    mouse->centerOn(rect);
//    mouse->show();


    return a.exec();
}
