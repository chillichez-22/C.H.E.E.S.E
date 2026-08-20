#pragma once

#include "colour.hpp"
#include "text.hpp"

// Action Buttons

class BaseButton{

private:

    // States
    bool isHovering = false;
    bool isPressed = false;
    bool isHolding = false;

    // Colours
    ColourF mainColour;
    ColourF outlineColour;

    ColourF hoveringColour;
    ColourF selectedColour;

    // Text
    bool isUsingText;
    TextBox renderText;

};

class SquareButton : BaseButton{
    
};

class CircleButton : BaseButton{
    
};


// Boolean Checkboxes

class BaseCheckbox{

    // States
    bool isHovering = false;
    bool isPressed = false;
    bool isHolding = false;

    // Colours
    ColourF mainColour;
    ColourF outlineColour;
    ColourF symbolColour;

    ColourF hoveringColour;
    ColourF selectedColour;

};

class SquareCheckbox : BaseCheckbox, SquareButton{
    
};

class CircleCheckbox : BaseCheckbox, CircleButton{
    
};