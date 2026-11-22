#pragma once

#include <cstdint>
#include <stdfloat>

#include "entity/entity.hpp"
#include "components/component.hpp"
#include "components/transform.hpp"

#include "iterables/buffer.hpp"

#include "maths/matrix.hpp"
#include "maths/vector_2.hpp"
#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"

#include "rendering/vertex.hpp"
#include "rendering/colour.hpp"



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