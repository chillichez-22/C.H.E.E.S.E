#pragma once

#include <string>

class Scene{

private:

    int m_ID = -1; /*< Scene unique ID. */
    std::string m_name = "myNewScene";  /*< Scene's name. */


public:

    /**
     * @brief Default constructor for the scene.
     */
    Scene() = default;

    /**
     * @brief Default destructor for the scene.
     */
    ~Scene() = default;


    // Getters

    /**
     * @brief Getter for the scene's ID.
     * 
     * @returns `int&` - Reference to the scenes unique ID.
     */
    int& getID();

    /**
     * @brief Getter for the scene's name.
     * 
     * @returns `string&` - Reference to the scenes unique name.
     */
    std::string& getName();


    // Setter

    /**
     * @brief Setter the scene's ID. 
     * 
     * This id MUST be unique otherwise.
     * 
     * 
     * @param id New id to set.
     */
    void setID( int id );

    /**
     * @brief Setter for the scene's name. 
     * 
     * Used to help identify what scene we are currently working on.
     * 
     * 
     * @param name New name to set.
     */
    void setName( const char* name );

};

