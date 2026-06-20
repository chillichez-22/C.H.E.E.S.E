#pragma once

// External
#include <cmath>

/**
 * @brief A vector of floats with 4 components: x, y, z, w.
 * 
 */
struct Vector4{

    float x;
    float y;
    float z;
    float w;
};


// Vector Basic


/**
 * @brief Returns the addition of vectorOne + vectorTwo.
 * 
 * @param vectorOne First vector to add.
 * @param vectorTwo Second vector to add.
 * 
 * @return New Vector4 of the added Vector4s.
 */
Vector4 add( Vector4& vectorOne, Vector4& vectorTwo );

/**
 * @brief Returns the subtraction of vectorTwo - vectorOne. 
 * 
 * @param vectorOne First vector to subtract.
 * @param vectorTwo Second vector to subtract.
 * 
 * @return New Vector4 of the subtracted Vector4s.
 */
Vector4 sub( Vector4& vectorOne, Vector4& vectorTwo );

/**
 * @brief Returns the multiplication of vectorOne * vectorTwo. 
 * 
 * @param vectorOne First vector to multiply.
 * @param vectorTwo Second vector to multiply.
 * 
 * @return New Vector4 of the divided Vector4s.
 */
Vector4 multiply( Vector4& vectorOne, Vector4& vectorTwo );

/**
 * @brief Returns the division of vectorTwo / vectorOne. 
 * 
 * @param vectorOne First vector to divide.
 * @param vectorTwo Second vector to divide.
 * 
 * @return New Vector4 of the divided Vector4s.
 */
Vector4 divide( Vector4& vectorOne, Vector4& vectorTwo );


// Vector math


/**
 * @brief Returns the magnitude of the inputted Vector4s.
 * 
 * @param vector Vector to find the magnitude.
 * 
 * @return Float of the magnitude of the Vector4s.
 */
float magnitude( Vector4& vector );

/**
 * @brief Returns the dot product of the inputted Vector4s.
 * 
 * @param vectorOne First vector.
 * @param vectorTwo Second vector.
 * 
 * @return Float of the dot product of the Vector4s.
 */
float dot( Vector4& vectorOne, Vector4& vectorTwo );
