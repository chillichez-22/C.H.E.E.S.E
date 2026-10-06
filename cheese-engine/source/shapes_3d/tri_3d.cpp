#include "tri_3d.hpp"

// External
#include <array>

// Outside Scope
#include "vector_3.hpp"


Tri3D::Tri3D(){};

Tri3D::Tri3D( 
    Vector3 pointOne, 
    Vector3 pointTwo, 
    Vector3 pointThree ){

   points[0] = pointOne;
   points[1] = pointTwo;
   points[3] = pointThree;
};
