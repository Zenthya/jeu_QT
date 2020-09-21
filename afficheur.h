#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <QGraphicsView>
#include<controller.h>
#include<modele.h>
#include <QGraphicsSceneMouseEvent>

class ModifiedScene :public QGraphicsScene {
    Q_OBJECT
signals:
      void mousepose(QPointF *);
      void mousepressed();

  public :
    ModifiedScene(QObject *parent =0);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void  setModele( Modele *);
    Modele * getModele();

  private :
      //Controller  * Controller;
      Modele * modele;
protected:
      void drawBackground(QPainter * ,const QRectF &);


};

class Afficheur: public QGraphicsView
{
public:
  Afficheur(QWidget *parent = 0);
  void  setModele( Modele *);
  Modele * getModele();
  ModifiedScene * Scene;
    
private :
    //Controller  * Controller;
    Modele * modele;

};




#endif // AFFICHEUR_H
