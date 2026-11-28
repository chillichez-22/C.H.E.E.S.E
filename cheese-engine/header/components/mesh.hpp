#pragma once

#include <vector>
#include <glad/glad.h>

#include "components/component.hpp"

class Mesh : public Component{

private:

    unsigned int m_vbo = 0;     /*< Opengl buffer id for the vbo. */
    unsigned int m_vao = 0;     /*< Opengl buffer id for the vao. */
    unsigned int m_ebo = 0;     /*< Opengl buffer id for the ebo. */

    unsigned int m_vertexCount = 0;     /*< Number of vertexes in the vbo*/

    GLenum m_renderMode = GL_TRIANGLES; /*< Mode to render the mesh. */


public:


    /**
     * @brief Default constructor for the mesh.
     * 
     */
    Mesh();

    /**
     * @brief Constructor for a new mesh.
     * 
     * Default values are for a 3 attributes: Pos Uv Normal; 
     * 
     * With layout: 3 float, 2 int, 3 float. 
     * 
     * 
     * @param vertexData Contiguous list of floats for the vertex data.
     * @param indexData Contiguous list of ints for the index data.
     * 
     * 
     * @param attributeCount Number of attributes.
     * 
     * @param countsOfAttributes List containing the number of values each attribute has. 
     * Example: `float float float | float float` = `3, 2`
     * 
     * @param typesOfAttributes List containing the types for each attribute's values.
     * Example: `Pos | UV | Normal` = `float, int, float`
     * 
     * 
     * @param indexOffset Offset for the starting position of the indexData.
     * @param vertexOffset Offset for the starting vertex in the indexData.
     * 
     */
    Mesh( 

        std::vector<float> vertexData,
        std::vector<int> indexData,

        int attributeCount = 3,
        std::vector<int> countsOfAttributes = std::vector<int>{3, 2, 3},
        std::vector<GLenum> typesOfAttributes = std::vector<GLenum>{ GL_FLOAT, GL_INT, GL_FLOAT },

        int indexOffset = 0,
        int vertexOffset = 0
    );
    


    /**
     * @brief Destructor for the mesh.
     */
    ~Mesh();


    // Initialiser

    /**
     * @brief Calculates the stride, and the cumulative stride for each attribute.
     * 
     * 
     * @param attributeCount Number of attributes.
     * 
     * @param countsOfAttributes List containing the number of values each attribute has. 
     * Example: `float float float | float float` = `3, 2`
     * 
     * 
     * @returns `std::vector<int>` - The offset stride for each attribute, where the final list value is the full stride.
     *
     * ```
     * Strides:
     * 0---3--5------8
     * Pos Uv Normal
     * float float float | float float | float float float
     * ```
     * 
     */
    std::vector< int > calculateStrides(

        int attributeCount,
        std::vector<int> countsOfAttributes
    );

    /**
     * @brief Binds the mesh's data into opengl buffers.
     * 
     * 
     * @param vertexData Contiguous list of floats for the vertex data.
     * @param indexData Contiguous list of ints for the index data.
     * 
     * 
     * @param attributeCount Number of attributes.
     * 
     * @param countsOfAttributes List containing the number of values each attribute has. 
     * Example: `float float float | float float` = `3, 2`
     * 
     * @param typesOfAttributes List containing the types for each attribute's values.
     * Example: `Pos | UV | Normal` = `float, int, float`
     * 
     * 
     * @param indexOffset Offset for the starting position of the indexData.
     * @param vertexOffset Offset for the starting vertex in the indexData.
     */
    void bind( 

        std::vector<float> vertexData,
        std::vector<int> indexData,

        int attributeCount = 3,
        std::vector<int> countsOfAttributes = std::vector<int>{3, 2, 3},
        std::vector<GLenum> typesOfAttributes = std::vector<GLenum>{ GL_FLOAT, GL_INT, GL_FLOAT },

        int indexOffset = 0,
        int vertexOffset = 0
    );


    // Getter

    /** 
     * @brief Getter for the mode to render the mesh.
     * 
     * @returns `GLenum&` - Reference for the mode to render.
    */
    GLenum& getRenderMode();


    // Setter

    /** 
     * @brief Getter for the mode to render the mesh.
     * 
     * @param mode Mode to render the mesh: GL_POINTS, GL_LINES, GL_TRIANGLES.
    */
    void setRenderMode( GLenum mode );

};