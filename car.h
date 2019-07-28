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
///
/// \brief The car class makes the car object to race, all with it's methodes and attributes.
///
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
    ///
    /// \brief health is a pointer from the class "Health", so that we can change the Lives shown while playing according to the events of the car object.
    ///
    Health *health;
    ///
    /// \brief leftTime is a pointer from the class Timer, so that we can change the Timer shown while playing by using it's timer() method in render() function of the car object.
    ///
    Timer * leftTime;
    ///
    /// \brief car starts a timer and connects it with render() function.
    /// \param parent is QGraphicsItem, from which QGraphicsPixmapItem is also derived.
    /// \param roadArray allows that the insideroad function can check if the roadArray consist the current x and y position of the car.
    /// \param decorArray allows that the crashed function can check if the decorArray consist the current x and y position of the car.
    ///
    car(QGraphicsItem*parent =0, road roadArray[]=0, int decorArray[] = 0);
    ///
    /// \brief keyPressEvent uses the key presses by it's pointer event.
    /// \param event are the key presses from the keyboard.
    ///
    void keyPressEvent(QKeyEvent*event);
    ///
    /// \brief keyReleaseEvent points the key presses into "event".
    /// \param events are pointed as keys are released.
    ///
    void keyReleaseEvent(QKeyEvent*event);
    ///
    /// \brief current_x is the current position x of the car.
    ///
    float current_x;
    ///
    /// \brief current_y is the current position y of the car.
    ///
    float current_y;
    ///
    /// \brief insideRoad checks if the car is on the road.
    /// \param roadArray sets an empty road array.
    /// \return false if the car is out of the road (rectangles) and car drives slower.
    ///
    bool insideRoad(road roadArray[]);
    ///
    /// \brief crashed compares if the car's position and position of the decor objects are same.
    /// \param decorArray sets an empty decor array.
    /// \returns true if the positions fit into one another.
    ///
    bool crashed(int decorArray[]);
    ///
    /// \brief roadArray  has a capacity of 15.
    ///
    road roadArray[15];
    ///
    /// \brief decorArray has a capacity of 30.
    ///
    int decorArray[30];
    ///
    /// \brief insideMap checks if the car is in the game scene as it can go off the scene's viewed part.
    /// \return false if the car is out of the game scene.
    ///
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
    ///
    /// \brief render function is called in every 40 seconds to check car's events.
    ///
    void render();

};

#endif // CAR_H
