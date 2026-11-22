

#include "maths/vector_2.hpp"
#include "shapes/shapes_2d/circle_2d.hpp"


Circle2D::Circle2D(){};

Circle2D::Circle2D(
    Vector2 circleCentre,
    float circleRadius ){

    centre = circleCentre;
    radius = circleRadius;
};
