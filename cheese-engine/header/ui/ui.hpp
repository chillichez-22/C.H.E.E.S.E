#pragma once

#include "button.hpp"
#include "checkbox.hpp"
#include "interactable.hpp"
#include "slider.hpp"
#include "text.hpp"
#include "ui_elements.hpp"

#include "vector_2.hpp"
#include "mouse.hpp"

#include <vector>
#include <memory>

/**
 * @brief A UI page for the project, holding UI elements such as: interactables, text and other. 
 */
class UI{

private:

    // Elements
    std::vector<UIElement*> elements;
    std::vector<Interactable*> interactables;

public:

    // Methods

    /**
     * @brief Destructor for the UI class.
     * 
     * @details Clears and releases all the memory associated with the `UI Elements` in the `elements` and `interactables` vectors.
     */
    ~UI();

    

    // Helpers

    /**
     * @brief Helper method to add interactables to the `interactables` vector.
     * 
     * @param *interactableObj Pointer to an `Interactable`
     */
    void addInteractables( Interactable* interactableObj ){
        interactables.push_back( interactableObj );
    }

    
    // UI Elements

    /**
     * @brief Draw call for every UI Element in the `elements` vector.
     * 
     */
    void drawAll();
    
    // Interactables

    /**
     * @brief Checks for hovering over, pressing and holding on every interactable.
     * 
     * @details Loops through all of the interactables only once, to save on loops.
     * 
     */
    void setStatesOnInteractables( Vector2& MousePos, MouseButtonEvent& leftMouseButton );

    /**
     * @brief Sets all interactables' `isPressed` state to false.
     */
    void unpressAll();

};