#include "car.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QtMath>
#include "mainwindow.h"
car::car(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    plotTimer = new QTimer(this);
    connect(plotTimer, SIGNAL(timeout()),this, SLOT(render()));
    plotTimer->start(20);

}


void car::keyPressEvent(QKeyEvent *event)
{
/*
   if(event->key()==Qt::Key_Left)
   {
       this->l++;
      // if(pos().x()>0)
       //if(pos().x()+135<956)

           this->setRotation(10*(this->r-this->l));

   }

    if(event->key()==Qt::Key_Right)
    {
        this->r++;

        //if(pos().x()+135<800) //TODO arabanin boyutunu editle

        {
              this->setRotation(10*(this->r-this->l));
        }


    }
    if (event->key()==Qt::Key_Up)
    {
       float rotat = (10*(this->r-this->l)) * 3.14 / 180 - 3.14/2.0;
        if(pos().y()-230<800)
        {
            int newX, newY;
            newX = pos().x() + 10 * qCos(rotat);
            newY = pos().y() + 10 * qSin(rotat);
            this->setPos(newX,newY);
            //qDebug()<<newX<<newY;
        }
    }

    if(event->key()==Qt::Key_Down)
    {
       float rotat = (10*(this->r-this->l)) * 3.14 / 180 - 3.14/2.0;
        if(pos().y()+230>0)
        {

            int newX, newY;
            newX = pos().x() - 10 * qCos(rotat);
            newY = pos().y() - 10 * qSin(rotat);
            this->setPos(newX,newY);
        }
            //setPos(x(),y()+10);
    }
    if(event->key()==Qt::Key_Space)
    {
        float rotat = (10*(this->r-this->l) )* 3.14 / 180 - 3.14/2.0;
        int boostX, boostY;
        boostX = pos().x() + 50 * qCos(rotat);
        boostY = pos().y() + 50 * qSin(rotat);
        this->setPos(boostX,boostY);
    }
    */
    //guven yeni
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
        if(U==1){
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
        if(D==1){


               float rotat = (this->r-this->l) * 3.14 / 180 - 3.14/2.0;
                if(pos().y()+230>0)
                {

                    int newX, newY;
                    newX = pos().x() - 10 * qCos(rotat);
                    newY = pos().y() - 10 * qSin(rotat);

                    //qDebug()<<rotat<<qSin(rotat)<<qCos(rotat)<<newX<<newY;
                    setPos(newX,newY);
                }
          }
        if(R==1){
            this->r++;

            if(pos().x()+135<800) //TODO arabanin boyutunu editle
              //  setPos(x()+10,y());
            {
                  setRotation(this->r-this->l);
            }

        }
        if(L==1){
            this->l++;
            if(pos().x()>0)
            {
            //qDebug()<<"linkearrow";
              // setPos(x()-10,y());
         //setTransformOriginPoint();
                setRotation(this->r-this->l);
            }


        }

}

