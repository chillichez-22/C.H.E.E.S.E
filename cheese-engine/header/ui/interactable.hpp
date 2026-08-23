#pragma once

#include "ui_elements.hpp"

/**
 * @brief Abstract class to identify `UIElement`s that can be clicked, pressed, or interacted by the user in any way.
 * 
 * @details Allows children to have this as their pointer, thus allowing the children be added to the same vectors, and lists.
 */
class Interactable : public UIElement{

public:

    /**
     * @brief Default destructor for the abstract class. 
     */
    virtual ~Interactable() = default;

};

