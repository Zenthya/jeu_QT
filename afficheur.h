#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QGraphicsView>
#include<modele.h>
#include "conttrolleur.h"


class Controlleur;

class Afficheur: public QGraphicsView
{

    Q_OBJECT

public slots :
    void update();
public:
    Afficheur(QWidget *parent = 0);
    void  setModele( Modele *);
    Modele * getModele();

private :
    Modele * modele;
};


#endif // AFFICHEUR_H
