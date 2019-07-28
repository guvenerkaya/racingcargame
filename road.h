#ifndef ROAD_H
#define ROAD_H

///
/// \brief The road class divides the road in rectangles.
///
class road
{
public:
    ///
    /// \brief road function creates the rectangles.
    /// \param baslangic_x bottom left x position of the rectangle.
    /// \param baslangic_y bottom left y position of the rectangle.
    /// \param son_x top right x position of the rectangle.
    /// \param son_y top right y position of the rectangle.
    ///
    road(int baslangic_x=0,
    int baslangic_y=0,
    int son_x=0,
    int son_y=0);

    int baslangic_x;
    int baslangic_y;
    int son_x;
    int son_y;
};

#endif // ROAD_H
