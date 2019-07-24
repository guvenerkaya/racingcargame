#include "car.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QtMath>
#include <QMediaPlayer>



car::car(QGraphicsItem * parent,road roadArray[], int decorArray[]): QGraphicsPixmapItem(parent)
{
    for (int x =0 ; x < 10; x++)
    this->roadArray[x] = roadArray[x];
        for (int y =0 ; y < 30; y++)
        this->decorArray[y] = decorArray[y];
    plotTimer = new QTimer(this);
    connect(plotTimer, SIGNAL(timeout()),this, SLOT(render()));
    plotTimer->start(40);

}

void car::keyPressEvent(QKeyEvent *event)
{
    //after initializing the key events, we set the the integers to "1" and then make them stay at value "1" through thenexpression !event
    if(!event->isAutoRepeat())
        {
            if(event->key() == Qt::Key_Down)
                D = 1;
            if(event->key() == Qt::Key_Up)
                U = 1;
            if(event->key() == Qt::Key_Left)
                L = 1;
            if(event->key() == Qt::Key_Right)
                R = 1;
        }

        if(event->key()==Qt::Key_Space)
        {
            float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
            int boostX, boostY;
            boostX = pos().x() + 50 * qCos(rotat);
            boostY = pos().y() + 50 * qSin(rotat);
            setPos(boostX,boostY);
        }
    }

    //as the keys are released the isAutoRepeat returns false and the values are set to "0"
    void car::keyReleaseEvent(QKeyEvent *event)
    {
        if (!event->isAutoRepeat())
        {
            if(event->key() == Qt::Key_Up)
                U = 0;
            if(event->key() == Qt::Key_Down)
                D = 0;
            if(event->key() == Qt::Key_Left   )
                L = 0;
            if(event->key() == Qt::Key_Right)
                R = 0;
        }
    }

    void car::render()
    {

        leftTime->timer(); //In jeder 40 ms wird die Funktion timer() aus timer Klasse aufgerufen
        roundsCompleted();
        leftTime->getlefttime();

       stopmusic();
       qDebug()<<stopmusic();

        //checking whether 3 of the lives are gone or the time is up...
        if(this->health->getHealth() <= 0 || leftTime->getlefttime()==0.04)


        {
        //if yes, game is over
            gameOver *gameOverScene=new gameOver();
            gameOverScene->exec();
            disconnect(plotTimer, SIGNAL(timeout()),this, SLOT(render()));



        }

        if(U==1)
        {
           float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;

            if(crashed(this->decorArray) == true)//man vergleicht die gegenwaertige Position vom Auto mit dem Objektposition
            {
                //update lives
                health->decreaseHealth();
                //set car position 49,324
                 setPos(49,324);//nach Anfangspunk zurückkehren falls crashed
            }


             if(insideMap() == false)//es wurde getestet, ob das Auto auf dem Gamewindow ist,
             {
               health->decreaseHealth();
               setPos(49,324);

             }

            if(insideRoad(this->roadArray) == true)//wurde getestet, ob das Auto auf der Rennstrecke ist.
            {
                 int newX, newY;
                 newX = pos().x() + 12 * qCos(rotat);
                 newY = pos().y() + 12 * qSin(rotat);

                 setPos(newX,newY);
                 this->current_x = newX;
                 this->current_y = newY;
                 //qDebug()<<current_x<<current_y;


            }
            else
            {
                     int newX, newY;
                     newX = pos().x() + 5 * qCos(rotat);//sonst das Auto faehrt langsamer.
                     newY = pos().y() + 5 * qSin(rotat);//sonst das Auto faehrt langsamer.

                     setPos(newX,newY);
                     this->current_x = newX;
                     this->current_y = newY;

                     //qDebug()<<current_x<<current_y;
            }

       }

       if(D==1)
       {

               float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
               {
                   if(crashed(this->decorArray) == true)
                   {
                       //update health and set car pos 49,324
                       health->decreaseHealth();
                       setPos(49,324);
                   }

                   if(insideMap() == false)
                   {
                        health->decreaseHealth();
                        setPos(49,324);
                   }

                   if(insideRoad(this->roadArray) == true)
                   {
                    int newX, newY;
                    newX = pos().x() - 10 * qCos(rotat);
                    newY = pos().y() - 10 * qSin(rotat);

                    setPos(newX,newY);
                    this->current_x = newX;
                    this->current_y = newY;

                   }
                   else
                   {
                       int newX, newY;
                       newX = pos().x() - 5 * qCos(rotat);
                       newY = pos().y() - 5 * qSin(rotat);

                       setPos(newX,newY);
                       this->current_x = newX;
                       this->current_y = newY;


                   }

                }
          }
        if(R==1)
        {
            //if right arrow key is clicked, increasing the integer value of right clicks
            this->r=r+5;

                //setting the angle of the car by calculating the angle through rightclicks amount - leftclicks amount
                  setRotation(this->r-this->l);


        }
        if(L==1)
        {
            //if left arrow key is clicked, increasing the integer value of left clicks
            this->l=l+5;

                //setting the angle of the car by calculating the angle through  rightclicks amount - leftclicks amount
                setRotation(this->r-this->l);


        }

    }

