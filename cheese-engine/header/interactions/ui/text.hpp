#pragma once

// External
#include <string>

// Outside Scope
#include "colour.hpp"
#include "vector_2.hpp"
#include "ttf.hpp"  

// Own Scope
#include "ui_element.hpp"


/**
 * @brief Non-templated abstract class for any textbox with an undefined shape.
 * 
 * @details Gives every different TextBox< ShapeType > a common non-templated type.
 *          This ensures a text box base pointer `BaseTextBox*` can be added into other UI Elements via composition.
 *          ( Because parent pointers `BaseTextBox*` can point to children )
 * 
 */
class BaseTextBox : public UIElement{

    BaseTextBox();
    ~BaseTextBox() = default;
};


/**
 * @brief A Text box rendered as a UI Element.
 */
template <typename ShapeType> 
class TextBox : public BaseTextBox{

private:

    // Text
    std::string contents = ""; /**< Text to display of the text.*/
    Font* font; /**< Font for the text.*/
    float fontSize = 10.f; /**< Size of the text. ( default is 10.f )*/
    ColourF& fontColour = ColourF( 0.f, 0.f, 0.f, 255.f ); /**< Colour of the text. ( default is black )*/

    // Shape
    ShapeType& shape = NULL; /**< Shape of the TextBox.*/
    ColourF& shapeColour = NULL; /**< Colour of the background of the TextBox.*/

    // Border
    float borderWidth = 4.0f; /**< Width of the border outline of the TextBox.*/
    ColourF& borderColour = ColourF( 0.f, 0.f, 0.f, 255.f ); /**< Colour of the border outline of the TextBox. ( default is black )*/

public:

    /** 
     * @brief Constructor for a TextBox.
     * 
     * @param shape Shape of the TextBox.
     * @param shapeColour Colour of the TextBox's background.
     * @param text String for the text to draw.
     * @param font Pointer to the font to use.
     * @param fontSize Size of the text to draw.
     * @param fontColour Colour of the text to draw.
     * 
     * @returns `TextBox<ShapeType>` New text box instance with specified shape.
     * 
    */
    TextBox(
        ShapeType& shape,
        ColourF& shapeColour,
        std::string text = "",
        Font* font = nullptr,
        float fontSize = 10.0f,
        ColourF& fontColour = ColourF( 0.f, 0.f, 0.f, 255.f )
    );

    /**
     * @brief Default destructor for the text box.
     */
    ~TextBox() = default;


    // Draw Call

    /**
     * @brief Draw call for the text box.
     * 
     * @param window Pointer to the SDL window.
     * @param renderer Pointer to the SDL renderer.
     * 
     */
    void draw( 
        SDL_Window* window, 
        SDL_Renderer* renderer
    );


    // Getters

    std::string getContents();

    Font* getFont();
    float getFontSize();
    ColourF& getFontColour();

    ShapeType& getShape();
    ColourF& getShapeColour();

    float getBorderWidth();
    ColourF& getBorderColour();


    // Setters

    void setContents( std::string newContents ); 

    void setFont( Font* newFont );
    void setFontSize( float newSize );
    void setFontColour( ColourF& newColour );

    void setShape( ShapeType& newShape );
    void setShapeColour( ColourF& newColour );

    void setBorderWidth( float newWidth );
    void setBorderColour( ColourF& newColour );

};