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


    // Arithmetic Operator Overloading


    /** 
     * @brief Returns the combination of this and `colour` and halves the total.
     * 
     * @attention Halves the value of the combination, due to the max component value being 255.
     * 
     * @param colour Colour to combine to this.
     * 
     * @returns `ColourF` Combination of the colours.
     */
    ColourF operator+( ColourF colour );

    /**
     * @brief Returns the scale of this colour by the `scale`
     * 
     * @param scale Value to scale the colour by.
     * 
     * @returns `ColourF` - Colour scaled.
     */
    ColourF operator*( float scale );

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


    // Arithmetic Operator Overloading

    /** 
     * @brief Returns the combination of this and `colour` and halves the total.
     * 
     * @attention Halves the value of the combination, due to the max component value being 255.
     * 
     * @param colour Colour to combine to this.
     * 
     * @returns `ColourI` Combination of the colours.
     */
    ColourI operator+( ColourI colour );

    /**
     * @brief Returns the scale of this colour by the `scale`
     * 
     * @param scale Value to scale the colour by.
     * 
     * @returns `ColourI` - Colour scaled.
     */
    ColourI operator*( float scale );
};
