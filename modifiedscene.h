#ifndef MODIFIEDSCENE_H
#define MODIFIEDSCENE_H

#include <QGraphicsSceneMouseEvent>
#include<QKeyEvent>
#include <QGraphicsScene>
#include<modele.h>
#include <conttrolleur.h>

class ModifiedScene :public QGraphicsScene {
    Q_OBJECT
signals:
      void mousepose(QPointF *);
      void mousepressed();

  public :
    ModifiedScene(QObject *parent =0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void  setModele( Modele *);
    Modele * getModele();

    Conttrolleur  * Conttrolleur;


private :

    Modele * modele;
protected:
    void drawBackground(QPainter * ,const QRectF &);


};

#endif // MODIFIEDSCENE_H
