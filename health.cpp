#include "health.h"
#include <QFont>
#include <QDebug>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize health=3 at the beginning of the game
    health = 3;


    //write "Lives:" current health ,on the screen
    setPlainText(QString("Lives: ") + QString::number(health));

    //set text color to red
    setDefaultTextColor(Qt::red);

    //set textfont to times new roman and the size 25
    setFont(QFont("times",25));
}
void Health::decreaseHealth()
{
    //whenever this function is called(its called in car.cpp when a collision is detected) decrease lives
    health--;
    //update the label on the screen
    setPlainText(QString("Lives: ") + QString::number(this->health));
}
int Health::getHealth()
{
    //return current health
    return  health;

}

