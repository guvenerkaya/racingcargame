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

class map: public QGraphicsView
{
    public:
            map(int selectedCar, int selectedMap);
            QGraphicsScene *scene;
            QGraphicsPixmapItem *backGround;
            car   *myCar;
            decor *myTree,   *myTree2, *myTree3,
                  *myTree4,  *myTree5,*myTree6,
                  *myTree7, *myGstand,*myGstand2,
                  *myRock,  *myPav,  *myPav2,
                  *myWater,*myWater2, *myTree8,*myTree9;

            road  *road_1,*road_2,*road_3,
                  *road_4,*road_5,*road_6,
                  *road_7,*road_8,*road_9,
                  *road_10,*road_11;

            void map1(int selectedCar);
            void map2(int selectedCar);
            void map3(int selectedCar);

         Health * lives;
};

#endif // MAP_H
