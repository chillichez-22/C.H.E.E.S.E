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

    /**
     * @brief Constructor for a new Vector2
     * 
     * @param x Float for the x component
     * @param y Float for the y component
     * 
     * @return `Vector2` new Vector2
     */
    Vector2( float x, float y );


    // Basic Operator Overloading

    /**
     * @brief Returns the addition of this + another `Vector2`.
     * 
     * @param vector Other vector to add.
     * 
     * @return Addition the two vectors.
     */
    Vector2 operator+( Vector2& vector );

    /**
     * @brief Returns the subtraction of this - another `Vector2`.
     * 
     * @param vector Other vector to sub.
     * 
     * @return Subtraction the two vectors.
     */
    Vector2 operator-( Vector2& vector );

    /**
     * @brief Returns the multiplication of this - another `Vector2`.
     * 
     * @param vector Other vector to multiply.
     * 
     * @return Multiplication of the two vectors.
     */
    Vector2 operator*( Vector2& vector );

    /**
     * @brief Returns the division of this - another `Vector2`.
     * 
     * @param vector Other vector to divide.
     * 
     * @return Division of the two vectors.
     */
    Vector2 operator/( Vector2& vector );

    /**
     * @brief Returns the vector raised to the power of `scale`.
     * 
     * @param vector Other vector to add.
     * 
     * @return Vector raised by the `scale`.
     */
    Vector2 operator^( float& scale );


    // Assignment Operator Overloading

    /**
     * @brief Returns the addition of this + another `Vector2`.
     * 
     * @param vector Other vector to add.
     */
    void operator+=( Vector2& vector );

    /**
     * @brief Returns the subtraction of this - another `Vector2`.
     * 
     * @param vector Other vector to sub.
     */
    void operator-=( Vector2& vector );

    /**
     * @brief Returns the multiplication of this - another `Vector2`.
     * 
     * @param vector Other vector to multiply.
     */
    void operator*=( Vector2& vector );

    /**
     * @brief Returns the division of this - another `Vector2`.
     * 
     * @param vector Other vector to divide.
     */
    void operator/=( Vector2& vector );

    /**
     * @brief Returns the vector raised to the power of `scale`.
     * 
     * @param vector Other vector to add.
     */
    void operator^=( float& scale );


    // Vector Maths

    /**
     * @brief Returns the magnitude of this Vector2s.
     * 
     * @return Float of the magnitude of the Vector2s.
     */
    float magnitude();

    /**
     * @brief Normalises this vector to a unit vector.
     */
    void normalise();

    /**
     * @brief Returns the unit vector of this Vector2.
     *
     * @return Vector2 for the unit vector.
     */
    Vector2 normalised();

    /**
     * @brief Scales this Vector2 by the inputted factor.
     * 
     * @attention This does NOT scale the vector TO the inputted factor, it simply
     *            multiplies the vector BY the scale. scaleTo( ) scales the vector to 
     *            the inputted factor.
     * 
     * @param factor Factor to scale the Vector2.
     */
    void scale( float factor );

    /**
     * @brief Scales this Vector2 scaled to the inputted factor.
     * 
     * @attention This scales the vector TO the inputted factor.
     *            scale( ) scales the vector by the inputted factor.
     * 
     * @param factor Length to set the Vector2's magnitude.
     */
    void scaleTo( float factor );

    /**
     * @brief Returns this Vector2 scaled by the inputted factor.
     * 
     * @attention This does NOT scale the vector TO the inputted factor, it simply
     *            multiplies the vector BY the scale. scaleTo( ) scales the vector 
     *            to the inputted factor.
     * 
     * @param factor Factor to scale the Vector2.
     * 
     * @return Vector2 scaled by the factor.
     */
    Vector2 scaled( float factor );

    /**
     * @brief Returns this Vector2 scaled to the inputted factor.
     * 
     * @attention This scales the vector TO the inputted factor.
     *            scale( ) scales the vector by the inputted factor.
     * 
     * @param factor Length to set the Vector2's magnitude.
     * 
     * @return Vector2 scaled to the factor.
     */
    Vector2 scaledTo( float factor );


    // Vector Rotations

    /**
     * @brief Returns the angle of this Vector2 in degrees.
     * 
     * @attention The `cmath` library uses radians natively for all angles and
     *            functions; are you sure your using the correct method? 
     *            `angleRadians( )` returns the radian angle.
     * 
     * @return Float of the Vector2's inner angle in degrees.
     */
    float angleDegrees();

    /**
     * @brief Returns the angle of this Vector2 in radians.
     * 
     * @return Float of the Vector2's inner angle in radians.
     */
    float angleRadians();

};


/**
 * @brief Returns the dot product of the inputted Vector2s.
 * 
 * @param vectorOne First vector.
 * @param vectorTwo Second vector.
 * 
 * @return Float of the dot product of the Vector2s.
 */
float dot( Vector2& vectorOne, Vector2& vectorTwo );
