#include "decor.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

decor::decor(QGraphicsItem * parent,int png_nmbr): QGraphicsPixmapItem(parent)
{
    if(png_nmbr==1){
    this->pixmap = QPixmap(":/map_images/tree.png");
    }
    if(png_nmbr==2){
    this->pixmap = QPixmap(":/map_images/Rock_01.png");
    }
    if(png_nmbr==3){
    this->pixmap = QPixmap(":/map_images/grandstandYARIM.png");
    }
    if(png_nmbr==4){
    this->pixmap = QPixmap(":/map_images/Water_Tile.png");
    }
    if(png_nmbr==5){
    this->pixmap = QPixmap(":/map_images/Pavilion_01.png");
    }
    if(png_nmbr==6){
    this->pixmap = QPixmap(":/map_images/Pavilion_02.png");
    }
    if(png_nmbr==7){
    this->pixmap = QPixmap(":/map_images/Soil_Tile.png");
    }
    if(png_nmbr==8){
    this->pixmap = QPixmap(":/map_images/grandstand.png");
    }
    if(png_nmbr==9){
    this->pixmap = QPixmap(":/map_images/Finish.png");
    }

    drawOrmanKanunlariFero();
}
void decor::drawOrmanKanunlariFero()

{
   setPixmap(this->pixmap);
}
