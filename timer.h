#ifndef TIMER_H
#define TIMER_H
#include <QGraphicsTextItem>
//#include <QTimer>

class Timer:public QGraphicsTextItem
{
    //QTimer * getlifeTimer;
public:
    Timer(QGraphicsItem * parent=0);
    double getlefttime();
    void timer();
    double leftTime;
private:
    //double leftTime = 40;
public slots:
//double getlefttime();



};

#endif // TIMER_H
