#pragma once


// Entity & Components
#include "entity.hpp"
#include "component.hpp"
#include "transform.hpp"

// Maths
#include "buffer.hpp"
#include "matrix.hpp"

// Vertex & Vectors
#include "vertex.hpp"
#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"
#include "colour.hpp"

// Graphics pipeline
#include "input_assembler.hpp"
#include "vertex_shader.hpp" 

//....


/**
 * @brief Renders an `entity` to the screen, and starts the cpu rendering pipeline for this object.
 *
 * Starts the render pipeline for this object.
 * 
 * @details Pipeline:
 * 
 *      1. VertexShader - calculateWorldVertex
 *      2. VertexShader - calculateScreenVertex
 * 
 * @param entity Object to render.
 * 
 * @param objectMatrix Object matrix for world position transform ( using the entity's `Transform3D` ), to apply to each vertex
 * @param viewMatrix View matrix for the camera transform, to apply to each vertex
 * @param projectionMatrix Projection matrix for the screen transform, to apply to each vertex`
 * 
 * @param indexBuffer Buffer holding all indexes
 * @param vertexBuffer Buffer holding all vertexes
 * 
 * 
 */
void renderEntity(

    const Entity& entity,

    const uint8_t topologyVertexSize,

    Matrix4x4< float >& viewMatrix,
    Matrix4x4< float >& projectionMatrix,

    const Buffer< uint32_t >& indexBuffer,
    const Buffer< ObjectVertex >& vertexBuffer
);

