#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Player.h>
#include<QObject>
#include <QPushButton>
#include <wall.h>
#include <floore.h>

#include<afficheur.h>
#include<conttrolleur.h>
#include<modele.h>
#include <modifiedscene.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Afficheur  * afficheur = new Afficheur;
    Conttrolleur * controlleur = new Conttrolleur();
    Modele  * modele = new Modele();
    ModifiedScene * scene = new ModifiedScene;
    controlleur->setModele(modele);
    controlleur->Afficheur=afficheur;

    scene->setModele(modele);
    scene->Conttrolleur = controlleur;
    afficheur->setScene(scene);
    afficheur->centerOn(0,0);

    controlleur->start();
    afficheur->show();
    return a.exec();
}

