#include "vector_test.hpp"

#include <iostream>
#include <SDL3/SDL.h>


bool areVectorsEqual( Vector2 vectorOne, Vector2 vectorTwo ){

    if ( vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y ) return true;

    else return false;
}

// Vector 2 Testing

bool testVector2Adding(){

    Vector2 vectorOne = { 5, 6 }; 
    Vector2 vectorTwo = { 3, 4 }; 

    Vector2 resultVector = add( vectorOne, vectorTwo );
    Vector2 expectedVector = { 8, 10 };

    return areVectorsEqual( resultVector, expectedVector );
}

bool testVector2Subbing(){

    Vector2 vectorOne = { 20, 17 }; 
    Vector2 vectorTwo = { 10, 30 }; 

    Vector2 resultVector = sub( vectorOne, vectorTwo );
    Vector2 expectedVector = { -10, 13 };

    return areVectorsEqual( resultVector, expectedVector );
}

bool testVector2Multiplying(){

    Vector2 vectorOne = { 4, 6 }; 
    Vector2 vectorTwo = { 5, 7 }; 

    Vector2 resultVector = multiply( vectorOne, vectorTwo );
    Vector2 expectedVector = { 20, 42 };

    return areVectorsEqual( resultVector, expectedVector );
}

bool testVector2Dividing(){

    Vector2 vectorOne = { 5, 6 }; 
    Vector2 vectorTwo = { 20, 30 }; 

    Vector2 resultVector = divide( vectorOne, vectorTwo );
    Vector2 expectedVector = { 4, 5 };

    return areVectorsEqual( resultVector, expectedVector );
}