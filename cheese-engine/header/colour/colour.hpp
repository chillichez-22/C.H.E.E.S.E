#pragma once


struct Colour{

    virtual ~Colour() = default;
};


/**
 * @brief Colour variable with 4 floats of: r, g, b, a.
 */
struct ColourF : Colour
{
    ColourF( float r, float g, float b, float a );

    float r = 0.f;
    float g = 0.f;
    float b = 0.f;
    float a = 0.f;
};

/**
 * @brief Colour variable with 4 ints of: r, g, b, a.
 */
struct ColourI : Colour
{
    ColourI( int r, int g, int b, int a );

    int r = 0;
    int g = 0;
    int b = 0;
    int a = 0;
};
