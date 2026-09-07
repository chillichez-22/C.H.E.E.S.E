#pragma once

// Outside Scope
#include "vector_2.hpp"

// Own Scope
#include "shape_2d.hpp"

/**
 * @brief A 2D circle structure. 
 */
struct Circle2D : public Shape2D{

public:

    Vector2 centre;
    float radius;

public:

    Circle2D( Vector2 centre, float radius );
    ~Circle2D() = default;


    /**
     * @brief Moves the `centre` of the `Circle2D` by the integers `x` and `y`.
     * 
     * @param x Integer for the x translation.
     * @param y Integer for the y translation.
     * 
     * @attention This takes in Integers. Use `move( float, float )` for float translations.
     */
    void move( int x, int y ); 

    /**
     * @brief Moves the `centre` of the `Circle2D` by the floats `x` and `y`.
     * 
     * @param x Float for the x translation.
     * @param y Float for the y translation.
     * 
     * @attention This takes in Integers. Use `move( int, int )` for integer translations.
     */
    void move( float x, float y ); 


};