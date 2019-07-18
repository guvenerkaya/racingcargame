#include "map.h"
#include <QImage>
#include "decor.h"
#include "selectgameobjectdialog.h"
#include <QMediaPlayer>
#include "QLabel"
#include "road.h"
#include "gameover.h"

map::map(int selectedCar, int selectedMap)
{
    if(selectedMap==0)
        map1(selectedCar);

    else if (selectedMap==1)
        map2(selectedCar);

    else if (selectedMap==2)
        map3(selectedCar);

    //QObject::connect(myCar, SIGNAL(carIsDead()), this, SLOT(map::carHasDied()));
}
void map::map1(int selectedCar)
{
 health=new Health();

//if its still alive
  if(health->getHealth()>0)
  {
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    QGraphicsPixmapItem* backGround ;
    backGround= scene->addPixmap(QPixmap(":/map_images/map2.png"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    road_1 = new road(1,560,100,-10);  //roadun bölündügü dikdörtgenlerin koordinatları
    road_2 = new road(101,107,234,-10);
    road_3 = new road(234,287,342,-10);
    road_4 = new road(350,287,502,185);
    road_5 = new road(502,185,591,32);
    road_6 = new road(591,450,750,32);
    road_7 = new road(310,510,591,353);
    road_8 = new road(101,510,310,353);
    road_9 = new road(350,185,501,60);

    road roadArray[] = {*road_1,*road_2,*road_3,
                        *road_4,*road_5,*road_6,
                        *road_7,*road_8,*road_9};

    //creating decors
    myTree=new decor(0,1);
    myTree->setPos(450,330);
    myTree2=new decor(0,1);
    myTree2->setPos(570,220);
    myTree3=new decor(0,1);
    myTree3->setPos(550,250);
    myTree4=new decor(0,1);
    myTree4->setPos(530,280);
    myTree5=new decor(0,1);
    myTree5->setPos(500,310);

    int myTree_x = 450;
    int myTree_y = 330;
        int myTree2_x = 570;
        int myTree2_y = 220;
            int myTree3_x = 550;
            int myTree3_y = 250;
                int myTree4_x = 530;
                int myTree4_y = 280;
                    int myTree5_x = 500;
                    int myTree5_y = 310;

                        int myTree6_x = 160;
                        int myTree6_y = 325;
                            int myTree7_x = 210;
                            int myTree7_y = 325;
                                int myTree8_x =260;
                                int myTree8_y = 325;

                                    int myTree9_x = 310;
                                    int myTree9_y = 325;
                                        int myTree10_x = 350;
                                        int myTree10_y = 325;
                                            int myTree11_x = 390;
                                            int myTree11_y = 325;

                                                int myGstand_x = 140;
                                                int myGstand_y = 140;
                                                    int myGstand2_x = 140;
                                                    int myGstand2_y = 190;
                                                        int myGstand3_x = 140;
                                                        int myGstand3_y = 240;


    int decorArray[] = {myGstand_x, myGstand_y,myGstand2_x, myGstand2_y,myGstand3_x, myGstand3_y,
                        myTree_x, myTree_y, myTree2_x, myTree2_y,
                        myTree3_x, myTree3_y,myTree4_x, myTree4_y,myTree5_x, myTree5_y,
                        myTree6_x, myTree6_y, myTree7_x, myTree7_y, myTree8_x, myTree8_y,
                        myTree9_x, myTree9_y,myTree10_x, myTree10_y,myTree11_x, myTree11_y};

    myRock=new decor(0,2);
    myRock->setPos(160,340);
        myPav=new decor(0,5);
        myPav->setPos(310,340);
        myPav2=new decor(0,6);
        myPav2->setPos(200,330);
            myGstand=new decor(0,3);
            myGstand->setPos(160,140);
            myGstand2=new decor(0,3);
            myGstand2->setPos(160,230);

    scene->addItem(myTree);
    scene->addItem(myTree2);
    scene->addItem(myTree3);
    scene->addItem(myTree4);
    scene->addItem(myTree5);
    scene->addItem(myRock);
    scene->addItem(myGstand);
    scene->addItem(myGstand2);
    scene->addItem(myPav);
    scene->addItem(myPav2);
    //show();

    //creating the car
    myCar=new car(0 ,roadArray, decorArray);
    myCar->health = health;

    if(selectedCar == 0)
    {
        QPixmap pixmap = QPixmap(":/car_images/ferrari.png");
        myCar->setPixmap(pixmap);
        myCar->setTransformOriginPoint(pixmap.width()/2,pixmap.height()/2);
    }
    if(selectedCar == 1)
    {
        QPixmap pixbok = QPixmap(":/car_images/mercedes.png");
        myCar->setPixmap(pixbok);
        myCar->setTransformOriginPoint(pixbok.width()/2,pixbok.height()/2);
    }
    if(selectedCar == 2)
    {
        QPixmap pixbok = QPixmap(":/car_images/redbull.png");
        myCar->setPixmap(pixbok);
        myCar->setTransformOriginPoint(pixbok.width()/2,pixbok.height()/2);
    }

    myCar->setPos(49,324);
    myCar->setFlag(QGraphicsItem::ItemIsFocusable);
    myCar->setFocus();
    scene->addItem(myCar);

    //set the position of lives:.. and add it to scene
    health->setPos(700,14);
    scene->addItem(health);

    //play car sound
    QMediaPlayer* carSound=new QMediaPlayer();
    carSound->setMedia(QUrl("qrc:/soundEffects/carSound.mp3"));
    carSound->play();

    show();
 }

  //if its not alive

}


void map::map2(int selectedCar)
{
   health = new Health();

    if(health->getHealth()>0)
    {

    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    QGraphicsPixmapItem* backGround ;
    backGround= scene->addPixmap(QPixmap(":/map_images/map_3.png"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    road_1 = new road(75,500,690,420);
    road_2 = new road(690,500,740,230);
    road_3 = new road(570,300,690,230);
    road_4 = new road(470,180,630,65);
    road_5 = new road(630,180,720,0);
    road_6 = new road(63,65,620,0);
    road_7 = new road(-15,170,63,0);
    road_8 = new road(51,174,230,110);
    road_9 = new road(230,370,340,110);
    road_10 = new road(80,370,230,280);
    road_11 = new road(-15,500,80,280);


    road roadArray[] = {*road_1,*road_2,*road_3,
                        *road_4,*road_5,*road_6,
                        *road_7,*road_8,*road_9,
                        *road_10,*road_11};


    //water collision
    int myTree_x = 20;
    int myTree_y = 230;
    int myTree2_x = 70;
    int myTree2_y = 230;
    int myTree3_x = 120;
    int myTree3_y = 230;
    int myTree4_x = 170;
    int myTree4_y = 230;
    int myTree5_x = 200;
    int myTree5_y = 230;
    int decorArray[] = {myTree_x, myTree_y,myTree2_x, myTree2_y,myTree3_x, myTree3_y,
                        myTree4_x, myTree4_y,myTree5_x, myTree5_y};


    //creating decors
    myWater=new decor(0,4);
    myWater->setPos(100,230);
    scene->addItem(myWater);
    myWater2=new decor(0,4);
    myWater2->setPos(20,230);
    scene->addItem(myWater2);
        myRock=new decor(0,2);
        myRock->setPos(270,30);
        scene->addItem(myRock);
           // show();

    //creating the car
    myCar=new car(0, roadArray, decorArray);
    myCar->health = health;

    if(selectedCar == 0)
    {
        QPixmap pixmap = QPixmap(":/car_images/ferrari.png");
        myCar->setPixmap(pixmap);
        myCar->setTransformOriginPoint(pixmap.width()/2,pixmap.height()/2);
    }

    if(selectedCar == 1)
    {
        QPixmap pixbok = QPixmap(":/car_images/mercedes.png");
        myCar->setPixmap(pixbok);
        myCar->setTransformOriginPoint(pixbok.width()/2,pixbok.height()/2);
    }

    if(selectedCar == 2)
    {
        QPixmap pixbok = QPixmap(":/car_images/redbull.png");
        myCar->setPixmap(pixbok);
        myCar->setTransformOriginPoint(pixbok.width()/2,pixbok.height()/2);
    }

    myCar->setPos(29,394);
    myCar->setFlag(QGraphicsItem::ItemIsFocusable);
    myCar->setFocus();
    scene->addItem(myCar);

    health->setPos(700,14);
    scene->addItem(health);

    QMediaPlayer* carSound=new QMediaPlayer();
    carSound->setMedia(QUrl("qrc:/soundEffects/carSound.mp3"));
    carSound->play();

    show();
    }
    //if it died
     if(health->getHealth()==0)
     {
         //show game over screen
         gameOver *gameOverScene=new gameOver();
         gameOverScene->exec();
     }
}

void map::map3(int selectedCar)
{
  health=new Health();

   if(health->getHealth()>0)
   {

    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    QGraphicsPixmapItem* backGround;
    backGround= scene->addPixmap(QPixmap(":/map_images/izi.png"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    road_1 = new road(75,500,690,420);
    road_2 = new road(690,500,740,230);
    road_3 = new road(570,300,690,230);
    road_4 = new road(470,180,630,65);
    road_5 = new road(630,180,720,0);
    road_6 = new road(63,65,620,0);
    road_7 = new road(-15,170,63,0);
    road_8 = new road(51,174,230,110);
    road_9 = new road(230,370,340,110);
    road_10 = new road(80,370,230,280);
    road_11 = new road(-15,500,80,280);


    road roadArray[] = {*road_1,*road_2,*road_3,
                        *road_4,*road_5,*road_6,
                        *road_7,*road_8,*road_9,
                        *road_10,*road_11};

    int decorArray[] = {};

    //creating decors
    myTree=new decor(0,1);
    myTree->setPos(450,280);
    scene->addItem(myTree);

    //creating the car
    myCar=new car(0,roadArray,decorArray);
    myCar->health = health;

    if(selectedCar == 0)
    {
        QPixmap pixmap = QPixmap(":/car_images/ferrari.png");
        myCar->setPixmap(pixmap);
        myCar->setTransformOriginPoint(pixmap.width()/2,pixmap.height()/2);
    }
    if(selectedCar == 1)
    {
        QPixmap pixbok = QPixmap(":/car_images/mercedes.png");
        myCar->setPixmap(pixbok);
        myCar->setTransformOriginPoint(pixbok.width()/2,pixbok.height()/2);
    }
    if(selectedCar == 2)
    {
        QPixmap pixbok = QPixmap(":/car_images/redbull.png");
        myCar->setPixmap(pixbok);
        myCar->setTransformOriginPoint(pixbok.width()/2,pixbok.height()/2);
    }

    myCar->setPos(49,324);
    myCar->setFlag(QGraphicsItem::ItemIsFocusable);
    myCar->setFocus();
    scene->addItem(myCar);


    health->setPos(700,14);
    scene->addItem(health);
   // qDebug()<<"health "<<health;

    QMediaPlayer* carSound=new QMediaPlayer();
    carSound->setMedia(QUrl("qrc:/soundEffects/carSound.mp3"));
    carSound->play();

    show();
    }

    if(health->getHealth()==0)
    {
        //hide();

        gameOver *gameOverScene=new gameOver();
        gameOverScene->exec();
    }
}

void map::carHasDied()
{
    qDebug()<<"Has Died";
    if(health->getHealth()==0)
    {
        //show game over scene
        gameOver *gameOverScene=new gameOver();
        gameOverScene->exec();
    }
}
