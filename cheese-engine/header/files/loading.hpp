#pragma once

#include <cstdint>
#include <array>
#include <vector>
#include <string>

#include "buffer.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

#include "entity.hpp"

#include "vertex.hpp"



/**
 * @brief Loads in a new object into the object at the `entityPtr`.
 * 
 * @tparam entityType Type of entity to load the data from. 
 * 
 * @param entity Entity to load data into.
 * @param filepath String of the filepath to retrieve the data from.
 * @param vertexList List of vertices to add.
 * @param vertexBuffer Vertex Buffer. 
 * @param indexBuffer Index Buffer. 
 * 
 * @returns `entityType` - Entity of type `entityType` with data from loading. 
 */
template< typename entityType >
entityType& loadObject( 
    entityType& entity, 
    std::string& filepath, 
    Buffer< ObjectVertex >& vertexBuffer, 
    Buffer< uint32_t >& indexBuffer 
); 



/**
 * @brief 
 * Checks if the `checkVertex` is in the `vertexVec`. And if it is, returns its index from `indexVec`. 
 * Otherwise returns `-1`
 * 
 * @param vertexVec Vector list that holds the vertices.
 * @param indexVec Vector list that holds the indicies.
 * @param checkVertex Vertex to check if inside the `vertexVec`.
 * 
 * @returns `int32_t` - index from `indexVec` if found. Otherwise `-1`.
 * 
 */
int32_t checkIfVertexInList( 
    Buffer< ObjectVertex > vertexVec, 
    Buffer< uint32_t > indexVec, 
    ObjectVertex checkVertex 
);




/**
 * @brief Loads the `vertexList` into the `vertexBufferPtr` and `indexBufferPtr`.
 * 
 * @tparam entityType Type of entity to load the data from. 
 * @tparam arraySize Size of the vertex list to load.
 * 
 * @param entity Entity to assign data to.
 * @param vertexList List of vertices to add.
 * @param vertexBuffer Vertex Buffer. 
 * @param indexBuffer Index Buffer. 
 * 
 * @returns `entityType` - Entity of type `entityType` with data from loading vertices. 
 */
template< typename entityType, std::size_t arraySize >
entityType& loadVertexData( 
    entityType& entity, 
    std::array< ObjectVertex, arraySize >&vertexList,
    Buffer< ObjectVertex >& vertexBuffer, 
    Buffer< uint32_t >& indexBuffer ){

    if ( vertexList.size() == 0 ){
        
        return entity;
    }

    Buffer< ObjectVertex > tempVertBuffer;
    Buffer< uint32_t > tempIndexBuffer;


    // // TODO: Have a cache to store last known vertices, then loop over this first to find a cache hit. 
    // //       Then only if a cache hit is not found, we go back and check the main tempVertexBuffer for duplicates.
    //
    // Buffer< ObjectVertex, 4 > vertexCache; /** < Stores the last 4 vertices, as they may have been reused */
    // Buffer< uint32_t, 4 > indexCache; /** < Stores the last 4 indicies, as they may have been reused */



    // Adds the first index, so we dont need an if to check if the `tempVertBuffer` and `tempIndexBuffer` are empty or not. 

    ObjectVertex vertex = vertexList[0];
    int32_t index = 0;
    
    index = tempVertBuffer.push_back( vertex );
    tempIndexBuffer.push_back( index );

    if ( vertexList.size() > 1 ){

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
    }
    entity.vertexCount = tempIndexBuffer.size();

    // Sets the offsets before adding the new items to the Buffers 
    entity.vertexOffset = vertexBuffer.size();
    entity.indexOffset = indexBuffer.size();

    vertexBuffer.push_back( tempVertBuffer );
    indexBuffer.push_back( tempIndexBuffer );

    return entity;
}








/**
 * @brief Removes duplicate vertex data from the `vertexList`
 * 
 * @details 
 * Maybe we can store this data in a cache somewhere, so we dont have to
 * de-duplicate the vertex list everytime we load an item ?
 */
template< uint32_t newSize, uint32_t oldSize >
std::array< ObjectVertex, newSize > deduplicateList( std::array< ObjectVertex, oldSize > vertexList );