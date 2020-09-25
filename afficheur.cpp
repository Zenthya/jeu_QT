#include "afficheur.h"
#include<QDebug>



Afficheur::Afficheur(QWidget *parent):QGraphicsView(parent)
{
    setMouseTracking(true);
    setFixedSize(1920,1080);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Afficheur::setModele(Modele * setter)
{
    modele = setter;
}

Modele* Afficheur::getModele(){
    return modele;
}








