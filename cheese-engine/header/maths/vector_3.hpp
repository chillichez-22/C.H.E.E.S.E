#pragma once

// External
#include <cmath>

/**
 * @brief A vector of floats with 3 components: x, y, z.
 * 
 */
struct Vector3{

    float x;
    float y;
    float z;
    
    /**
     * @brief Default Constructor
     */
    Vector3();

    /**
     * @brief Constructor for a new Vector3
     * 
     * @param newX Float for the x component
     * @param newY Float for the y component
     * @param newZ Float for the z component
     * 
     * @return `Vector3` new Vector3
     */
    Vector3( float newX, float newY, float newZ );
    
    
    // Comparison Operator Overloading

    /**
     * @brief Returns the comparison of this + another `Vector3`.
     * 
     * @param vector Other vector to compare.
     * 
     * @return Comparison of the two vectors.
     */
    bool operator==( Vector3& vector );

    /**
     * @brief Returns the not comparison of this + another `Vector3`.
     * 
     * @param vector Other vector to compare.
     * 
     * @return Comparison of the two vectors.
     */
    bool operator!=( Vector3& vector );


    // Basic Operator Overloading

    /**
     * @brief Returns the addition of this + another `Vector3`.
     * 
     * @param vector Other vector to add.
     * 
     * @return Addition of the two vectors.
     */
    Vector3 operator+( Vector3& vector );

    /**
     * @brief Returns the subtraction of this - another `Vector3`.
     * 
     * @param vector Other vector to sub.
     * 
     * @return Subtraction of the two vectors.
     */
    Vector3 operator-( Vector3& vector );

    /**
     * @brief Returns the multiplication of this - another `Vector3`.
     * 
     * @param vector Other vector to multiply.
     * 
     * @return Multiplication of the two vectors.
     */
    Vector3 operator*( Vector3& vector );

    /**
     * @brief Returns the division of this - another `Vector3`.
     * 
     * @param vector Other vector to divide.
     * 
     * @return Division of the two vectors.
     */
    Vector3 operator/( Vector3& vector );

    /**
     * @brief Returns the vector raised to the power of `scale`.
     * 
     * @param vector Other vector to add.
     * 
     * @return Vector raised by the `scale`.
     */
    Vector3 operator^( float& scale );


    // Assignment Operator Overloading

    /**
     * @brief Returns the addition of this + another `Vector3`.
     * 
     * @param vector Other vector to add.
     */
    void operator+=( Vector3& vector );

    /**
     * @brief Returns the subtraction of this - another `Vector3`.
     * 
     * @param vector Other vector to sub.
     */
    void operator-=( Vector3& vector );

    /**
     * @brief Returns the multiplication of this - another `Vector3`.
     * 
     * @param vector Other vector to multiply.
     */
    void operator*=( Vector3& vector );

    /**
     * @brief Returns the division of this - another `Vector3`.
     * 
     * @param vector Other vector to divide.
     */
    void operator/=( Vector3& vector );

    /**
     * @brief Returns the vector raised to the power of `scale`.
     * 
     * @param vector Other vector to add.
     */
    void operator^=( float& scale );



    // Vector Basic

    /**
     * @brief Returns the addition of vectorOne + vectorTwo.
     * 
     * @param vectorOne First vector to add.
     * @param vectorTwo Second vector to add.
     * 
     * @return New Vector3 of the added Vector3s.
     */
    Vector3 add( Vector3& vectorOne, Vector3& vectorTwo );

    /**
     * @brief Returns the subtraction of vectorTwo - vectorOne.
     * 
     * @param vectorOne First vector to subtract.
     * @param vectorTwo Second vector to subtract.
     * 
     * @return New Vector3 of the subtracted Vector3s.
     */
    Vector3 sub( Vector3& vectorOne, Vector3& vectorTwo );

    /**
     * @brief Returns the multiplication of vectorOne * vectorTwo. 
     * 
     * @param vectorOne First vector to multiply.
     * @param vectorTwo Second vector to multiply.
     * 
     * @return New Vector3 of the divided Vector3s.
     */
    Vector3 multiply( Vector3& vectorOne, Vector3& vectorTwo );

    /**
     * @brief Returns the division of vectorTwo / vectorOne. 
     * 
     * @param vectorOne First vector to divide.
     * @param vectorTwo Second vector to divide.
     * 
     * @return New Vector3 of the divided Vector3s.
     */
    Vector3 divide( Vector3& vectorOne, Vector3& vectorTwo );


    // Vector math

    /**
     * @brief Returns the magnitude of the inputted Vector3s.
     * 
     * @param vector Vector to find the magnitude.
     * 
     * @return Float of the magnitude of the Vector3s.
     */
    float magnitude( Vector3& vector );

    /**
     * @brief Returns the inputted Vector3 scaled by the inputted factor.
     * 
     * @attention This does NOT scale the vector TO the inputted factor, it simply
     *            multiplies the vector BY the scale. scaleTo( ) scales the vector to 
     *            the inputted factor.
     * 
     * @param vector Vector to be scaled.
     * @param factor Factor to scale the Vector3.
     * 
     * @return Vector3 of the vector scaled.
     */
    Vector3 scale( Vector3& vector, float factor );

    /**
     * @brief Returns the inputted Vector3 scaled to the inputted factor.
     * 
     * @attention This scale the vector TO the inputted factor. 
     *            scale( ) scales the vector by the inputted factor.
     * 
     * @param vector Vector to be scaled.
     * @param factor Length to set the Vector3's magnitude.
     * 
     * @return Vector3 of the vector scaled to the factor.
     */
    Vector3 scaleTo( Vector3& vector, float factor );

    /**
     * @brief Returns the unit vector of the inputted Vector3.
     * 
     * @param vector Vector to calculate the unit vector.
     * 
     * @return Vector3 for the unit vector.
     */
    Vector3 unit( Vector3& vector );


    // Vector Rotations

    /**
     * @brief Returns the 3 inner angles of the inputted Vector3 in degrees.
     * 
     * @attention The `cmath` library uses radians natively for all angles and
     *            functions; are you sure your using the correct method ? 
     *            angleRadians( ) returns the radian angle.
     * 
     * @param vector Vector to find inner angle.
     * 
     * @return Vector3 representing the Vector3's 3 inner angles in degrees.
     */
    Vector3 angleDegrees( Vector3& vector );

    /**
     * @brief Returns the 3 inner angles of the inputted Vector3 in radians.
     * 
     * @param vector Vector to find inner angle.
     * 
     * @return Vector3 representing the Vector3's 3 inner angles in radians.
     */
    Vector3 angleRadians( Vector3& vector );
};

/**
 * @brief Returns the dot product of the inputted Vector3s.
 * 
 * @param vectorOne First vector.
 * @param vectorTwo Second vector.
 * 
 * @return Float of the dot product of the Vector3s.
 */
float dot( Vector3& vectorOne, Vector3& vectorTwo );


