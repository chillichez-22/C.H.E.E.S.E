#pragma once

#include "vector_3.hpp"
#include "vertex.hpp"

#include <array>

template< typename vertexType >
struct Primitive{

    std::array< vertexType, 3 > vertices; /**< Vertexes making up the primitive */

};


