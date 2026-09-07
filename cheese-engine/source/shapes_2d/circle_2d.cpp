#include "circle_2d.hpp"

// Outside Scope
#include "vector_2.hpp"


Circle2D::Circle2D(){};

Circle2D::Circle2D(
    Vector2 circleCentre,
    float circleRadius ){

    centre = circleCentre;
    radius = circleRadius;
};
