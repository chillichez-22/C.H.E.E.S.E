
#include <array>

#include "shapes/shapes_2d/tri_2d.hpp"
#include "maths/vector_2.hpp"



Tri2D::Tri2D(){};

Tri2D::Tri2D( 
    Vector2 pointOne, 
    Vector2 pointTwo, 
    Vector2 pointThree ){

   points[0] = pointOne;
   points[1] = pointTwo;
   points[2] = pointThree;
};
