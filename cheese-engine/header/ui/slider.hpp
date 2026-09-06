#pragma once

#include "button.hpp"
#include "text.hpp"
#include "interactable.hpp"

#include "shape_2d.hpp"
#include "line_2d.hpp"
#include "colour.hpp"

/**
 * @brief Abstract class for a slider with an unspecified button, shape and orientation.
 * 
 * @details Used to allow children to have this as their pointer, thus allowing there pointers to be added to vectors, and lists.
 */
class BaseSlider : public Interactable{

public:

    virtual ~BaseSlider() = default;

};

/**
 * @brief A general purpose slider that changes value, depending on the position of an internal button, for one axis only.
 */
template <typename ButtonShape> 
class LinearSlider : public BaseSlider{

private:

    // Shape
    
    Shape2D* shape; /**< Shape of the slider.*/
    ButtonShape button; /**< Button of the slider.*/
    Line2D line; /**< Horizontal line of the slider. */  

    // Values

    float minValue = -1.f;
    float startValue = 0.f;
    float maxValue = 1.f;
    
    float currentValue;

    // Display
    
    ColourF lineColour = ColourF( 180.f, 180.f, 180.f, 255.f );

    BaseTextBox* minValueText = NULL;
    BaseTextBox* startValueText = NULL;
    BaseTextBox* maxValueText = NULL;

public:

    LinearSlider( 
        ButtonShape buttonShape 
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

    //ShapeType* getShape();
    BaseButton* getButton();
    Line2D* getLine();

    ColourF& getLineColour();

    float& getMinValue();
    float& getStartValue();
    float& getMaxValue();

    BaseTextBox* getMinValueText();
    BaseTextBox* getStartValueText();
    BaseTextBox* getMaxValueText();

    
    // Setters

    void setPointerState( PointerState newState );

    void setMainColour( ColourF& newColour );
    void setHoveringColour( ColourF& newColour );
    void setSelectedColour( ColourF& newColour );

    void setBorderColour( ColourF& newColour );
    void setBorderWidth( float newWidth );


    //void setShape( ShapeType* newShape );

    void setButton( BaseButton* newButton );
    void setLine( Line2D* newLine );

    void setLineColour( ColourF& newColour );

    void setMinValueText( BaseTextBox* newText );
    void setStartValueText( BaseTextBox* newText );
    void setMaxValueText( BaseTextBox* newText );

};
