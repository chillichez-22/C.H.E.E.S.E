#pragma once

// Own Shape
#include "ray.hpp"

// Maths Objects
#include "vertex.hpp"
#include "vector_3.hpp"

// Other Shapes
#include "tri_3d.hpp"

/**
 * @brief 
 * Calculates a collision for a `ray` and `tri`.
 *  
 * If successful, stuffs the `uv` of the `RayHit3D` with the barycentric u and v values. 
 * ( w can be found using the equation: w = 1 - u - v ).
 * 
 * @param ray Ray to test with.
 * @param tri Tri to test for an intersection with the `ray`.
 * 
 * @returns `RayHit3D` New RayHit3D
 */
RayHit3D collisionRay3DTri3D( Ray3D ray, Tri3D tri );