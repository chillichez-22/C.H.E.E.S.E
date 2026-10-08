#include "tri_3d.hpp"


Tri3D::Tri3D(){};

Tri3D::Tri3D( 
    Vector3& vectorOne, 
    Vector3& vectorTwo, 
    Vector3& vectorThree ){

   points[0] = vectorOne;
   points[1] = vectorTwo;
   points[3] = vectorThree;
};
