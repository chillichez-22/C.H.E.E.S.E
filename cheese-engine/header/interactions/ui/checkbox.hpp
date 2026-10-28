#pragma once

// Outside Scope
#include "colour.hpp"
#include "text.hpp"

// Own Scope
#include "interactable.hpp"


/**
 * @brief Non-templated abstract class for any checkbox with an undefined shape.
 * 
 * @details Gives every different Button< ShapeType > a common non-templated type.
 *          This ensures a base checkbox pointer `BaseCheckbox*` can be added into other UI Elements via composition.
 *          ( Because parent pointers `BaseCheckbox*` can point to children )
 * 
 */
class BaseCheckbox : public Interactable{

public:

    /**
     * @brief Default destructor for the abstract class. 
     */
    virtual ~BaseCheckbox() = default;

};


/**
 * @brief A general purpose button that does an action upon being clicked.
 */
template <typename ShapeType> 
class Checkbox : public BaseCheckbox{
private:
    
    bool state = false; 

    // Symbol
    ColourF symbolColour = ColourF( 0.f, 0.f, 0.f, 255.f );
    char symbol = "X";

protected:

    // Shape
    ShapeType buttonShape = NULL;

public:

    
    /**
     * @brief Constructor for a checkbox with specified shape.
     * 
     * @param checkboxShape Shape of the checkbox.
     * @param mainColour Background colour of the checkbox.
     * @param hoveringColour Colour of the checkbox, when hovered over by the mouse.
     * @param selectedColour Colour of the checkbox, when pressed or held over by the mouse.
     * @param symbol Character to display, when the checkbox is activated ( or true ).
     * @param symbolColour Colour of the `symbol` to display.
     * @param startState State the checkbox you begin with.
     * 
     * @returns `Button<ShapeType>` New checkbox instance with specified shape.
     */
    Checkbox( 
        ShapeType& checkboxShape,
        ColourF& mainColour,
        ColourF& hoveringColour = NULL,
        ColourF& selectedColour = NULL,
        char& symbol = "X",
        ColourF& symbolColour = ColourF( 0.f, 0.f, 0.f, 255.f ),
        bool& startState = false
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
     * @brief Draw call for the checkbox.
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

    ShapeType* getShape();

    bool& getState();
    char& getSymbol();
    ColourF& getSymbolColour();

    // Setters

    void setPointerState( PointerState newState );

    void setMainColour( ColourF& newColour );
    void setHoveringColour( ColourF& newColour );
    void setSelectedColour( ColourF& newColour );

    void setBorderColour( ColourF& newColour );
    void setBorderWidth( float newWidth );

    void setShape( ShapeType* newShape );

    void setSymbol( char& newSymbol );
    void setSymbolColour( ColourF& newColour );


};
