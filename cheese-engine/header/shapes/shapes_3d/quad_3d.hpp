#pragma once

// External
#include <array>
#include <cstdint>

// Outside Scope
#include "vector_3.hpp"

// Own Scope
#include "shape_3d.hpp"

/**
 * @brief A 3D Quad structure.
 */
struct Quad3D : public Shape3D{

public:

    std::array< Vector3, 4 > points = std::array< Vector3, 4 >();

};