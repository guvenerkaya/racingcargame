#include "health.h"
#include <QFont>
#include <QDebug>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize health=3 at the beginning of the game
    health = 3;

   // updateHealth();

    //write "Lives:" current health ,on the screen
    setPlainText(QString("Lives: ") + QString::number(health));

    qDebug()<<"olmasi gereken"<<this->health;

    //set text color to red
    setDefaultTextColor(Qt::red);

    //set textfont to times new roman and the size 25
    setFont(QFont("times",25));
}
void Health::decreaseHealth()
{
    //whenever this function is called(its called in car.cpp when a collision is detected) decrease lives
    health--;
    qDebug()<<"Health"<<health;

    //update the label on the screen
    setPlainText(QString("Lives: ") + QString::number(this->health));
}
int Health::getHealth()
{
    //return current health

    return  health;
    qDebug()<<"lives= " <<this->health;
}
/*
void Health::updateHealth()
{

setPlainText(QString("Lives: ") + QString::number(this->health)); //lives:..
qDebug()<<"olmasi gereken"<<this->health;
setDefaultTextColor(Qt::red);
setFont(QFont("times",25));
}
*/
