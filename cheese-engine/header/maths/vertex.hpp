#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"

#include "colour.hpp"

#include <vector>

/**
 * @brief A 2D vertex holding the pos, uv co-ord, and colour for a 2D shape.
 * 
 * @details This does not hold a normal vector, as the shape can only face forwards pointing towards the camera.
 * 
 * @attention This is a `2D` vertex, it cannot be used for a 3D shape. For 3D shapes use `Vertex3D`
 */
struct Vertex2D{

    Vector2 pos;
    Vector2 uv;
    ColourI colour;

    /**
     * @brief Default Constructor 
     */
    Vertex2D();

    /**
     * @brief Constructor for a 2D vertex.
     * 
     * @attention This is a `2D` vertex, it cannot be used for a 3D shape. For 3D shapes use `Vertex3D`
     * 
     * @param posCoord 2D Position co-ordinate of the vertex.
     * @param uvCoord UV co-ordinate for a texture.
     * @param colourValue Colour value for this vertex. ( This is used to lerp between each of a shape's corner, to produce its albedo value )
     * 
     * @returns `Vertex2D` Vertex with a position, normal, uv, and colour value.
     */
    Vertex2D( 
        Vector2 posCoord,  
        Vector2 uvCoord, 
        ColourI colourValue 
    );
};

/**
 * @brief A Vertex holding position, normal, uv, and colour.
 */
struct Vertex3D{

    Vector3 pos;
    Vector3 normal;
    Vector2 uv;
    ColourI colour;

    /**
     * @brief Default Constructor 
     */
    Vertex3D();

    /**
     * @brief Constructor for a 3D vertex.
     * 
     * @param posCoord 3D Position co-ordinate of the vertex.
     * @param normalVec Normal of the vertex.
     * @param uvCoord UV co-ordinate for a texture.
     * @param colourValue Colour value for this vertex. ( This is used to lerp between each of a shape's corner, to produce its albedo value )
     * 
     * @returns `Vertex3D` Vertex with a position, normal, uv, and colour value.
     */
    Vertex3D( 
        Vector3 posCoord, 
        Vector3 normalVec, 
        Vector2 uvCoord, 
        ColourI colourValue 
    );
};

struct vertexBuffer2D{


    std::vector< Vertex2D > buffer; /**<Buffer of vertexes */

    /**
     * @brief Creates an empty vertexBuffer2D
     * 
     * @returns `vertexBuffer2D` New empty vertex buffer.
     */
    vertexBuffer2D(){};

    /**
     * @brief Create a new vertexBuffer2D.
     * 
     * @param buffer List of `vertex2D` to initialise the buffer with.
     * 
     * @returns `vertexBuffer2D` New vertex buffer filled with the `buffer`. 
     */
    vertexBuffer2D( std::vector< Vertex2D > vertexBuffer ): buffer( vertexBuffer ){};;

    /**
     * @brief Returns the number of items in the buffer.
     * 
     * @returns `int` Number of items in the buffer.
     */
    int count();
};

struct vertexBuffer3D{


    std::vector< Vertex3D > buffer; /**<Buffer of vertexes */

    /**
     * @brief Creates an empty vertexBuffer3D
     * 
     * @returns `vertexBuffer3D` New empty vertex buffer.
     */
    vertexBuffer3D(){};

    /**
     * @brief Create a new vertexBuffer3D.
     * 
     * @param buffer List of `vertex3D` to initialise the buffer with.
     * 
     * @returns `vertexBuffer3D` New vertex buffer filled with the `buffer`. 
     */
    vertexBuffer3D( std::vector< Vertex3D > vertexBuffer ): buffer( vertexBuffer ){};

    /**
     * @brief Returns the number of items in the buffer.
     * 
     * @returns `int` Number of items in the buffer.
     */
    int count();
};