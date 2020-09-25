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
    void animate_player_attack(int,bool);
    Modele * modele ;
    void MousePressDetection(QEvent *event);
    void UpdateScreenPosition(QPointF position_screen, QPointF position_player);

signals :
    void sound_death();
};


#endif // CONTTROLLEUR_H
