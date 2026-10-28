#include "quad_2d.hpp"

// External
#include <array>

// Outside Scope
#include "vector_2.hpp"


Quad2D::Quad2D(){};

Quad2D::Quad2D( 
    Vector2 pointOne,
    Vector2 pointTwo,
    Vector2 pointThree,
    Vector2 pointFour ){

    std::array< Vector2, 4 > points = { pointOne, pointTwo, pointThree, pointFour };
};
