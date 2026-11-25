#pragma once

#include "components/transform.hpp"

#include <cstdint>

/**
 * @brief Base entity class for gameobjects in the scene.
 */
class Entity{

private:

	uint32_t m_vertexCount;   /*< Number of vertexes making up the object */
	uint32_t m_indexOffset;   /*< Offset of the index buffer, ( where the object's vertex's indicies start )*/
	uint32_t m_vertexOffset;  /*< Offset of the vertex buffer, ( where the object's vertex's start )*/

	/*

	// Suppose the vertex buffer holds 3 tris:

	tri1: v0, v1, v2
	tri2: v1, v2, v3
	tri3: v2, v3, v4

	// These can be put below in the vertex and index buffer like so:

	Vertex Buffer
	----------------------
	| v0, v1, v2, v3, v4 |
	----------------------

	Index Buffer
	-----------------------------
	| 0, 1, 2, 0, 1, 2, 0, 1, 2 |
	-----------------------------

	// If we wanted to get to get the "tri2"

	// We create an `Entity` ( this class or child of this class )
	// We can use a `vertexCount` to determine the length of the object in the index buffer.

	I-Buffer
	-----------------------------
	| 0, 1, 2, 0, 1, 2, 0, 1, 2 |
	-----------------------------
				^  ^  ^    
				-------
				3 wide


	// Then use the `indexOffset` to determine which of the 3 indexes to use.
	// And where to start offseting the indices.

	I-Buffer
	-----------------------------
	| 0, 1, 2, 0, 1, 2, 0, 1, 2 |
	-----------------------------
				^  ^  ^
		|        |  
		----------
		3 offset

	
	// Then use the `vertexOffset` to determine which of 3 vertices the indices ( from the index buffer ), points to (in the vertex buffer ).

	V-Buffer
	----------------------
	| v0, v1, v2, v3, v4 |
	----------------------
		
		|    |
		------
		1 Wide 


	V-Buffer
	----------------------
	| v0, v1, v2, v3, v4 |
	----------------------
			^   ^   ^
		|    |
		------
		1 Wide

	// So using the `vertexOffset` to get the initial offset for the vertex buffer ( 1 ), 
	// then using adding that to each of 3 the indicies from the Index Buffer,
	// we can get the 3 vertices for "tri2" of: v1, v2, v3  

	*/

protected:

	Transform3D m_transform;	/*< Transform, with the position, rotation and scale of the entity. */ 


public:


	// Getters

    /**
     * @brief Getter for the camera's transform.
     * 
     * @returns `Transform3D` - Transform for the camera. Scale is not used.
     */
    Transform3D& getTransform();


};