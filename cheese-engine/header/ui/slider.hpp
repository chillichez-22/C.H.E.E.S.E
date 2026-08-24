#pragma once

#include "colour.hpp"
#include "text.hpp"
#include "interactable.hpp"


/**
 * @details Used to allow children to have this as their pointer, thus allowing there pointers to be added to vectors, and lists.
 */
class BaseSlider : public Interactable{

public:

    virtual ~BaseSlider() = default;

};

/**
 * @brief A general purpose slider that changes values depending on the axis affected.
 */
template <typename ShapeType> 
class Slider : public BaseSlider{

private:

    // Shape
    ShapeType buttonShape;

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



public:

    Slider( ShapeType buttonShape );

};
