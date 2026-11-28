
#include <exception>
#include <iostream>

#include "files/texture_manager.hpp"


Texture emptyTexture(){

	return Texture( -1, -1, "", "" );
}

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


Texture* TextureManager::addTexture( 
    const char* path 
){

	std::string name = path;

	
	// Has the texture already been added?
	Texture* allocatedTex = getTextureFromName( name );
	if ( allocatedTex != nullptr ){

		return allocatedTex;
	}


	int textureID = loadTexture( path );
	int textureUnit = findNextSpaceOnTheWall();

	// No more spaces left
	if ( textureUnit == -1 ){

		throw std::length_error( "ERROR: Max space on the texture wall. Too many texture have been loaded." );
		return nullptr;
	}

    Texture* newTex = new Texture(
        textureUnit,
        textureID,
        path,
        name
    );

	m_textureWall[ textureUnit ] = newTex;

	return newTex;
	
}

void TextureManager::removeTexture( 
    int textureUnit 
){

    delete( m_textureWall[ textureUnit ] );
	m_textureWall[ textureUnit ] = nullptr;

	m_textureCount -= 1;
};



// Getters

Texture* TextureManager::getTexture( int texUnit ){

	return m_textureWall[ texUnit ];
}

Texture* TextureManager::getTextureFromID( int texID ){

	int texCount = 0;

	for( int i = 0; i < TEXTURE_WALL_SIZE; i++ ){

		// All textures looped through
		if ( m_textureCount < texCount ){
			break;
		}

		// Texture empty
		if ( m_textureWall[i] == nullptr ){
			continue;
		}


		texCount++;

		if ( m_textureWall[i]->id == texID ){
			return m_textureWall[i];
		}

	}

	return nullptr;
}

Texture* TextureManager::getTextureFromName( std::string texName ){

	int texCount = 0;

	for( int i = 0; i < TEXTURE_WALL_SIZE; i++ ){

		// All textures looped through
		if ( m_textureCount < texCount ){
			break;
		}

		// Texture empty
		if ( m_textureWall[i] == nullptr ){
			continue;
		}


		texCount++;

		if ( m_textureWall[i]->name == texName ){
			return m_textureWall[i];
		}

	}

	return nullptr;
}