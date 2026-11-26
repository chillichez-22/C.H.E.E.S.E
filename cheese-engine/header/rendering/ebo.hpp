#pragma once

#include <vector>


/**
 * @brief Entity Buffer Object ( EBO )
 * 
 * An EBO is a struct holding data on how vertex data should be read and formed into tris.
 */
struct EBO {

private:

    unsigned int m_ID;  /*< OpenGl buffer id. */

    std::vector< unsigned int >* m_indexDataPtr{}; /*< Pointer to the index data for the EBO. */

    unsigned int m_indexOffset = 0; /*< Offset for the starting index in the indexData, for this object. */
    unsigned int m_vertexOffset = 0;  /*< Offset for the starting vertex in the vao, for this model. */

    
public:


    /**
     * @brief Default constructor for an Entity Buffer Object ( EBO ).
     */
    EBO() = default;

    /**
     * @brief Constructor for a new Entity Buffer Object ( EBO ).
     * 
     * @param indexData Vector of indexes that point to corresponding vertex data.
     * @param indexOffset Offset for the starting position of the indexData.
     * @param vertexOffset Offset for the starting vertex in the indexData.
     * 
     */
    EBO( 
        std::vector< unsigned int > indexData,
        unsigned int indexOffset = 0,
        unsigned int vertexOffset = 0
    );

    /**
     * @brief Constructor for a new Entity Buffer Object ( EBO ).
     * 
     * @param indexDataPtr Pointer to a vector of indexes that point to corresponding vertex data.
     * @param indexOffset Offset for the starting position of the indexData.
     * @param vertexOffset Offset for the starting vertex in the indexData.
     *      
     */
    EBO( 
        std::vector< unsigned int >* indexDataPtr,
        unsigned int indexOffset = 0,
        unsigned int vertexOffset = 0
    );


    /**
     * @brief Destructor for the Entity Buffer Object ( EBO ).
     */
    ~EBO();



    // Getter

	/**
	 * @brief Getter for the EBO's OpenGl id.
	 *  
	 * @returns `unsigned int&` - Reference to an unsigned int, for the ebo's id.
	 */	
	unsigned int& getId();

    /**
     * @brief Getter for the index data.
     * 
     * @returns `const vector<unsigned int>&` - reference to a integer vector for indexData.
     */
    std::vector< unsigned int >*& getIndexData();

    /**
     * @brief Getter for the index offset.
     * 
     * @returns `const unsigned int&` - const reference to an integer for the index offset.
     */
    unsigned int& getIndexOffset();

    /**
     * @brief Getter for the vertex offset.
     * 
     * @returns `const unsigned int&` - const reference to an integer for the vertex offset.
     */
    unsigned int& getVertexOffset();


    // Setter

    /**
     * @brief Setter for the EBO's OpenGl Id.
     * 
     * @param id New id to set.
     */
    void setId( unsigned int id );


    /**
     * @brief Setter for the index data pointer.
     * 
     * @param indexDataPtr New index data to set.
     */
    void setIndexData( std::vector< unsigned int >* indexDataPtr );

    /**
     * @brief Setter for the index data.
     * 
     * Creates a new int vector on the heap,
     * 
     * @param indexData New index data to set.
     */
    void setIndexData( std::vector< unsigned int > indexData );


    /**
     * @brief Setter for the index offset.
     * 
     * @param offset New index offset to set.
     */
    void setIndexOffset( unsigned int offset );

    /**
     * @brief Setter for the vertex offset.
     * 
     * @param offset New vertex offset to set.
     */
    void setVertexOffset( unsigned int offset );
};