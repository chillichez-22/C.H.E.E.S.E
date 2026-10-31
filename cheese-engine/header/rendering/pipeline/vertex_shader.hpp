#pragma once


#include "buffer.hpp"
#include "matrix.hpp"

#include "vertex.hpp"
#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

#include <cstdint>
#include <stdfloat>


/**
 * @brief 
 * Transforms a vertex from the `indexBuffer` and `vertexBuffer`, by the `modelMatrix` and `viewMatrix`.
 * 
 * @details 
 * Transforms each of the vertices starting from `indexOffset` and ending at ( `indexOffset` + `vertexCount` ) in the `indexBuffer`, 
 * applying the `vertexOffset` to get the vertices from the `vertexBuffer`, and multiplying each one by the `modelMatrix` and `viewMatrix`.
 *
 * @param triCentre Centre of this tri to rotate and scale the vertex around.
 * 
 * @param vertex World vertex to transform into 2D coords.
 *
 * @param modelMatrix Object matrix for world position transform ( using the entity's `Transform3D` ), to apply to each vertex
 * @param viewMatrix View matrix for the camera transform, to apply to each vertex
 *
 * @returns `WorldVertex` Transformed vertex using the `modelMatrix` and `viewMatrix`
 */
WorldVertex vs_calculateWorldVertex( 

    const ObjectVertex& vertex, 
    Matrix4x4< float >& modelMatrix, 
    Matrix4x4< float >& viewMatrix
);


/**
 * @brief Transforms the `WorldVertex` into a `ScreenVertex` using the `projectionMatrix`
 * 
 * 
 * @param vertex World vertex to transform into 2D coords.
 * @param projectionMatrix Projection matrix for the screen transform, to apply to the `worldVertex`
 * 
 * @returns `ScreenVertex` Transformed 2d screen vertex using the `projectionMatrix`
 */
ScreenVertex vs_calculateScreenVertex( 

    const WorldVertex& vertex, 
    Matrix4x4< float >& projectionMatrix

);