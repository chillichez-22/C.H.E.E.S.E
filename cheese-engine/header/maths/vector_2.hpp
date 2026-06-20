#pragma once

// External
#include <cmath>

/**
 * @brief A vector of floats with 2 components: x, y.
 * 
 */
struct Vector2{

    float x;
    float y;
};


// Vector Basic


/**
 * @brief Returns the addition of vectorOne + vectorTwo.
 * 
 * @param vectorOne First vector to add.
 * @param vectorTwo Second vector to add.
 * 
 * @return New Vector2 of the added Vector2s.
 */
Vector2 add( Vector2& vectorOne, Vector2& vectorTwo );

/**
 * @brief Returns the subtraction of vectorTwo - vectorOne. 
 * 
 * @param vectorOne First vector to subtract.
 * @param vectorTwo Second vector to subtract.
 * 
 * @return New Vector2 of the subtracted Vector2s.
 */
Vector2 sub( Vector2& vectorOne, Vector2& vectorTwo );

/**
 * @brief Returns the multiplication of vectorOne * vectorTwo. 
 * 
 * @param vectorOne First vector to multiply.
 * @param vectorTwo Second vector to multiply.
 * 
 * @return New Vector2 of the divided Vector2s.
 */
Vector2 multiply( Vector2& vectorOne, Vector2& vectorTwo );

/**
 * @brief Returns the division of vectorTwo / vectorOne. 
 * 
 * @param vectorOne First vector to divide.
 * @param vectorTwo Second vector to divide.
 * 
 * @return New Vector2 of the divided Vector2s.
 */
Vector2 divide( Vector2& vectorOne, Vector2& vectorTwo );


// Vector Maths


/**
 * @brief Returns the magnitude of the inputted Vector2s.
 * 
 * @param vector Vector to find the magnitude.
 * 
 * @return Float of the magnitude of the Vector2s.
 */
float magnitude( Vector2& vector );

/**
 * @brief Returns the angle of the inputted Vector2 in degrees.
 * 
 * @attention The "cmath" library uses radians natively for all angles and
 *            functions; are you sure your using the correct method ? 
 *            angleRadians( ) returns the radian angle.
 * 
 * @param vector Vector to find inner angle.
 * 
 * @return Float of the Vector2's inner angle in degrees.
 */
float angleDegrees( Vector2& vector );

/**
 * @brief Returns the angle of the inputted Vector2 in radians.
 * 
 * @param vector Vector to find inner angle.
 * 
 * @return Float of the Vector2's inner angle in radians.
 */
float angleRadians( Vector2& vector );


/**
 * @brief Returns the dot product of the inputted Vector2s.
 * 
 * @param vectorOne First vector.
 * @param vectorTwo Second vector.
 * 
 * @return Float of the dot product of the Vector2s.
 */
float dot( Vector2& vectorOne, Vector2& vectorTwo );

