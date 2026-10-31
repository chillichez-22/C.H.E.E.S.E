#pragma once

#include "view_volume.hpp"
#include "matrix.hpp"


/**
 * @brief Calculates the projection matrix for an orthographic projection.
 * 
 * Coords are mapped to a unit cube of [-1, +1], so that: z = far maps to +1, and z = near maps to -1
 * 
 * @details Assigns matrix of:
 * 
 *              |                                            |
 *              | 2/(r-l),  0,        0,        -(r+l)/(r-l) |
 *              | 0,        2/(t-b),  0,        -(t+b)/(t-b) |
 *   P(ortho) = | 0,        0,        2/(f-n),  -(f+n)/(f-n) |
 *              | 0,        0,        0,        1            |
 *              |                                            |
 *
 * 
 * @param viewVol Camera's view volume
 * 
 * @returns `Matrix4x4<float>` Projection matrix for an orthographic projection.
 */
Matrix4x4<float> calculateOrthoProjection(

    Frustum& viewVol

);


/**
 * @brief Calculates the projection matrix for an orthographic projection.
 * 
 * Coords are mapped to a unit cube of [-1, +1], so that: z = far maps to +1, and z = near maps to -1
 * 
 * @details Assigns matrix of:
 *
 *             |                                          |
 *             | 2n/(r-l),  0,         -(r+l)/(r-l),  0   |
 *             | 0,         2n/(t-b),  -(t+b)/(t-b),  0   |
 *  P(pers) =  | 0,         0,         1,             -2n |
 *             | 0,         0,         1,             0   |
 *             |                                          |
 *   
 *
 * @param viewVol Camera's view frustum
 * 
 * @returns `Matrix4x4<float>` Projection matrix for an orthographic projection.
 */
Matrix4x4<float> calculatePerspectiveProjection(

    Frustum& viewVol

);