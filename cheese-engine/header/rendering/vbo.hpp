#pragma once

#include <vector>
#include <iostream>
#include <glad/glad.h>

/**
 * 
 * @brief Vertex Buffer Object ( VBO )
 * 
 * A VBO is a struct holding vertex data, that will be read by a VAO.
 */
struct VBO{

private:

    unsigned int m_ID = 0;  /*< OpenGl buffer id. */

    std::vector< float >* m_vertexDataPtr{};    /*< Vertex data for the vbo. */ 

public:


    // Constructor
    
    /**
     * @brief Default constructor for a new Vertex Buffer Object ( VBO ).
     */
    VBO() = default;
    

    /**
     * @brief Constructor for a new Vertex Buffer Object ( VBO ).
     * 
     * @param vertexDataPtr Pointer to the vertex data stored on the heap.
     * @param id OpenGl id for the buffer. 
     */
    VBO(
        std::vector< float >* vertexDataPtr,
        unsigned int id = 0
    );

    /**
     * @brief Constructor for a new Vertex Buffer Object ( VBO ).
     * 
     * @param vertexData Vertex data stored on the heap.
     * @param id OpenGl id for the buffer. 
     */
    VBO(
        std::vector< float > vertexData,
        unsigned int id = 0
    );

    
    /**
     * @brief Default destructor for a new Vertex Buffer Object.
     */
    ~VBO();
    
    
    // Getter
    
	/**
     * @brief Getter for the VBO's OpenGl id.
     *  
     * @returns `unsigned int&` - Reference to an unsigned int, for the vbo's id.
	 */	
    unsigned int& getId();
    
    /**
     * @brief Getter for the VBO's copy of the vertex data.
     * 
     * @returns `vector< float >&` - Reference to the vbo's float vector of vertex data.
     * Read using a `VAO`.
     */
    std::vector< float >*& getVertexData();
    

    // Setter 

    /**
    * @brief Setter for the VBO's OpenGl Id.
    * 
    * @param id New id to set.
    */
    void setId( unsigned int id );

    /**
    * @brief Setter for the VBO's vertex data pointer. 
    * 
    */
    void VBO::setVertexData( std::vector<float>* vertexDataPtr );

    /**
    * @brief Setter for the VBO's vertex data.
    * 
    * Creates a new float vector on the heap, using the same data as the inputted `vertexData`.
    * 
    */    
    void VBO::setVertexData( std::vector<float> vertexData );

};