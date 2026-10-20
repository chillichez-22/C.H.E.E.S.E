#include "loading.hpp"

template< typename entityType, uint32_t arraySize >
entityType* loadVertexData( 
    entityType* entityPtr, 
    std::array< ObjectVertex, arraySize > vertexList,
    buffer< ObjectVertex >* vertexBufferPtr, 
    buffer< uint32_t >* indexBufferPtr
    ){

        
    buffer< ObjectVertex > tempVertBuffer;
    buffer< uint32_t > tempIndexBuffer;


    // TODO: Have a cache to store last known vertices, then loop over this first to find a cache hit. 
    //       Then only if a cache hit is not found, we go back and check the main tempVertexBuffer for duplicates.
    //
    // buffer< ObjectVertex, 4 > vertexCache; /** < Stores the last 4 vertices, as they may have been reused */
    // buffer< uint32_t, 4 > indexCache; /** < Stores the last 4 indicies, as they may have been reused */



    // Adds the first index, so we dont need an if to check if the `tempVertBuffer` and `tempIndexBuffer` are empty or not. 

    ObjectVertex vertex = vertexList[0];
    int32_t index = 0;
    
    index = tempVertBuffer.push_back( vertex );
    tempIndexBuffer.push_back( index );

    // Loops over vertices, not including the first `0` since we did that above. 
    for ( uint32_t v = 1; v < vertexList.size(); v++ ){

        vertex = vertexList[v];

        index = checkIfVertexInList( tempVertBuffer, tempIndexBuffer, vertex );

        // Not in list, therefore `index` needs changing, and `tempVertBuffer` needs updating
        if ( index == -1 ){

            index = tempVertBuffer.push_back( vertex );
        }
        
        tempIndexBuffer.push_back( uint32_t( index ) );
    
    }

    (*entity).vertexCount = tempIndexBuffer.size();

    // Sets the offsets before adding the new items to the buffers 
    (*entity).vertexOffset = (*vertexBufferPtr).size();
    (*entity).indexOffset = (*indexBufferPtr).size();

    (*vertexBufferPtr).push_back( tempVertBuffer );
    (*indexBufferPtr).push_back( tempIndexBuffer );

    return entity;
}

