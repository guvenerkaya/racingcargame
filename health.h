#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health:public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void decreaseLives();
    int getHealth();
    int health;
    bool isHealthy();
    void updateHealth();
};

#endif // HEALTH_H
