
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
#include <cstdint>
#include <stdfloat>

/*
std::vector< std::vector<ObjectVertex> > ia_assemblePrimitives(

    std::vector< std::vector< ObjectVertex > >& primitiveStream,

    const int32_t vertexCount,
    const uint32_t& indexOffset,
    const uint32_t& vertexOffset,

    const uint8_t primitiveSize,

    const Buffer< uint32_t >& indexBuffer,
    const Buffer< ObjectVertex >& vertexBuffer
){

    for( uint32_t i = 0; i < vertexCount; i++ ){
    
        primitiveStream[ i / primitiveSize ][ i % primitiveSize ] = vertexBuffer[ i + indexOffset + vertexOffset ];
    
    };

    return primitiveStream;
    
}
*/