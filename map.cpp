#include "map.h"
#include <QImage>
#include "decor.h"
#include "selectgameobjectdialog.h"
#include <QMediaPlayer>
#include "QLabel"
#include "road.h"
#include <QMediaPlaylist>

map::map(int selectedCar, int selectedMap)
{
    //start game with the selected car and map
    if(selectedMap==0)
        map1(selectedCar);

    else if (selectedMap==1)
        map2(selectedCar);

    else if (selectedMap==2)
        map3(selectedCar);


}
void map::map1(int selectedCar)
{

    health = new Health();
    leftTime = new Timer();


    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    QGraphicsPixmapItem* backGround ;
    backGround= scene->addPixmap(QPixmap(":/map_images/map2.png"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Jede Rennstrecke teilt sich in Rechtecken mit unterschiedlichen Größen
    road_1 = new road(1,560,100,-10);
    road_2 = new road(101,107,234,-10);
    road_3 = new road(234,287,342,-10);
    road_4 = new road(350,287,502,185);
    road_5 = new road(502,185,591,32);
    road_6 = new road(591,450,750,32);
    road_7 = new road(310,510,591,353);
    road_8 = new road(101,510,310,353);
    road_9 = new road(350,185,501,60);


    //und wwurde an einem roadArray gespeicher, damit wir die Grenzen bestimmen können
    road roadArray[] = {*road_1,*road_2,*road_3,
                        *road_4,*road_5,*road_6,
                        *road_7,*road_8,*road_9};


    //creating decors
    myTree=new decor(0,1);
    myTree->setPos(450,330);
    scene->addItem(myTree);
    myTree2=new decor(0,1);
    myTree2->setPos(570,220);
    scene->addItem(myTree2);
    myTree3=new decor(0,1);
    myTree3->setPos(550,250);
    scene->addItem(myTree3);
    myTree4=new decor(0,1);
    myTree4->setPos(530,280);
    scene->addItem(myTree4);
    myTree5=new decor(0,1);
    myTree5->setPos(500,310);
    scene->addItem(myTree5);

     //Viele unterschiedliche Collisionpunkte wurden bestimmt und im decorArray gespeichert.
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


    scene->addItem(myRock);
    scene->addItem(myGstand);
    scene->addItem(myGstand2);
    scene->addItem(myPav);
    scene->addItem(myPav2);
    //show();

    //creating the car
    myCar=new car(0 ,roadArray, decorArray);
    myCar->health = health;
    myCar->leftTime=leftTime;
    leftTime->leftTime=40;


    //load the pixmap image according to the selection of the player
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
    leftTime->setPos(650,40);
    scene->addItem(leftTime);

    //play car sound
    QMediaPlayer* carSound=new QMediaPlayer();
    carSound->setMedia(QUrl("qrc:/soundEffects/carSound.mp3"));
    carSound->play();

    show();
 }
void map::map2(int selectedCar)
{
   health = new Health();
   leftTime = new Timer();

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

    road_1 = new road(0,600,800,0);
   /* road_2 = new road(690,500,740,230);
    road_3 = new road(570,300,690,230);
    road_4 = new road(470,180,630,65);
    road_5 = new road(630,180,720,0);
    road_6 = new road(63,65,620,0);
    road_7 = new road(-15,170,63,0);
    road_8 = new road(51,174,230,110);
    road_9 = new road(230,370,340,110);
    road_10 = new road(80,370,230,280);
    road_11 = new road(-15,500,80,280);*/


    road roadArray[] = {*road_1};/**road_2,*road_3,
                        *road_4,*road_5,*road_6,
                        *road_7,*road_8,*road_9,
                        *road_10,*road_11};*/


    /*//water collision
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
                        myTree4_x, myTree4_y,myTree5_x, myTree5_y};*/


    //creating decors
    myWater=new decor(0,4);
    myWater->setPos(100,230);
    scene->addItem(myWater);
    myWater2=new decor(0,4);
    myWater2->setPos(20,230);
    scene->addItem(myWater2);
    myFinish=new decor(0,9);
    myFinish->setPos(24,350);
    scene->addItem(myFinish);

    //cit collision
    int myCit_x = 120;
    int myCit_y = 400;
    int myCit2_x = 200;
    int myCit2_y = 400;
    int myCit3_x = 280;
    int myCit3_y = 400;
    int myCit4_x = 360;
    int myCit4_y = 400;
        int myCit5_x = 400;
        int myCit5_y = 390;
        int myCit6_x = 480;
        int myCit6_y = 390;
        int myCit7_x = 560;
        int myCit7_y = 390;
        int myCit8_x = 620;
        int myCit8_y = 390;
            int myCit9_x = 360;
            int myCit9_y = 120;
            int myCit10_x = 360;
            int myCit10_y = 220;
            int myCit11_x = 360;
            int myCit11_y = 320;
           // show();

            //water collision
            int myWater_x = 40;
            int myWater_y = 230;
            int myWater2_x = 120;
            int myWater2_y = 230;
            int myWater3_x = 200;
            int myWater3_y = 230;


            int decorArray[] = {myWater_x, myWater_y,myWater2_x, myWater2_y,myWater3_x, myWater3_y,
                               myCit_x, myCit_y,myCit2_x, myCit2_y,myCit3_x, myCit3_y,myCit4_x,
                               myCit4_y,myCit5_x, myCit5_y,myCit6_x, myCit6_y,myCit7_x, myCit7_y,
                               myCit8_x, myCit8_y,myCit9_x, myCit9_y,myCit10_x, myCit10_y,myCit11_x, myCit11_y};

    //creating the car
    myCar=new car(0, roadArray, decorArray);
    myCar->health = health;
    myCar-> leftTime = leftTime;
    leftTime->leftTime=75;

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

    //add health label to the scene
    health->setPos(700,14);
    scene->addItem(health);
    leftTime->setPos(650,40);
    scene->addItem(leftTime);

    QMediaPlayer* carSound=new QMediaPlayer();
    carSound->setMedia(QUrl("qrc:/soundEffects/carSound.mp3"));
    carSound->play();

    show();
    }

}

void map::map3(int selectedCar)
{
  health=new Health();
  leftTime = new Timer();


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

    road_1 = new road(-5,530,125,-10);
    road_2 = new road(125,70,615,-10);
    road_3 = new road(615,530,740,-10);
    road_4 = new road(125,530,615,440);


    road roadArray[] = {*road_1,*road_2,*road_3,
                        *road_4};

    //creating decors
    myWater=new decor(0,4);
    myWater->setPos(167,120);
    scene->addItem(myWater);
    myWater2=new decor(0,4);
    myWater2->setPos(167,210);
    scene->addItem(myWater2);
    myWater3=new decor(0,4);
    myWater3->setPos(167,300);
    scene->addItem(myWater3);
    myWater4=new decor(0,4);
    myWater4->setPos(167,375);
    scene->addItem(myWater4);
        myWater5=new decor(0,4);
        myWater5->setPos(450,120);
        scene->addItem(myWater5);
        myWater6=new decor(0,4);
        myWater6->setPos(450,210);
        scene->addItem(myWater6);
        myWater7=new decor(0,4);
        myWater7->setPos(450,300);
        scene->addItem(myWater7);
        myWater8=new decor(0,4);
        myWater8->setPos(450,375);
        scene->addItem(myWater8);

            myGstand=new decor(0,8);
            myGstand->setPos(345,125);
            scene->addItem(myGstand);
            myGstand2=new decor(0,8);
            myGstand2->setPos(345,205);
            scene->addItem(myGstand2);
            myGstand3=new decor(0,8);
            myGstand3->setPos(345,285);
            scene->addItem(myGstand3);
            myGstand4=new decor(0,8);
            myGstand4->setPos(345,365);
            scene->addItem(myGstand4);
                myFinish=new decor(0,9);
                myFinish->setPos(24,290);
                scene->addItem(myFinish);
             show();

                int myWater_x = 177;
                int myWater_y = 150;
                int myWater2_x = 177;
                int myWater2_y = 200;
                int myWater3_x = 177;
                int myWater3_y = 250;
                int myWater4_x = 177;
                int myWater4_y = 310;
                int myWater9_x = 190;
                int myWater9_y = 380;
                    int myWater5_x = 540;
                    int myWater5_y = 140;
                    int myWater6_x = 540;
                    int myWater6_y = 190;
                    int myWater7_x = 540;
                    int myWater7_y = 240;
                    int myWater8_x = 540;
                    int myWater8_y = 310;
                    int myWater10_x = 540;
                    int myWater10_y = 370;
                    int myWater11_x = 460;
                    int myWater11_y = 370;
                        int myGstand_x=300;
                        int myGstand_y=100;
                        int myGstand4_x=350;
                        int myGstand4_y=100;
                        int myGstand2_x=300;
                        int myGstand2_y=380;
                        int myGstand3_x=350;
                        int myGstand3_y=380;


                int decorArray[] = {myWater_x, myWater_y,myWater2_x, myWater2_y,myWater3_x, myWater3_y,
                                    myWater4_x, myWater4_y,myWater5_x, myWater5_y,myWater6_x, myWater6_y,
                                    myWater7_x, myWater7_y,myWater8_x, myWater8_y,myWater9_x, myWater9_y,
                                    myGstand_x,myGstand_y,  myGstand2_x,myGstand2_y,myGstand3_x,myGstand3_y,
                                    myWater10_x, myWater10_y,myWater11_x, myWater11_y,myGstand4_x,myGstand4_y};
    //creating the car
    myCar=new car(0,roadArray,decorArray);
    myCar->health = health;
    myCar->leftTime = leftTime;
    leftTime->leftTime=35;

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
    leftTime->setPos(650,40);
    scene->addItem(leftTime);
   // qDebug()<<"health "<<health;

    QMediaPlayer* carSound=new QMediaPlayer();
    carSound->setMedia(QUrl("qrc:/soundEffects/carSound.mp3"));

    carSound->play();
    if(health->getHealth()==0)
    {
        carSound->stop();
    }

    show();
    }

}


