#ifndef DECOR_H
#define DECOR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


///
/// \brief The decor class creates the objects to add them on the map
///
class decor:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
       //int l=0,r=0;
     QPixmap pixmap;

public:
     ///
     /// \brief decor selects pixmaps according to pngnumber.
     /// \param parent is QGraphicsItem, from which QGraphicsPixmapItem is also derived.
     /// \param png_nmbr is the number of the chosen png to add the chosen png on a spesific position in the map
     /// and sets 0 as default
     ///
    decor(QGraphicsItem*parent =0,int png_nmbr=0);
    ///
    /// \brief drawOrmanKanunlariFero sets the pixmap according to png number.
    ///
    void drawOrmanKanunlariFero();

};

#endif // DECOR_H
