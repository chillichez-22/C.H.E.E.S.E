#pragma once

#include <array>
#include <string>
#include <glad/glad.h>

#include "components/texture.hpp"


#define TEXTURE_WALL_SIZE 16


/**
 * @brief Static manager for textures and image files, used in rendering.
 */
class TextureManager{

private:

    unsigned int m_textureCount;    /*< Number of textures made, used to assign new TextureUnits. */
    std::array< Texture*, TEXTURE_WALL_SIZE > m_textureWall;   /*< Vector holding the TextureId's, where the index is the TextureUnits. */

private:

    /**
     * @brief Finds the next free space on the wall and returns it's index for the TextureUnit.
     * 
     * Returns `-1` if a space could nt be allocated.
     * 
     * @returns `int` - Index of the next free space on the wall.
     */
    int findNextSpaceOnTheWall();

    
    /**
     * @brief Loads a texture into OpenGL, and returns its unique index in the wall.
     * 
     * @param path File path to the texture image.
     * 
     * @returns `static int` - Texture unit, index location of the texture in the texture wall.
     */
    int loadTexture( char const* path );


public:


    /** 
     * @brief Constructor for the texture manager. 
     */
    TextureManager();

    /**
     * @brief Deconstructor for the texture manager.
     */
    ~TextureManager();


    
    /**
     * @brief Loads and adds a texture to the texture wall, so we can easily add and remove textures.
     * 
     * @param path File path to the texture image.
     * 
     * @returns `int` TextureUnit, index of the wall.
     */
    Texture* addTexture( const char* path );

    /**
     * @brief Remove a texture from the texture wall.
     * 
     * @attention Takes in the TextureUnit. NOT the TextureId
     * 
     * @param textureUnit Texture Unit, for the index of the wall.
     */
    void removeTexture( int textureUnit );
    

    // Getter

    /**
     * @brief Gets a texture from the texture wall using an index.
     * 
     * @param texUnit Index for the wall.
     * 
     * @returns `Texture*` - Pointer to a texture struct holding data about the texture.
     */
    Texture* getTexture( int texUnit );

    /**
     * @brief Gets a texture from the texture wall using a texture's id.
     * 
     * @param texID Id of a texture.
     * 
     * @returns `Texture*` - Pointer to a texture struct holding data about the texture.
     */
    Texture* getTextureFromID( int texID );

        /**
     * @brief Gets a texture from the texture wall using a texture's id.
     * 
     * @param texName Name of a texture.
     * 
     * @returns `Texture*` - Pointer to a texture struct holding data about the texture.
     */
    Texture* getTextureFromName( std::string texName );

};