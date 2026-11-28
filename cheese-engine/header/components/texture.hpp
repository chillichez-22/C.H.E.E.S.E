#pragma once

#include <string>

/**
 * @brief Texture object stored at each position in the wall.
 */
struct Texture{

public:

    int unit = -1;  /*< Texture's Unit. */
    int id = -1;    /*< Texture's Id. */
    std::string path = "";  /*< Texture's file path. */
    std::string name = "";  /*< Texture's file name. */


    /**
     * @brief Creates a new texture struct, holding texture data.
     * 
     * @param texUnit Unit for the texture.
     * @param texId Id for the texture.
     * @param texPath File-path for the texture.
     * @param texName Name for the texture.
     */
    Texture(
        int texUnit,
        int texId,
        std::string texPath,
        std::string texName
    ):
        unit( texUnit ),
        id( texId ),
        path( texPath ),
        name( texName )
    {};


};

