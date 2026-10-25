#pragma once

// External
#include <string>
#include <iostream>
#include <vector>
#include <cstddef>
#include <SDL3/SDL.h>

// Outside Scope
#include "math.hpp"

#include "buffer.hpp"

#include "vector_2.hpp"
#include "vector_3.hpp"
#include "colour.hpp"

#include "vertex.hpp"
#include "primitives.hpp"

#include "tri_2d.hpp"
#include "line_2d.hpp"


/**
 * @brief Rasterises a tri into fragments.
 * 
 * @param worldTri Tri primitive in world space coords ( 4D/3D )
 * @param screenTri Tri primitive in screen space coords ( 2D )
 * 
 * @return `vector< Vector2 >` List of UV lambdas, from the barycentric coords ( w not included ).
 */
Buffer< Vector2 > ra_rasteriseTri( 

    Primitive< ScreenVertex >& screenTri
);

/**
 * @brief Orders `zero`, `one` and `two` vertexes, to change the `orderedPoints`.
 * 
 * @param orderedPoints Array to assign and replace vertexes 
 * @param zero First vertex
 * @param one Second vertex
 * @param two Third vertex
 */
void ra_orderPointsTri(

    std::array< ScreenVertex, 3 >& orderedPoints,
    ScreenVertex& zero,
    ScreenVertex& one,
    ScreenVertex& two 
);

/**
 * @brief Splits the incoming primitive tri, into two: Upper, and Lower tris.
 * 
 * @param splitTris Array to assign tris to
 * @param top Top-most point of the incoming primitive tri
 * @param mid Middle point of the incoming primitive tri
 * @param low Lowest point of the incoming primitive tri
 */
void ra_splitTri( 

    std::array< Tri2D, 2 >& splitTris,
    Vector2& top,
    Vector2& mid,
    Vector2& low 
);


/**
 * @brief 
 * Scans a tri with a flat horizontal side, from top ( -y ) to bottom ( +y )
 * to returns all of it's fragments ( inside 2d positions ).
 * 
 * @details 
 * Calculates the slope/gradient of both vertical-ish sides of a split tri, 
 * knowing that the 0 index ( first point ) will always be the "top" point ( most -y ). And 2 index ( third point ) will always be the "low" point ( most +y ).
 * ( The "mid" point will be the same as the "low" point when bottom-flat. And the "mid" will be the same as the "top" point when top-flat )
 *
 * On top-flat tris: 
 * - Zero or One is the top point. 
 * - Two is the low point.
 *  
 *      1---------[0]^
 *       \       /
 *        \     /
 *         \   /
 *          \ /
 *          [2]v
 * 
 * On bottom-flat tris:
 * - Zero is the top point
 * - Two or One is the low point.
 * 
 *           [0]^
 *           / \
 *          /   \
 *         /     \
 *        /       \
 *       1--------[2]v
 * 
 * 
 * Uses Equation Of Line (EOL) to work out the C value ( from y=mx+c ) since we know the gradient: m, and y value 
 * Uses EOL again to work out the x value of the two vertical-ish sides, to later loop through as the `startX` and `endX`.
 * 
 * 
 * @param fragmentStream List of 2d positions ( fragments )
 * @param tri Tri to scan
 * 
 */
void ra_scanTri(
    Buffer< Vector2 >& fragmentStream,
    Tri2D& tri
);


