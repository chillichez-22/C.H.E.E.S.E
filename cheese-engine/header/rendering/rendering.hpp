#pragma once


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
#include "primitives.hpp"

// Graphics pipeline
#include "input_assembler.hpp"
#include "vertex_shader.hpp" 
#include "primitive_assembler.hpp"
#include "rasteriser.hpp"
#include "fragment_shader.hpp"

//....


/**
 * @brief Global settings for the renderer.
 * 
 *
 */

struct RenderSettings
{
    //const uint8_t topologySize = topologyVertexSize; /**< Vertex count of the primitives, how many vertexes to make one primitive */
};




/**
 * @brief Renders an `entity` to the screen, and starts the cpu rendering pipeline for this object.
 *
 * Starts the render pipeline for this object.
 * 
 * @details Pipeline:
 * 
 *      1. VertexShader - calculateWorldVertex
 *      2. VertexShader - calculateScreenVertex
 * 
 * @tparam topologyVertexSize Number of vertexes that make up a primitive ( E.G 3 or 4 )
 * 
 * @param entity Object to render.
 * 
 * @param objectMatrix Object matrix for world position transform ( using the entity's `Transform3D` ), to apply to each vertex
 * @param viewMatrix View matrix for the camera transform, to apply to each vertex
 * @param projectionMatrix Projection matrix for the screen transform, to apply to each vertex`
 * 
 * @param indexBuffer Buffer holding all indexes
 * @param vertexBuffer Buffer holding all vertexes
 * 
 * 
 */
void renderEntity(

    const Entity& entity,

    Matrix4x4< float >& viewMatrix,
    Matrix4x4< float >& projectionMatrix,

    const Buffer< uint32_t >& indexBuffer,
    const Buffer< ObjectVertex >& vertexBuffer,

    SDL_Renderer* renderer,
    const RenderSettings& settings
){

    //std::cout << "\n" << "Renderer Started...." << "\n";

    // Loads the model matrix data

    Matrix4x4<float> modelMatrix;


    /* TODO: Make this work 

    modelMatrix.scale( 
        entity.transform.scale[0],
        entity.transform.scale[1],
        entity.transform.scale[2]
    );

    modelMatrix.translate(
        entity.transform.position[0],
        entity.transform.position[1],
        entity.transform.position[2]
    );

    modelMatrix.rotateX( entity.transform.rotation[0] );
    modelMatrix.rotateY( entity.transform.rotation[1] );
    modelMatrix.rotateZ( entity.transform.rotation[2] );

    */


    /*
    We do a 2 loops here to:

    1. Simulate the sending of data from the GPU's Input Assembler, to the Vertex Shader's parallel cores.

    2. Simulate the primitive assembler combining said data from all of the Vertex Shader cores.

    3. Limit the amount of RAM ( memory ) needed, so we dont store the same calculated data. 
    ( E.G Full set of vertex and index buffers, full set of `worldVertex` data, full set of `screenVertex` data )

    */

    std::array< WorldVertex, 3 > worldVertexStream;     /**< Holds a primitive for the world vertexes */
    std::array< ScreenVertex, 3 > screenVertexStream;   /**< Holds a primitive for the screen vertexes */

    Primitive< WorldVertex > worldPrimitive;    /**< Primitive tri for the world */
    Primitive< ScreenVertex > screenPrimitive;  /**< Primitive tri for the screen */

    Buffer< Vector2 > fragmentStream; /**< Holds UV for the barycentric coords ( w is not stored as it can be found ) */
    ColourI fragColour;     /**< Colour of the fragment */
    Vector2 fragPos;        /**< 2D Position of the fragment in screen space */

    //std::cout << "Vertex Count: " << entity.vertexCount << "\n";
    
    // Splits the indexes into primitives, of size `settings.topologySize`
    for ( unsigned int i = 0; i <= ( entity.vertexCount / 3 ); i += 3 ){

        // std::cout << "I: " << i << "\n";

        // Loops over the vertexes in the primitives
        for ( unsigned int v = 0; v < 3; v++ ){

            //std::cout << "V: " << v << "\n";

            /* Vertex Shader */
            worldVertexStream[v] = vs_calculateWorldVertex( vertexBuffer[ indexBuffer[ ( i + v ) + entity.indexOffset ] + entity.vertexOffset ], modelMatrix, viewMatrix ); 
            screenVertexStream[v] = vs_calculateScreenVertex( worldVertexStream[v], projectionMatrix  ); 

            //std::cout << "World Vertex: " << v << " " << worldVertexStream[v] << "\n";
            //std::cout << "Screen Vertex: " << v << " " << screenVertexStream[v] << "\n";

            // Other shaders go here for now
        }

        /* Primitive Assembler */
        //std::cout << "\n" << "Primitive Assembler" << "\n";

        worldPrimitive = pa_formPrimitive< WorldVertex >( worldVertexStream );
        screenPrimitive = pa_formPrimitive< ScreenVertex >( screenVertexStream );

        //std::cout << "worldPrimitive: " << worldPrimitive << "\n";
        //std::cout << "screenPrimitive: " << screenPrimitive << "\n";


        /* Rasteriser */
        //std::cout << "\n" << "Rasteriser" << "\n";

        fragmentStream = ra_rasteriseTri( screenPrimitive );

        //std::cout << "Fragment stream size: " << fragmentStream.size() << "\n";

        /* Fragment Shader */
        //std::cout << "\n" << "Fragment Shader" << "\n";

        for ( unsigned int i = 0; i < fragmentStream.size(); i++ ){

            fragPos = fs_findScreenCoord( fragmentStream[i], screenPrimitive );
            
            fragColour = fs_drawFragmentBase( fragmentStream[i], worldPrimitive, screenPrimitive );
            

            SDL_SetRenderDrawColor( renderer, fragColour.r, fragColour.g, fragColour.b, fragColour.a );      
            SDL_RenderPoint( renderer, fragPos.x, fragPos.y );

        }

        fragmentStream.clear();
    };

    return;
};


