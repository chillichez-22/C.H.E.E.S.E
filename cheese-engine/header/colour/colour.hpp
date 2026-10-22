#pragma once

#include <cstdint>

struct Colour{

    virtual ~Colour() = default;
};


/**
 * @brief Colour variable with 4 floats of: r, g, b, a.
 */
struct ColourF : Colour
{
    ColourF();
    ColourF( float red, float green, float blue, float alpha = 1.0f );

    float r;
    float g;
    float b;
    float a;


    // Comparison Operator Overloading

    /**
     * @brief Returns the comparison of this + another `ColourF`.
     * 
     * @param colour Other colour to compare.
     * 
     * @return `bool` - Comparison of the two colours.
     */
    bool operator==( ColourF colour );

    /**
     * @brief Returns the inverse comparison of this + another `ColourF`.
     * 
     * @param colour Other colour to compare.
     * 
     * @return `bool` - Comparison of the two colours.
     */
    bool operator!=( ColourF colour );
};

/**
 * @brief Colour variable with 4 ints of: r, g, b, a.
 */
struct ColourI : Colour
{
    ColourI();
    ColourI( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255 );

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;


    // Comparison Operator Overloading

    /**
     * @brief Returns the comparison of this + another `ColourI`.
     * 
     * @param colour Other colour to compare.
     * 
     * @return `bool` - Comparison of the two colours.
     */
    bool operator==( ColourI colour );

    /**
     * @brief Returns the inverse comparison of this + another `ColourI`.
     * 
     * @param colour Other colour to compare.
     * 
     * @return `bool` - Comparison of the two colours.
     */
    bool operator!=( ColourI colour );
};
