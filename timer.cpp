#include "timer.h"
#include <QFont>
#include <QDebug>

Timer::Timer(QGraphicsItem * parent): QGraphicsTextItem(parent)

{
setPlainText(QString("Timer: ") + QString::number(leftTime));
setDefaultTextColor(Qt::yellow);
setFont(QFont("times",25));
}

double Timer::getlefttime()
{
    //return the remaining time to finish
    return leftTime;
    qDebug()<<leftTime;

}

void Timer::timer()
{
    leftTime=leftTime-0.04;
    //qDebug()<leftTime
    setPlainText(QString("Timer: ") + QString::number(leftTime));
    if (leftTime<=0.04)
    {
        leftTime=0.04;
        setPlainText(QString("Timer: ") + QString::number(0.00));
    }

}

/*void Timer::timer2()
{
    leftTime2=leftTime2-0.04;
    setPlainText(QString("Timer: ") + QString::number(leftTime2));
     if (leftTime2<=0.04)
     {
         leftTime2=0.04;
     }

}

void Timer::timer3()
{
    leftTime3=leftTime3-0.04;
    setPlainText(QString("Timer: ") + QString::number(leftTime3));
     if (leftTime3<=0.04)
     {
         leftTime3=0.04;
     }

}
*/
