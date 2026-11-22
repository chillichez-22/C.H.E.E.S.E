#pragma once

#include <array>

#include "maths/vector_3.hpp"
#include "rendering/vertex.hpp"



template< typename vertexType >
struct Primitive{

    std::array< vertexType, 3 > vertices; /**< Vertexes making up the primitive */

    /**
     * @brief Allows the use of `<iostream>` to print this object.
     * 
     * Shows only the pos.
     * 
     * @param os Output stream object.
     * @param obj Object to output into stream.
     * 
     * @returns `ostream` Output stream object. 
     */
    friend std::ostream& operator<<( std::ostream& os, const Primitive< vertexType > obj ){

        os << (obj.vertices[0]);
        os << (obj.vertices[1]);
        os << (obj.vertices[2]);
        
        return os;
    }
};


