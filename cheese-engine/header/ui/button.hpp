#pragma once

#include "interactable.hpp"
#include "text.hpp"

#include "colour.hpp"
#include "vector_2.hpp"
#include "collision_result.hpp"

#include <string>


/**
 * @brief Non-templated abstract class for any button with an undefined shape.
 * 
 * @details Gives every different Button< ShapeType > a common non-templated type.
 *          This ensures a base button pointer `BaseButton*` can be added into other UI Elements via composition.
 *          ( Because parent pointers `BaseButton*` can point to children )
 * 
 */
class BaseButton : public Interactable{

public:

    virtual ~BaseButton() = default;

};


/**
 * @brief A general purpose button that does an action upon being clicked.
 */
template <typename ShapeType> /**< Default type for a shape.*/
class Button : public BaseButton{

private:
    
    // Text
    bool isUsingText = false; /**< Should the button also render text? */
    BaseTextBox* renderText = nullptr; /**< Text to display on top of the button. */

protected:

    // Shape
    ShapeType& buttonShape = NULL;

public:

    /**
     * @brief Constructor for a button with specified shape.
     * 
     * @param buttonShape Shape of the button.
     * @param mainColour Background colour of the button.
     * @param hoveringColour Colour of the button, when hovered over by the mouse.
     * @param selectedColour Colour of the button, when pressed or held over by the mouse.
     * @param textBox Text, linked to the button, to display.
     * 
     * @returns `Button<ShapeType>` New button instance with specified shape.
     */
    Button( 
        ShapeType& buttonShape,
        ColourF& mainColour,
        ColourF& hoveringColour = NULL,
        ColourF& selectedColour = NULL,
        BaseTextBox* textBox = nullptr
    );

    // Collision

    /**
     * @brief Checks if the mouse is colliding with the interactable's shape.
     * 
     * @param pointerPos Position of the pointer on the screen.
     * 
     * @returns `bool` If the collision has taken place.
     */
    bool isPointerColliding( Vector2 pointerPos );


    // Draw Call

    /**
     * @brief Draw call for the button.
     * 
     * @param window Pointer to the SDL window.
     * @param renderer Pointer to the SDL renderer.
     */
    void draw( 
        SDL_Window* window, 
        SDL_Renderer* renderer
    );

    // Getters

    PointerState& getPointerState();

    ColourF& getMainColour();
    ColourF& getHoveringColour();
    ColourF& getSelectedColour();

    ColourF& getBorderColour();
    float& getBorderWidth();

    bool& getIsUsingText();
    BaseTextBox* getRenderText();

    ShapeType* getShape();

    // Setters

    void setPointerState( PointerState newState );

    void setMainColour( ColourF& newColour );
    void setHoveringColour( ColourF& newColour );
    void setSelectedColour( ColourF& newColour );

    void setBorderColour( ColourF& newColour );
    void setBorderWidth( float newWidth );

    void setRenderText( BaseTextBox* newText );

    void setShape( ShapeType* newShape );

};
