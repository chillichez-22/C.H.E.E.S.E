#pragma once

#include "colour.hpp"

// Action Buttons

class BaseButton{

    // States
    bool isHovering = false;
    bool isPressed = false;
    bool isHolding = false;


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


};

class SquareCheckbox : BaseCheckbox{
    
};

class CircleCheckbox : BaseCheckbox{
    
};