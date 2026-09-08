#include "line_2d.hpp"

// Outside Scope
#include "vector_2.hpp"

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