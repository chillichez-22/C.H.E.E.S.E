#pragma once


#include "button.hpp"
#include "slider.hpp"
#include "text.hpp"
#include "vector_2.hpp"
#include "mouse.hpp"

#include <vector>

/**
 * @brief A UI page for the project, holding UI elements such as: interactables, text and other. 
 */
struct UI{

    // Elements
    std::vector<SquareButton> squareButtons;
    std::vector<CircleButton> circleButtons;

    std::vector<SquareCheckbox> squareCheckboxes;
    std::vector<CircleCheckbox> circleCheckboxes;

    std::vector<Slider> sliders;

    std::vector<TextBox> textBoxes;

    // Methods

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