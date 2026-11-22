
#include "maths/vector_2.hpp"
#include "shapes/shapes_2d/rect_2d.hpp"



Rect2D::Rect2D(){};

Rect2D::Rect2D( 
    Vector2 rectCentre, 
    Vector2 rectSize ){

    centre = rectCentre;
    size = rectSize;
};