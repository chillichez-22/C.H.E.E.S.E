#pragma once

#include <array>
#include <vector>
#include <iostream>
#include <glad/glad.h>


/**
 * @brief Vertex Array Object ( VAO ).
 * 
 * A VAO is a struct holding data about how a VBO should be read.
 */
struct VAO{

private:

    unsigned int m_ID;  /*< OpenGl buffer id. */

	int m_attrCount; /*< Number of attributes in this VAO. */

	std::vector< int > m_attrValueCounts{};  /*< Number of values per attribute. */
	std::vector< GLenum > m_attrValueTypes{};    /*< Type of every value per attribute. */


	// Dont manually set the strides, they are auto calculated upon

	/*
	We +1 to the size of this, to put 0 at the start position, at index 0. 
	We iterate over i-1, to get the relative offset not the cumulative, so each value is [ n-1 ] where n is the index. 

	So the first index value will be 0.
	Second should have the value of [ index 1 ], 
	Third should have the value of [ index 2 ].... and so on. 

	*/

	//< Stride for each attribute, plus all the previous ones it takes to get there. Has a size of m_attrCount + 1, [See Vao.h for more description]*/
	std::vector<GLsizei> m_cumulativeAttrStrides{}; 

	GLsizei m_stride;    /*< Stride of each vertex. */


public:

    // Constructors

	/**
	 * @brief Default constructor for a new Vertex Array Object ( VAO ).
	 * 
	 */
	VAO() = default;

	/**
	 * @brief Constructor for a new Vertex Array Object ( VAO ).
	 * 
	 * @brief attrCount Number of attributes in the VAO
	 */
	VAO( int attrCount );

	/**
	 * @brief Constructor for a new Vertex Array Object ( VAO ).
	 * 
	 * @brief attrCount Number of attributes in the VAO
	 */
	VAO(  
		int attrCount,
		std::vector< int > attrValueCounts,
		std::vector< GLenum > attrValueTypes
	);


	/**
	 * @brief Default destructor for a VAO.
	 */
	~VAO() = default;


    // Initialisation

	/**
	 * @brief Calculates the `m_stride` and `m_cumulativeAttrStrides` for this Vao.
	 * 
	 * Is called in bindToVBO, so we almost never need to call it manually
	 */
	void calculateStrides();


	// Getters

	/**
	 * @brief Getter for the VAO's OpenGl id.
	 *  
	 * @returns `unsigned int&` - Reference to an unsigned int, for the vao's id.
	 */	
	unsigned int& getId();

	/**
	 * @brief Getter for the attribute count.
	 * 
	 * @returns `int&` - Reference to an int, for theattribute count.
	 */
	int& getAttrCount();

	/**
	 * @brief Getter for the attribute value count array.
	 * 
	 * @returns `span<int, attrCount>&` - Reference to a span of ints, of size attrCount. ( Can be implicitly coverted to an array )
	 */
	std::vector< int > getAttrValueCounts();

	/**
	 * @brief Getter for the attribute type array.
	 * 
	 * @returns `span<GLenum, attrCount>&` - Reference to a span of GLenum types, of size attrCount. ( Can be implicitly coverted to an array )
	 */
	std::vector< GLenum > getAttrValueTypes();

	/**
	 * @brief Getter for the cumulative attribute stride array.
	 * 
	 * @returns `span<GLsizei, attrCount&` - Reference to a span of GLsizei ( OpenGL int ) of size attrCount. ( Can be implicitly coverted to an array )
	 */
	std::vector< GLsizei > getCumulativeAttrStrides();

	/**
	 * @brief Getter for the stride.
	 * 
	 * @returns `GLsizei&` - Reference to a GLsizei ( OpenGL int ) for the stride.
	 */
	GLsizei& getStride();

	

	// Setters

    /**
     * @brief Setter for the VAO's OpenGl Id.
     * 
     * @param id New id to set.
     */
    void setId( unsigned int id );

	/**
	 * @brief Setter for the attribute value count array.
	 * 
	 * @param attrValueCounts (Implicitly converted) Array of ints to specify how many values make up each attribute.
	 */
	void setAttrValueCounts( std::vector< int > attrValueCounts );

	/**
	 * @brief Setter for the attribute type array.
	 * 
	 * @param attrTypes (Implicitly converted) Array of GLenum types, for the type of each attribute.
	 */
	void setAttrValueTypes( std::vector< GLenum > attrTypes );

};
