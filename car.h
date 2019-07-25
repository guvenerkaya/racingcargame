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
#include "timer.h"
#include <QMediaPlayer>

class car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

    //to calculate the correct angle for the car rotation..
    //we are storing the right( r)/left(l) click numbers starting with 0
    int l=0,r=0;

    QPixmap pixmap;
    QTimer * plotTimer;
    gameOver *gameOverDialog;
    GameWonDialog *gameWon;
    bool ch1passed = false, ch2passed = false, sppassed = false;
    QMediaPlayer * carcollide;

public:
    Health *health;
    Timer * leftTime;
    car(QGraphicsItem*parent =0, road roadArray[]=0, int decorArray[] = 0);
    void keyPressEvent(QKeyEvent*event);
    void keyReleaseEvent(QKeyEvent*event);
    float current_x;
    float current_y;
    bool insideRoad(road roadArray[]);
    bool crashed(int decorArray[]);
    road roadArray[15];
    int decorArray[30];
    bool insideMap();

private:
    int R,D,L,U;

    //3 rounds completed
    void roundsCompleted();

    //controle points, that the car should pass in order to complete 1 round
    int checkPoint1=0,checkPoint2=0,startPoint=0;

    //checking if the car has passed by the controle points
    int checkPoint_1_Passed();
    int startPointPassed();
    int checkPoint_2_Passed();

public slots:
    void render();

};

#endif // CAR_H
