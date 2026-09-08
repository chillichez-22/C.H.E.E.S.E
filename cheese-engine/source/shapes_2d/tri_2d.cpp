#include "tri_2d.hpp"

// External
#include <array>

// Outside Scope
#include "vector_2.hpp"


Tri2D::Tri2D(){};

Tri2D::Tri2D( 
    Vector2 pointOne, 
    Vector2 pointTwo, 
    Vector2 pointThree ){

   points[0] = pointOne;
   points[1] = pointTwo;
   points[2] = pointThree;
};