//es wurde getestet, ob das Auto auf der Rennstrecke ist.
bool car:: insideRoad(road roadArray[]){
        int x = this->current_x;
        int y = this->current_y;
        for (int i = 0 ; i < 10; i++){
            int x1 = roadArray[i].baslangic_x;
            int y1 = roadArray[i].baslangic_y;
            int x2 = roadArray[i].son_x;
            int y2 = roadArray[i].son_y;
            if( x > x1 && x < x2 && y < y1 && y > y2 )
            return true;
        }
        return false;
}
//man vergleicht die gegenwaertige Position vom Auto mit dem Objektposition für Kollision
bool car:: crashed(int decorArray[]){
    int x = this->current_x;
    int y = this->current_y;
    for(int i= 0 ; i< 30;){
       if(x > decorArray[i]-30 && y < decorArray[i+1]+30
               &&x < decorArray[i]+30 &&y > decorArray[i+1]-30)
       {
           return true;
           health->decreaseHealth();
       }
        i = i +2;
    }
    return false;
}


bool car:: insideMap()
{
    int x = this->current_x;
    int y = this->current_y;

    if(x < -10 || x > 800 || y < -30 || y > 600)
        return false;
    else
        return true;
}

bool car::stopmusic()
{
    if (health->getHealth() <= 0 || leftTime->getlefttime()==0.04)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int car::startPointPassed()
{
    //if start point passed...
    if (pos().x()>= -10 && pos().x()<110 && pos().y()>=304 &&pos().y()<344)
    {
        //increase startpoint passed integer value if it hasnt been increased already (for that round)
        if(!sppassed)
        {                
            startPoint++;
            sppassed = true;
        }

    }
    else
    {       
        sppassed = false;
    }

    if(crashed(this->decorArray)==true ||insideMap() == false)
    {
        //if a collision has happened, or the car has gone outside the map..
        //..decrease the start point value, which we already have increased for that passing..
        //so that, that round doesnt count
        startPoint-=1;
    }
    //to prevent going forward and backwards at the beginning check if the difference..
    //..between starpoint 1 and 2 is greater than 1
       if(startPoint-checkPoint1>=2 )
       {
           do
           {
               startPoint-=1;
           }
           while(startPoint-checkPoint1>=2);
       }

    //update start point
    return startPoint;  

}

int car::checkPoint_1_Passed()
{
    //if check point 1 passed...
        if ( current_x>80&&current_x<120 &&current_y>-24 &&current_y<105)
        {
            //..if the integer value for checkpoint 1 has not been updated for that passing..
            if(!ch1passed)
            {
                //...increase checkpoint1 passed integer value..
                checkPoint1++;
                //..do this to know if we have already updated the value for that passing
                ch1passed = true;
            }

         }
    else
    {
        ch1passed = false;
    }
    //if a collision has happened, or the car has gone outside the map..
    //..decrease the check point 1 passed integer value, which we already have increased for that passing..
    //so that, that round doesnt count
            if(crashed(this->decorArray)==true||insideMap() == false )
            {

                if(checkPoint1>=startPoint)
                {
                checkPoint1-=1;
                }
            }
    return checkPoint1;
    qDebug()<<"cp1: "<<checkPoint1;
}

int car::checkPoint_2_Passed()
{
     //if check point 2 passed...
    if ( current_x>=498 && current_x<538 &&current_y>332 && current_y<650) //TODO x de ekle
    {
        if(!ch2passed)
        {
            //...increase checkpoint 2 passed integer value
            checkPoint2++;
           // if it hasnt increased the value for that passing
            ch2passed = true;
        }
    }
    else
    {
        ch2passed = false;
    }


        if(crashed(this->decorArray)==true||insideMap() == false)
        {
            //if a collision has happened, or the car has gone outside the map..
            //..check if we have already increased the checkpoint 2 passed value for that round..
            //..if yes decrease the value, if not dont..
            //..(for example if we have only passsed the 1. checkpoint before the collision happened)
            if(checkPoint2>=checkPoint1 &&checkPoint2==startPoint)
            {
            checkPoint2-=1;
            }
        }

    //return checkpoint 2 passed integer value
    return checkPoint2;

}

void car::roundsCompleted()
{
    checkPoint_1_Passed();
    checkPoint_2_Passed();
    startPointPassed();
  //if start point has been passed 4 times
  if(startPoint>=4)
  {
      //if check point 1 has been passed 3 times
      if (checkPoint1>=3)
      {
          //if check point 2 has been passed 3 times
          if(checkPoint2>=3)
          {
                  // 3 rounds has been completed-> show game won screen
                  gameWon=new GameWonDialog();
                  gameWon->exec();
                  disconnect(plotTimer, SIGNAL(timeout()),this, SLOT(render()));

          }
      }
  }

}
