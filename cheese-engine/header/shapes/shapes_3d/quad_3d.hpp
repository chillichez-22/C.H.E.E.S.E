#pragma once

#include <array>
#include <cstdint>

#include "maths/vector_3.hpp"
#include "shapes/shapes_3d/shape_3d.hpp"



/**
 * @brief A 3D Quad structure.
 */
struct Quad3D : public Shape3D{

public:

    std::array< Vector3, 4 > points = std::array< Vector3, 4 >();

};