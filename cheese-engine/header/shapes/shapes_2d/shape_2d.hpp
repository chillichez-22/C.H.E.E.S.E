#pragma once

// Outside Scope
#include "shape.hpp"

/**
 * @brief Abstract class for any 2D shape
 * 
 * @details Allows children to have this as their pointer.
 *          Thus allowing the children be added to the same vectors, and lists. 
 *          And allows objects to use this pointer if the child class is not yet defined. 
 */
class Shape2D : public Shape{

};
