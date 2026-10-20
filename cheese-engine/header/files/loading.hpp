#pragma once

#include <cstdint>
#include <array>
#include <vector>
#include <string>

#include "buffer.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

#include "entity.hpp"

#include "rendering.hpp"



/**
 * @brief Loads in a new object into the object at the `entityPtr`.
 * 
 * @tparam entityType Type of entity to load the data from. 
 * 
 * @param entityPtr Pointer to the entity to load data into.
 * @param filepath String of the filepath to retrieve the data from.
 * @param vertexList List of vertices to add.
 * @param *vertexBufferPtr Pointer to the vertex buffer. 
 * @param *indexBufferPtr Pointer to the index buffer. 
 * 
 * @returns `entityType` - Entity of type `entityType` with data from loading. 
 */
template< typename entityType >
entityType* loadObject( 
    entityType* entityPtr, 
    std::string filepath, 
    buffer< ObjectVertex >* vertexBuffer, 
    buffer< uint32_t >* indexBuffer 
); 


/**
 * @brief Loads the `vertexList` into the `vertexBufferPtr` and `indexBufferPtr`.
 * 
 * @tparam entityType Type of entity to load the data from. 
 * @tparam arraySize Size of the vertex list to load.
 * 
 * @param entityPtr Pointer to the entity to assign data to.
 * @param vertexList List of vertices to add.
 * @param *vertexBufferPtr Pointer to the vertex buffer. 
 * @param *indexBufferPtr Pointer to the index buffer. 
 * 
 * @returns `entityType` - Entity of type `entityType` with data from loading vertices. 
 */
template< typename entityType, uint32_t arraySize >
entityType* loadVertexData( 
    entityType* entityPtr, 
    std::array< ObjectVertex, arraySize > vertexList,
    buffer< ObjectVertex >* vertexBufferPtr, 
    buffer< uint32_t >* indexBufferPtr 
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
    std::vector< ObjectVertex > vertexVec, 
    std::vector< uint32_t > indexVec, 
    ObjectVertex checkVertex 
);





/**
 * @brief Removes duplicate vertex data from the `vertexList`
 * 
 * @details 
 * Maybe we can store this data in a cache somewhere, so we dont have to
 * de-duplicate the vertex list everytime we load an item ?
 */
template< uint32_t newSize, uint32_t oldSize >
std::array< ObjectVertex, newSize > deduplicateList( std::array< ObjectVertex, oldSize > vertexList );