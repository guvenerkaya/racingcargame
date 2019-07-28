#ifndef TIMER_H
#define TIMER_H
#include <QGraphicsTextItem>
//#include <QTimer>
///
/// \brief The Timer class makes the timer object for the game.
///
class Timer:public QGraphicsTextItem
{
    //QTimer * getlifeTimer;
public:
    ///
    /// \brief Timer constructs the text on the game scene Timer: and the timer given for maps.
    /// \param parent is QGraphicsItem inherited by QGraphicsTextItem.
    ///
    Timer(QGraphicsItem * parent=0);
    ///
    /// \brief getlefttime returns the leftTime.
    ///
    ///
    double getlefttime();
    ///
    /// \brief timer function is called in render function and plots a timer.
    ///
    void timer();
    ///
    /// \brief leftTime is the double value where we store the remaining time in the game.
    ///
    double leftTime;
private:
    //double leftTime = 40;
public slots:
//double getlefttime();



};

#endif // TIMER_H
