
#include <exception>
#include <iostream>

#include "rendering/texture_manager.hpp"


// Private

int TextureManager::findNextSpaceOnTheWall(){

	// Linearly loops through the wall
	for( int i = 0; i < m_textureWall.size(); i++ ){

		if ( m_textureWall[i] != nullptr ){

			return i;
		}
	}

	return -1;
}

int TextureManager::loadTexture( 
    const char* path 
){

    return -1;
}



// Public

TextureManager::TextureManager(){

	m_textureWall.fill( nullptr );
	m_textureCount = 0;
}

TextureManager::~TextureManager(){

    // Frees the memory
    for( int i = 0; i < TEXTURE_WALL_SIZE; i++ ){

        delete( m_textureWall[ i ] );
	    m_textureWall[ i ] = nullptr;
    }

}


int TextureManager::addTexture( 
    const char* path 
){

	int textureID = loadTexture( path );
	int textureUnit = findNextSpaceOnTheWall();

	// No more spaces left
	if ( textureUnit == -1 ){

		throw std::length_error( "ERROR: Max space on the texture wall. Too many texture have been loaded." );
		return -1;
	}

    Texture* newTex = new Texture(
        textureUnit,
        textureID,
        path,
        path
    );


	m_textureWall[ textureUnit ] = newTex;

	return textureUnit;
	
}

void TextureManager::removeTexture( 
    int textureUnit 
){

    delete( m_textureWall[ textureUnit ] );
	m_textureWall[ textureUnit ] = nullptr;

	m_textureCount -= 1;
};