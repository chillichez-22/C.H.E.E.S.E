#pragma once
#include "math.hpp"


bool areVectorsEqual( Vector2 vectorOne, Vector2 vectorTwo );
bool areVectorsEqual( Vector3 vectorOne, Vector3 vectorTwo );
bool areVectorsEqual( Vector4 vectorOne, Vector4 vectorTwo );


// Vector2 

/**
 * @brief Tests the addition of two Vector2s
 * 
 * @return If the test was successful
 */
bool testVector2Adding();

/**
 * @brief Tests the subtraction of two Vector2s
 * 
 * @return If the test was successful
 */
bool testVector2Subbing();

/**
 * @brief Tests the multiplication of two Vector2s
 * 
 * @return If the test was successful
 */
bool testVector2Multiplying();

/**
 * @brief Tests the division of two Vector2s
 * 
 * @return If the test was successful
 */
bool testVector2Dividing();
