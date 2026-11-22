#pragma once

#include "maths/vector_2.hpp"
#include "maths/vector_3.hpp"

#include "rendering/vertex.hpp"
#include "rendering/primitives.hpp"


/**
 * @brief Creates primitives using 3 or more vertexes.
 * 
 * @param vertexStream List of vertexes to create the primitive.
 * 
 * @returns `Primitive` - New primitive shape.
 */
template< typename vertexType >
Primitive< vertexType > pa_formPrimitive( std::array< vertexType, 3 > vertexStream ){

    Primitive< vertexType > primitive;

    primitive.vertices = vertexStream;

    return primitive;
}; 