#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

#include "colour.hpp"

#include <iostream>
#include <vector>

/**
 * @brief A vertex holding a 3d position, uv, and colour.
 */
struct ObjectVertex{
    
    Vector3 pos;
    Vector3 normal;
    Vector2 uv;
    ColourI colour;

    
    /**
     * @brief Default Constructor 
     */
    ObjectVertex(){};
    
    /**
     * @brief Constructor for a world vertex.
     * 
     * @param posCoord 3D Position co-ordinate of the vertex.
     * @param uvCoord 2D co-ordinate for a texture uv.
     * @param colourValue Colour value for this vertex. ( This is used to lerp between each of a shape's corner, to produce its albedo value )
     * 
     * @returns `ObjectVertex` Vertex with a position, uv, and colour value.
     */
    ObjectVertex( 
        Vector3 posCoord,
        Vector3 normalVec,
        Vector2 uvCoord, 
        ColourI colourValue 
    ): pos( posCoord ), normal( normalVec ), uv( uvCoord ), colour( colourValue ){};


    // Iostream

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
    friend std::ostream& operator<<( std::ostream& os, const ObjectVertex obj ){

        os << (obj.pos);
        
        return os;
    }

    // Comparison Operator Overloading

    /**
     * @brief Returns the comparison of this + another `ObjectVertex`.
     * 
     * @param vertex Other vertex to compare.
     * 
     * @return `bool` - Comparison of the two vertexes.
     */
    bool operator==( ObjectVertex vertex );

    /**
     * @brief Returns the inverse comparison of this + another `ObjectVertex`.
     * 
     * @param vertex Other vertex to compare.
     * 
     * @return `bool` - Comparison of the two vertexes.
     */
    bool operator!=( ObjectVertex vertex );
    
};


/**
 * @brief A vertex holding a 4d position, 3d normal, uv, and colour.
 */
struct WorldVertex{
    
    Vector4 pos;
    Vector3 normal;
    Vector2 uv;
    ColourI colour;
    
    /**
     * @brief Default Constructor 
     */
    WorldVertex(){};
    
    /**
     * @brief Constructor for a world vertex.
     * 
     * @param posCoord 4D Position co-ordinate of the vertex.
     * @param normalVec Normal of the vertex.
     * @param uvCoord 2D co-ordinate for a texture uv.
     * @param colourValue Colour value for this vertex. ( This is used to lerp between each of a shape's corner, to produce its albedo value )
     * 
     * @returns `WorldVertex` Vertex with a position, normal, uv, and colour value.
     */
    WorldVertex( 
        Vector4 posCoord, 
        Vector3 normalVec, 
        Vector2 uvCoord, 
        ColourI colourValue 
    ): pos( posCoord ), normal( normalVec ), uv( uvCoord ), colour( colourValue ){};


    // Iostream

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
    friend std::ostream& operator<<( std::ostream& os, const WorldVertex obj ){

        os << (obj.pos);
        
        return os;
    }
};

/**
 * @brief A vertex holding the 2d pos and uv co-ord
 */
struct ScreenVertex{

    Vector2 pos;
    Vector2 uv;

    /**
     * @brief Default Constructor 
     */
    ScreenVertex(){};

    /**
     * @brief Constructor for a screen vertex.
     * 
     * @param posCoord 2D Position co-ordinate of the vertex.
     * @param uvCoord 2D co-ordinate for a texture uv.
     * 
     * @returns `ScreenVertex` Vertex with a position, normal, uv, and colour value.
     */
    ScreenVertex( 
        Vector2 posCoord,  
        Vector2 uvCoord
    ): pos( posCoord ), uv( uvCoord ){};


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
    friend std::ostream& operator<<( std::ostream& os, const ScreenVertex obj ){

        os << (obj.pos);
        
        return os;
    }
};
