#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vertex.hpp"

#include "primitives.hpp"

/**
 * @brief Creates primitives using 3 or more vertexes.
 * 
 * @tparam vertexType Type of the vertex for the primitive.
 * @tparam primitiveCount Number of points to create the primitives.
 * 
 * @param vertexStream List of vertexes to create the primitive.
 * 
 * @returns `Primitive` - New primitive shape.
 */
template< typename vertexType, uint8_t primitiveCount  >
Primitive< vertexType, primitiveCount > pa_formPrimitive( std::vector< vertexType > vertexStream ){

    Primitive< vertexType, primitiveCount > primitive;

    for ( unsigned int i = 0; i < primitiveCount; i++ ){
        primitive.vertices[i] = vertexStream[i];
    };

    return primitive;
}; 