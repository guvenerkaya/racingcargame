#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class car:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    int l=0,r=0;
    QPixmap pixmap;
    QTimer * plotTimer;
public:
    car(QGraphicsItem*parent =0);
    void drawFerrari();
    void drawMercedes();
    void drawRedbull();
    void keyPressEvent(QKeyEvent*event);
    void keyReleaseEvent(QKeyEvent*event);

private:
    int R,D,L,U;
public slots:
    void render();

};

#endif // CAR_H
