#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"

#include "tri_3d.hpp"

/**
 * @brief Calculates the `uvw` coords for the `tri`, from the `point`
 * 
 * @param point Point that is inside the `tri`.
 * @param tri Triangle calculate the `uvw` coords.
 * 
 * @returns
 */
Vector3 calculateBarycentricCoords( Vector3 point, Tri3D tri );