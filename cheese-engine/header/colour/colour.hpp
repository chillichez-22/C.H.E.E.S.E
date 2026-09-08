#pragma once


struct Colour{

    virtual ~Colour() = default;
};


/**
 * @brief Colour variable with 4 floats of: r, g, b, a.
 */
struct ColourF : Colour
{
    ColourF( float r, float g, float b, float a = 1.0f );

    float r;
    float g;
    float b;
    float a;
};

/**
 * @brief Colour variable with 4 ints of: r, g, b, a.
 */
struct ColourI : Colour
{
    ColourI( int r, int g, int b, int a = 255 );

    int r;
    int g;
    int b;
    int a;
};
