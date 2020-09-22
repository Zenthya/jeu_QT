#ifndef CONTTROLLEUR_H
#define CONTTROLLEUR_H


#include <QThread>
#include "afficheur.h"
#include "modele.h"

class Afficheur;

class Conttrolleur : public QThread
{


public:
    Conttrolleur();
    void run();
    void setModele(Modele *);
    Modele * getModele();
    void ReveivceEvent (QEvent *event);

    Afficheur  * Afficheur;


private :

    void Deplacementjoueur(QString );
    Modele * modele ;
};

#endif // CONTTROLLEUR_H
