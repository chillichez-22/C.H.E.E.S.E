#include "rendering.hpp"

void renderEntity(

    const Entity& entity,

    const uint8_t topologyVertexSize,

    Matrix4x4< float >& viewMatrix,
    Matrix4x4< float >& projectionMatrix,

    const Buffer< uint32_t >& indexBuffer,
    const Buffer< ObjectVertex >& vertexBuffer
){


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

    std::vector< WorldVertex > worldVertexStream;
    std::vector< ScreenVertex > screenVertexStream;

    for ( unsigned int i = 0; i < topologyVertexSize; i ++){

        worldVertexStream.push_back( WorldVertex() );
        screenVertexStream.push_back( ScreenVertex() );

    }; 

    // Splits the indexes into primitives, of size `topologyVertexSize`
    for ( unsigned int i = 0; i < ( entity.vertexCount / topologyVertexSize ); i + topologyVertexSize ){

        // Loops over the vertexes in the primitives
        for ( unsigned int v = 0; v < topologyVertexSize; v++ ){

            worldVertexStream[v] = vs_calculateWorldVertex( vertexBuffer[ indexBuffer[ ( i + v ) + entity.indexOffset ] + entity.vertexOffset ], modelMatrix, viewMatrix ); 
            screenVertexStream[v] = vs_calculateScreenVertex( worldVertexStream[v], projectionMatrix  ); 

            // Other shaders go here for now
        }


    };


};
