 #ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
///
/// \brief The Health class is to set the Lives of the car and show them on the game scene dependent by the events of the car object.
///
class Health:public QGraphicsTextItem
{
public:
    ///
    /// \brief Health constructs the text on the game scene Lives:3
    /// \param parent is QGrahicsItem which is inherited by QGraphicsTextItem.
    ///
    Health(QGraphicsItem * parent=0);
    ///
    /// \brief decreaseHealth whenever this function is called(its called in car.cpp when a collision is detected); decrease lives.
    ///
    void decreaseHealth();
    ///
    /// \brief getHealth holds the current live value.
    /// \returns the live value.
    ///
    int getHealth();
private:
    int health;

};

#endif // HEALTH_H
