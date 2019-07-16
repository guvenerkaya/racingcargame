#include "health.h"
#include <QFont>
#include <QDebug>
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    this-> health = 3;
   // updateHealth();
    setPlainText(QString("Lives: ") + QString::number(this->health)); //lives:..
    qDebug()<<"olmasi gereken"<<this->health;
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",25));
}
void Health::decreaseLives()
{
    this->health--;
    //qDebug()<<lives;
   setPlainText(QString("Lives: ") + QString::number(this->health));
   //setPos(0,0);
   qDebug()<<"olmasi gereken"<<this->health;
    //updateHealth();
}
int Health::getHealth()
{
    return this->health;
    qDebug()<<"lives= " <<this->health;
}
/*bool Health::isHealthy()
{
    if(this->health>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Health::updateHealth()
{

setPlainText(QString("Lives: ") + QString::number(this->health)); //lives:..
qDebug()<<"olmasi gereken"<<this->health;
setDefaultTextColor(Qt::red);
setFont(QFont("times",25));
}
*/
