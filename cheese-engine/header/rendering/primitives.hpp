#pragma once

#include "vector_3.hpp"
#include "vertex.hpp"

#include <array>

template< typename vertexType, uint8_t vertexCount>
struct primitive{

    std::array< vertexType&, vertexCount> vertices; /**< Vertexes making up the primitive */

};


