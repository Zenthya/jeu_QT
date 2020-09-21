#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QThread>
#include <afficheur.h>
#include <modele.h>
class Controller : QThread
{


public:
    Controller();
    void run();
    void setModel(Modele *);
    Modele * getModele();


private :

    Modele * modele ;
};

#endif // CONTROLLER_H
