#pragma once

#include "component.hpp"

#include <array>
#include <cstdint>
#include <stdfloat>

struct Transform3D : public Component{

    std::array< std::float64_t, 3 > position = { 0.f, 0.f, 0.f }; /**< Array of 64 Bit floats for positional values */
    std::array< std::float64_t, 3 > rotation = { 0.f, 0.f, 0.f }; /**< Array of 64 Bit floats for euler rotation values */
    std::array< std::float32_t, 3 > scale = { 1.f, 1.f, 1.f};     /**< Array of 32 Bit floats for scalar values */

};