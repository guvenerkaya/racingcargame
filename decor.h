#ifndef DECOR_H
#define DECOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>



class decor:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
       //int l=0,r=0;
     QPixmap pixmap;

public:
    decor(QGraphicsItem*parent =0,int png_nmbr=0);
    void drawOrmanKanunlariFero();

};

#endif // DECOR_H
