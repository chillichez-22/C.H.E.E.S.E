#pragma once

#include "ui_element.hpp"

#include "colour.hpp"
#include "vector_2.hpp"
#include "collision_result.hpp"


/**
 * @brief Enum holding the different states an interactable can be in, relative to the mouse/pointer input.
 */
enum class PointerState{

    NONE = 0,     /**< Cursor is not interacting with this interactable.*/
    HOVERING = 1, /**< Cursor is over this interactable.*/
    PRESSING = 2, /**< Cursor is pressing this interactable. */
    HOLDING = 3   /**< Cursor is holding this interactable. */

};


/**
 * @brief Abstract class to identify `UIElement`s that can be clicked, pressed, or interacted by the user in any way.
 * 
 * @details Allows children to have this as their pointer, thus allowing the children be added to the same vectors, and lists.
 */
class Interactable : public UIElement{
    
protected:

    // States
    PointerState pointerState = PointerState();

    // Colours
    ColourF mainColour; /**< Colour of the interactable's background.*/
    ColourF hoveringColour; /**<Colour when the interactable is hovered with the mouse, but not clicked. ( Uses `mainColour` if not defined ). */
    ColourF selectedColour; /**< Colour when the mouse clicks/holds on an interactable. ( Uses `mainColour` if not defined ). */
    
    // Border
    ColourF borderColour = ColourF( 0.f, 0.f, 0.f, 255.f ); /**< Colour of the border of the interactable.*/
    float borderWidth = 4.0f; /**< Width of the border of the interactable.*/


    // Methods

    /**
     * @brief Draw call for the interactable.
     * 
     * @param window Pointer to the SDL window.
     * @param renderer Pointer to the SDL renderer.
     */
    void draw( 
        SDL_Window* window, 
        SDL_Renderer* renderer
    );


    /**
     * @brief Checks if the mouse is colliding with the interactable's shape.
     * 
     * @param pointerPos Position of the pointer on the screen.
     * 
     * @returns `bool` If the collision has taken place.
     */
    bool isPointerColliding( Vector2 pointerPos );

public:

    /**
     * @brief Default destructor for the interactable. 
     */
    virtual ~Interactable() = default;


};