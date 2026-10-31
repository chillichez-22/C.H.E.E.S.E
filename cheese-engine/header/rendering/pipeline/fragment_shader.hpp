#pragma once


#include "colour.hpp"
#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"
#include "vertex.hpp"
#include "primitives.hpp"

#include "ray.hpp"
#include "ray_3d_collisions.hpp"
#include "collision_result.hpp"

#include <SDL3/SDL.h>

#include <cstdint>
#include <stdfloat>



/**
 * @brief Draw a fragment from the rasteriser, into the screen.
 * 
 * @param fragPos UV percentages from the barycentric coords.
 * @param worldPrimitive 3D primitive tri in world space 
 * @param screenPrimitive 2D primitive tri in screen space
 * 
 * @returns `ColourI` Colour value ranging from 0->255.
 */
ColourI fs_drawFragmentBase(

    Vector2& fragUV, 
    Primitive< WorldVertex >& worldPrimitive, 
    Primitive< ScreenVertex >& screenPrimitive 
);


/**
 * @brief Calculates the screen coords using the `fragUV`.
 * 
 * @param fragPos UV percentages from the barycentric coords.
 * @param screenPrimitive 2D primitive tri in screen space
 * 
 * @returns `ColourI` Colour value ranging from 0->255.
 */
Vector2 fs_findScreenCoord(
    Vector2& fragUV, 
    Primitive< ScreenVertex >& screenPrimitive 
);