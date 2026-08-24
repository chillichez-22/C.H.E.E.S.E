#pragma once

#include <string>
#include <SDL3/SDL.h>

/**
 * @brief Abstract class for any UI Element to be rendered onto the screen as a part of a `UI`.
 * 
 * @details Allows children to have this as their pointer, thus allowing the children be added to the same vectors, and lists.
 */
class UIElement{

protected:

    std::string type;
    bool isInteractable = false;

    void draw( SDL_Window* window, SDL_Renderer* renderer );

public:

    /**
     * @brief Default destructor for the abstract class. 
     */
    ~UIElement() = default;


};
