#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include "road.h"
#include "health.h"

class car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    int l=0,r=0;
    QPixmap pixmap;
    QTimer * plotTimer;
    Health *lives;
public:
    car(QGraphicsItem*parent =0, road roadArray[]=0, int decorArray[] = 0);
    void drawFerrari();
    void drawMercedes();
    void drawRedbull();
    void keyPressEvent(QKeyEvent*event);
    void keyReleaseEvent(QKeyEvent*event);
    //float newX,newY;
    float current_x;
    float current_y;
    bool insideRoad(road roadArray[]);
    bool crashed(int decorArray[]);
    road roadArray[15];
    int decorArray[30];
    bool insideMap();


private:
    int R,D,L,U;
public slots:
    void render();

};

#endif // CAR_H
