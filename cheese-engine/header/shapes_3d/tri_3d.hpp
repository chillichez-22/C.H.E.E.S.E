#pragma once

// External
#include <array>
#include <cstdint>

// Outside Scope
#include "vector_3.hpp"

// Own Scope
#include "shape_3d.hpp"

/**
 * @brief A 3D Tri structure.
 */
struct Tri3D : public Shape3D{

public:

    std::array< Vector3&, 3 > points;

public:

    Tri3D();
    
    Tri3D( 
        Vector3& vectorOne, 
        Vector3& vectorTwo, 
        Vector3& vectorThree 
    );

    ~Tri3D() = default;

    /**
     * @brief Moves the `centre` of the `Tri3D` by the integers `x` and `y`.
     * 
     * @param x Integer for the x translation.
     * @param y Integer for the y translation.
     * @param z Integer for the z translation.
     * 
     * @attention This takes in Integers. Use `move( float, float )` for float translations.
     */
    void move( int x, int y, float z ); 

    /**
     * @brief Moves the `centre` of the `Tri3D` by the floats `x` and `y`.
     * 
     * @attention This takes in Integers. Use `move( int, int )` for integer translations.
     * 
     * @param x Float for the x translation.
     * @param y Float for the y translation.
     * @param z Float for the z translation.
     */
    void move( float x, float y, float z ); 

};