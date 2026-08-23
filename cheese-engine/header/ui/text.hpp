#pragma once

#include "ui_elements.hpp"

#include "colour.hpp"
#include "vector_2.hpp"

#include <string>


/**
 * @brief A Text box rendered as a UI Element.
 */
class TextBox : public UIElement{

    std::string contents = ""; 
    
    float fontSize;
    ColourF fontColour;

    Vector2 centrePos;
    Vector2 size;
    
};