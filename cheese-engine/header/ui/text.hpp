#pragma once

#include <string>
#include "colour.hpp"
#include "vector_2.hpp"

/**
 * @brief A Text box rendered as a UI Element.
 */
class TextBox{

    std::string contents = ""; 
    
    float fontSize;
    ColourF fontColour;

    Vector2 centrePos;
    Vector2 size;
    
};