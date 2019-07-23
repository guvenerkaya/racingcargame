#include "car.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QtMath>

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
        roundsCompleted();
        if(this->health->getHealth() <= 0)
        {
            gameOver *gameOverScene=new gameOver();
            gameOverScene->exec();
            disconnect(plotTimer, SIGNAL(timeout()),this, SLOT(render()));
        }

        if(U==1)
        {
           float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;

            if(crashed(this->decorArray) == true)
            {
                //update lives
                health->decreaseHealth();

                //set car position 49,324
                 setPos(49,324);
            }


             if(insideMap() == false)
             {
               setPos(49,324);
             }

            if(insideRoad(this->roadArray) == true)
            {
                 int newX, newY;
                 newX = pos().x() + 10 * qCos(rotat);
                 newY = pos().y() + 10 * qSin(rotat);

                 setPos(newX,newY);
                 this->current_x = newX;
                 this->current_y = newY;
                 //qDebug()<<current_x<<current_y;


            }
            else
            {
                     int newX, newY;
                     newX = pos().x() + 5 * qCos(rotat);
                     newY = pos().y() + 5 * qSin(rotat);

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

                        setPos(49,324);

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
            this->r=r+5;
            {
                  setRotation(this->r-this->l);
            }

        }
        if(L==1)
        {
            this->l=l+5;

                if(pos().x()>0)
                {
                setRotation(this->r-this->l);
                }

        }

    }

bool car:: insideRoad(road roadArray[15]){
        int x = this->current_x;
        int y = this->current_y;
        for (int i = 0 ; i < 15; i++){
            int x1 = roadArray[i].baslangic_x;
            int y1 = roadArray[i].baslangic_y;
            int x2 = roadArray[i].son_x;
            int y2 = roadArray[i].son_y;
            if( x > x1 && x < x2 && y < y1 && y > y2 )
            return true;
        }
        return false;
}

bool car:: crashed(int decorArray[]){
    int x = this->current_x;
    int y = this->current_y;
    for(int i= 0 ; i< 30;){
       if(x > decorArray[i]-25 && y < decorArray[i+1]+25
               &&x < decorArray[i]+25 &&y > decorArray[i+1]-25)
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

    if(x < -10 || x > 800 || y < -10 || y > 600)
        return false;
    else
        return true;
}

int car::startPointPassed()
{
    //if start point passed...
    if (pos().x()>= -10 && pos().x()<110 && pos().y()>=304 &&pos().y()<344)
    {
        //increase startpoint passed integer value
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

    if(crashed(this->decorArray)==true)
    {
        //if(startPoint>che)
        startPoint-=1;
    }
     qDebug()<<"sp: "<<startPoint;

     //to prevent going forward and backward at the beginning check if the difference
     //between starpoint 1 and 2 is greater than 1
     if(startPoint-checkPoint1>=2 )
     {
         do
         {
             startPoint-=1;
         }
         while(startPoint-checkPoint1>=2);
     }
    return startPoint;
     //qDebug()<<"sp: "<<startPoint;
}

int car::checkPoint_1_Passed()
{
    //if check point 1 passed...
        if ( current_x>80&&current_x<120 &&current_y>-24 &&current_y<105)
        // if(pos().x()==80 && pos)
        {
            if(!ch1passed)
            {
                //...increase checkpoint1 passed integer value
               // lastCheckPoint = 1;
                checkPoint1++;
                ch1passed = true;
            }

         }
    else
    {
        ch1passed = false;
    }
    //return new checkpoint1 passed integer value
            if(crashed(this->decorArray)==true)
            {
                //if(checkPoint1==startPoint || checkPoint1>)
                if(checkPoint1>=startPoint)
                {
                //if()
                checkPoint1-=1;
                }
            }


             qDebug()<<"cp1: "<<checkPoint1;
    return checkPoint1;

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
           // lastCheckPoint = 2;
            ch2passed = true;
        }
    }
    else
    {
        ch2passed = false;
    }
    //return checkpoint 2 passed integer value

        if(crashed(this->decorArray)==true)
        {
            if(checkPoint2>=checkPoint1 &&checkPoint2==startPoint)
            {
            checkPoint2-=1;
            //checkPoint1-=1;
            }
        }
qDebug()<<"cp2: "<<checkPoint2;
    return checkPoint2;


}

void car::roundsCompleted()
{
//timeout olduysa if clause
    checkPoint_1_Passed();
    checkPoint_2_Passed();
    startPointPassed();
  //if start point has been passed 3 times
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
