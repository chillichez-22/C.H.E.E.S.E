
#include "maths/vector_2.hpp"
#include "shapes/shapes_2d/line_2d.hpp"


Line2D::Line2D(){};

Line2D::Line2D(
    Vector2 start,
    Vector2 end ){

    startPoint = start;
    endPoint = end;
};


Vector2 Line2D::lineVector(){

    return endPoint - startPoint;
}