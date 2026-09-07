#pragma once

// Outside Scope
#include "vector_2.hpp"

// Own Scope
#include "shape_2d.hpp"

/**
 * @brief
 */
struct Line2D : public Shape2D{

public:
    
    Vector2 startPoint;
    Vector2 endPoint;

public:

    Line2D( Vector2 start, Vector2 end );
    ~Line2D() = default;

    
    /**
     * @brief Moves the `centre` of the `Line2D` by the integers `x` and `y`.
     * 
     * @param x Integer for the x translation.
     * @param y Integer for the y translation.
     * 
     * @attention This takes in Integers. Use `move( float, float )` for float translations.
     */
    void move( int x, int y ); 

    /**
     * @brief Moves the `centre` of the `Line2D` by the floats `x` and `y`.
     * 
     * @attention This takes in Integers. Use `move( int, int )` for integer translations.
     * 
     * @param x Float for the x translation.
     * @param y Float for the y translation.
     */
    void move( float x, float y ); 

    
    /**
     * @brief Rotates the line's points by the integer `angle`, in radians, about the `origin`.
     * 
     * @attention This uses RADIANS for the rotation angle. Therefore `angle` should be between `+0`->`+2`.
     * 
     * @param angle Integer angle, in radians, to rotate the line.
     * @param origin Vector2 for the point to rotate the line about.
     */
    void rotate( int angle, Vector2 origin );

    /**
     * @brief Rotates the line's points by the float `angle`, in radians, about the `origin`.
     * 
     * @attention This uses RADIANS for the rotation angle.
     * 
     * @param angle Float angle, in radians, to rotate the line.
     * @param origin Vector2 for the point to rotate the line about.
     */
    void rotate( float angle, Vector2 origin );


    /**
     * @brief Calculates the vector that the `Line2D` takes from the `startPoint` to the `endPoint`
     * 
     * @returns `Vector2` Vector for the line.
     */
    Vector2 lineVector();


};