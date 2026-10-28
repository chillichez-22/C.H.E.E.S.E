#include "rect_2d.hpp"

// Outside Scope
#include "vector_2.hpp"


Rect2D::Rect2D(){};

Rect2D::Rect2D( 
    Vector2 rectCentre, 
    Vector2 rectSize ){

    centre = rectCentre;
    size = rectSize;
};