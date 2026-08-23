#pragma once

#include "colour.hpp"
#include "text.hpp"
#include "interactable.hpp"


/**
 * @brief Abstract class for a button instance. 
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
    ColourF symbolColour;
    char symbol;

protected:

    // States
    bool isHovering = false;
    bool isPressed = false;
    bool isHolding = false;

    // Colours
    ColourF mainColour;
    ColourF outlineColour;

    ColourF hoveringColour;
    ColourF selectedColour;

    // Shape
    ShapeType buttonShape;

public:

    Checkbox( ShapeType buttonShape );

};
