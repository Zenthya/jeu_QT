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
    bool player_attack_chest();
    bool pause_game=true;
    
   
    void MousePressDetection(QEvent *event);
    void UpdateScreenPosition(QPointF position_screen, QPointF position_player);
    void animate_player_sword(int,bool);
    void hurt_animation(Graphic_element_alive *,int *);
    int life_cadence =0;
    Modele * modele ;
    QList<hurt *>List_hurt;

 signals :
     void sound_death();
     void update();
};




#endif // CONTTROLLEUR_H
