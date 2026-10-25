#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"

#include "tri_2d.hpp"
#include "tri_3d.hpp"



/**
 * @brief Calculates the u,v,w coords for the 2D `tri`, using the 2D `point`.
 * 
 * @param point 2D Point that is inside the `tri`.
 * @param tri 2D Triangle calculate the `uvw` coords.
 * 
 * @returns `Vector3` U, V, W percentages of `point` inside of `tri`.
 */
Vector3 calculateBarycentricCoords( Vector2 point, Tri2D tri );


/**
 * @brief Calculates the u,v,w coords for the 3D `tri`, using the 3D `point`.
 * 
 * @param point 3D Point that is inside the `tri`.
 * @param tri 3D Triangle calculate the `uvw` coords.
 * 
 * @returns `Vector3` U, V, W percentages of `point` inside of `tri`.
 */
Vector3 calculateBarycentricCoords( Vector3 point, Tri3D tri );

