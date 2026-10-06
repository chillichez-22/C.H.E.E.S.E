#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"

#include "colour.hpp"

/**
 * @brief A 2D vertex holding the pos, uv co-ord, and colour for a 2D shape.
 * 
 * @details This does not hold a normal vector, as the shape can only face forwards pointing towards the camera.
 * 
 * @attention This is a `2D` vertex, it cannot be used for a 3D shape. For 3D shapes use `Vertex3D`
 */
struct Vertex2D{

    Vector2 pos;
    Vector2 uv;
    ColourI colour;
};

/**
 * @brief A Vertex holding position, normal, uv, and colour.
 */
struct Vertex3D{

    Vector3 pos;
    Vector3 normal;
    Vector2 uv;
    ColourI colour;
};