#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include "road.h"
#include "health.h"
#include "gameover.h"
#include "gamewondialog.h"

class car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    int l=0,r=0;
    QPixmap pixmap;
    QTimer * plotTimer;
    gameOver *gameOverDialog;
    GameWonDialog *gameWon;
    bool ch1passed = false, ch2passed = false, sppassed = false;
    //int lastCheckPoint = 0;
public:
    Health *health;

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
    void roundsCompleted();
    int checkPoint1=0,checkPoint2=0,startPoint=0;
    int checkPoint_1_Passed();
    int startPointPassed();
    int checkPoint_2_Passed();
    bool between_1_2();
    bool between_start_1();
    bool between_2_start();



public slots:
    void render();

signals:
    void carIsDead();
};

#endif // CAR_H
