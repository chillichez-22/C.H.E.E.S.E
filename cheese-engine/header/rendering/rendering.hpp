#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

#include "colour.hpp"

#include <vector>

/**
 * @brief A vertex holding a 3d position, uv, and colour.
 */
struct ObjectVertex{
    
    Vector3 pos;
    Vector2 uv;
    ColourI colour;
    
    /**
     * @brief Default Constructor 
     */
    ObjectVertex();
    
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
        Vector2 uvCoord, 
        ColourI colourValue 
    ): pos( posCoord ), uv( uvCoord ), colour( colourValue ){};
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
    WorldVertex();
    
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
    ScreenVertex();

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
};
