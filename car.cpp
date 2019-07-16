#include "car.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QtMath>
#include "mainwindow.h"

car::car(QGraphicsItem * parent,road roadArray[], int decorArray[]): QGraphicsPixmapItem(parent)
{
    for (int x =0 ; x < 10; x++)
    this->roadArray[x] = roadArray[x];
        for (int y =0 ; y < 30; y++)
        this->decorArray[y] = decorArray[y];
    plotTimer = new QTimer(this);
    connect(plotTimer, SIGNAL(timeout()),this, SLOT(render()));
    plotTimer->start(40);
    lives=new Health();

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
      /* if(event->key()==Qt::Key_Left)
       {
           this->l=l++;
           if(pos().x()>0)
           //qDebug()<<"linkearrow";
             // setPos(x()-10,y());
        //setTransformOriginPoint();
               setRotation(this->r-this->l);
       }

        if(event->key()==Qt::Key_Right)
        {
            this->r++;

            if(pos().x()+135<800) //TODO arabanin boyutunu editle
              //  setPos(x()+10,y());
            {
                  setRotation(this->r-this->l);
            }


        }

        if (event->key()==Qt::Key_Up)
        {
           float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
            if(pos().y()-230<800)
            {
                int newX, newY;
                newX = pos().x() + 10 * qCos(rotat);
                newY = pos().y() + 10 * qSin(rotat);
                //setRotation(this->r-this->l);
                //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                setPos(newX,newY);
            }
            //setPos(x(),y()-10);
        }

        if(event->key()==Qt::Key_Down)
        {
           float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
            if(pos().y()+230>0)
            {

                int newX, newY;
                newX = pos().x() - 10 * qCos(rotat);
                newY = pos().y() - 10 * qSin(rotat);

                //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                setPos(newX,newY);
            }
                //setPos(x(),y()+10);
        }*/
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


        if(U==1)
        {
           float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
             //if(pos().y()-230<800)
             //{
                //QString kaza = "canin b'tt'";
        if(crashed(this->decorArray) == true)
        {
            lives->decreaseLives();
            qDebug()<<lives->getHealth();
                    setPos(49,324);

                    //update lives

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
                 //setRotation(this->r-this->l);
                 //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                 setPos(newX,newY);
                 this->current_x = newX;
                 this->current_y = newY;

                 //qDebug()<<newX<<newY;
                // qDebug()<<insideRoad(this->roadArray);
                // qDebug()<<crashed(this->decorArray);

         }
         else
         {
                     int newX, newY;
                     newX = pos().x() + 5 * qCos(rotat);
                     newY = pos().y() + 5 * qSin(rotat);

                     //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                     setPos(newX,newY);
                     this->current_x = newX;
                     this->current_y = newY;

                    // qDebug()<<current_x<<current_y;
                    // qDebug()<<insideRoad(this->roadArray);
                    // qDebug()<<crashed(this->decorArray);
           }

       }
             //setPos(x(),y()-10);

        if(D==1){

               float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
               // if(pos().y()+230>0)
                {
                   if(crashed(this->decorArray) == true)

                      {
                       lives->decreaseLives();
                       setPos(49,324);
                      }

                    if(insideMap() == false)
                        setPos(49,324);
                   if(insideRoad(this->roadArray) == true){
                    int newX, newY;
                    newX = pos().x() - 10 * qCos(rotat);
                    newY = pos().y() - 10 * qSin(rotat);

                    //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                    setPos(newX,newY);
                    this->current_x = newX;
                    this->current_y = newY;

                   // qDebug()<<current_x<<current_y;
                   // qDebug()<<insideRoad(this->roadArray);
                   // qDebug()<<crashed(this->decorArray);

                   }
                   else{
                       int newX, newY;
                       newX = pos().x() - 5 * qCos(rotat);
                       newY = pos().y() - 5 * qSin(rotat);

                       //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                       setPos(newX,newY);
                       this->current_x = newX;
                       this->current_y = newY;
                      // qDebug()<<newX<<newY;
                      // qDebug()<<insideRoad(this->roadArray);
                      // qDebug()<<crashed(this->decorArray);

                   }

                }
          }
        if(R==1){
            this->r=r+5;

            //if(pos().x()+135<800) //TODO arabanin boyutunu editle
              //  setPos(x()+10,y());
            {
                  setRotation(this->r-this->l);
            }

        }
        if(L==1){
            this->l=l+5;
            if(pos().x()>0)
            {
            //qDebug()<<"linkearrow";
              // setPos(x()-10,y());
         //setTransformOriginPoint();
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
               &&x < decorArray[i]+25 &&y > decorArray[i+1]-25){
           return true;
        }
        i = i +2;
    }
    return false;
}

bool car:: insideMap(){
    int x = this->current_x;
    int y = this->current_y;

    if(x < -10 || x > 800 || y < -10 || y > 600)
        return false;
    else
        return true;
}



