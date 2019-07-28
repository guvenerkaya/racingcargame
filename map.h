#ifndef MAP_H
#define MAP_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "car.h"
#include <QGraphicsItem>
#include "decor.h"
#include "road.h"
#include "health.h"
#include "timer.h"
#include "map.h"

///
/// \brief The map class creates the game scene, makes the game maps and puts the map and the car into the scene
///
class map: public QGraphicsView
{
    //,long long int startTime=0;
    public:
    ///
    /// \brief map puts the chosen map and car on the scene.
    /// \param selectedCar chosen car added on the scene.
    /// \param selectedMap chosen map added on the scene.
    ///
            map(int selectedCar, int selectedMap);
            ///
            /// \brief scene in order to put everything on a scene(car, map, collision objects such as rocks, water ..etc. we are using the QGraphicsscene class.
            ///
            QGraphicsScene *scene;
            ///
            /// \brief backGround for each map we are using 3 different map images as backgrounds and put collision objects on it.
            ///
            QGraphicsPixmapItem *backGround;
            ///
            /// \brief myCar we are setting the position of the car,adding it on the scene, and make it focusable to be able to move it with arrow keys.
            ///
            car   *myCar;
            ///
            /// \brief myTree, myWater, myGstand and myFinish are  stand for the added objects on the map.
            ///
            decor *myTree,   *myTree2, *myTree3,
                  *myTree4,  *myTree5,*myTree6,
                  *myTree7, *myGstand,*myGstand2,
                  *myRock,  *myPav,  *myPav2,
                  *myWater,*myWater2, *myTree8,*myTree9,
                  *myWater3,*myWater4,
                  *myWater5,*myWater6,*myWater7,
                  *myWater8,*myGstand3,*myGstand4,
                  *myFinish;
            ///
            /// \brief road_1 and the other road_s are stand for the rectangle
            ///
            road  *road_1,*road_2,*road_3,
                  *road_4,*road_5,*road_6,
                  *road_7,*road_8,*road_9,
                  *road_10,*road_11;
            ///
            /// \brief map1 according to selection, it  changes background of the scene, puts collision objects in different positions, loads the correct pixmap of the car and puts it on the scene, shows dynamic lives /timers labels on the scene
            /// \param selectedCar each map has 3 of the cars, according to the selection only one car will be put on the scene
            ///
            void map1(int selectedCar);
            void map2(int selectedCar);
            void map3(int selectedCar);
            ///
            /// \brief health pointer of the class Health is also in class map, so that we can set the health to be shown in map class according the myCar's events (by using myCar->health=health in map.cpp).
            ///
         Health * health;
         ///
         /// \brief leftTime pointer of the class Timer is also in class map, so that we can set the timer to be shown in map class according the myCar's events (by using myCar->leftTime=leftTime in map.cpp).
         ///
         Timer *  leftTime;


    public slots:
};

#endif // MAP_H
