#pragma once

// Own Scope
#include "circle.hpp"
#include "line_2d.hpp"
#include "rect.hpp"
#include "tri.hpp"

/**
 * @brief Abstract class for any shape in 2D, and 3D
 * 
 * @details Allows children to have this as their pointer.
 *          Thus allowing the children be added to the same vectors, and lists. 
 *          And allows objects to use this pointer if the child class is not yet defined. 
 */
class Shape{

};

/**
 * @brief Abstract class for any 2D shape
 * 
 * @details Allows children to have this as their pointer.
 *          Thus allowing the children be added to the same vectors, and lists. 
 *          And allows objects to use this pointer if the child class is not yet defined. 
 */
class Shape2D : public Shape{

};

/**
 * @brief Abstract class for any 3D shape
 * 
 * @details Allows children to have this as their pointer.
 *          Thus allowing the children be added to the same vectors, and lists. 
 *          And allows objects to use this pointer if the child class is not yet defined. 
 */
class Shape3D : public Shape{

};