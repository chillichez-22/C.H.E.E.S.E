#pragma once

#include <glad/glad.h>
#include "components/component.hpp"

//#include "rendering"
#include "rendering/vbo.hpp"
#include "rendering/vao.hpp"
#include "rendering/ebo.hpp"

class Mesh{

private:

    VBO* m_vboPtr = nullptr;    /*< Pointer to the VBO struct in the heap. */
    VAO* m_vaoPtr = nullptr;    /*< Pointer to the VAO struct in the heap.  */
    EBO* m_eboPtr = nullptr;    /*< Pointer to the EBO struct in the heap. */

    GLenum m_renderMode = GL_TRIANGLES; /*< Mode to render the mesh. */


public:

    /**
     * @brief Default constructor for the mesh.
     * 
     */
    Mesh();

    /**
     * @brief Destructor for the mesh.
     */
    ~Mesh();


    // Initialiser

    /**
     * @brief Binds the mesh's `VBO`, `VAO` and `EBO`.
     */
    void bind( );


    // Getter

    /**
     * @brief Getter for the VBO's pointer.
     * 
     * @return `VBO*` - Reference to the mesh's vbo.
     */
    VBO*& getVbo();

    /**
     * @brief Getter for the VAO's pointer.
     * 
     * @return `VAO*` - Reference to the mesh's vao.
     */
    VAO*& getVao();

    /**
     * @brief Getter for the EBO's pointer.
     * 
     * @return `EBO*` - Reference to the mesh's ebo.
     */
    EBO*& getEbo();

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