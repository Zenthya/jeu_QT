#ifndef CONTTROLLEUR_H
#define CONTTROLLEUR_H


#include <QThread>
#include "afficheur.h"
#include "modele.h"

class Afficheur;

class Conttrolleur : public QThread
{
    Q_OBJECT

public:
    Conttrolleur();
    void run();
    void setModele(Modele *);
    Modele * getModele();
    void ReveivceEvent (QEvent *event);

    Afficheur  * Afficheur;


private :
    QList<QString *> Key;
    QString Haut = "haut";
    QString Bas = "bas";
    QString Gauche = "gauche";
    QString Droite = "droite";
    void Deplacementjoueur(QString * );
    bool Controle_out_map(QPointF );
    bool player_attack();
    void animate_player_sword(int,bool);
    Modele * modele ;


 signals :
     void sound_death();
};

#endif // CONTTROLLEUR_H
