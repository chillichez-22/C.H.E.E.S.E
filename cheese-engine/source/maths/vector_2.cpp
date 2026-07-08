#include "vector_2.hpp"

// Vector Basic

Vector2 add( Vector2& vectorOne, Vector2& vectorTwo ){

    Vector2 newVector2 = { 
        vectorOne.x + vectorTwo.x, 
        vectorOne.y + vectorTwo.y 
    };
    return newVector2;
}

Vector2 sub( Vector2& vectorOne, Vector2& vectorTwo ){

    // VectorTwo and VectorOne are in the reversed order, since thats the most commonly used
    // way for a vector subtraction
    Vector2 newVector2 = { 
        vectorTwo.x - vectorOne.x, 
        vectorTwo.y - vectorOne.y 
    };
    return newVector2;
}

Vector2 multiply( Vector2& vectorOne, Vector2& vectorTwo ){

    Vector2 newVector2 = { 
        vectorOne.x * vectorTwo.x, 
        vectorOne.y * vectorTwo.y 
    };
    return newVector2;
}

Vector2 divide( Vector2& vectorOne, Vector2& vectorTwo ){

    // VectorTwo and VectorOne are in the reversed order, since thats the most commonly used
    // way for a vector division
    Vector2 newVector2 = { 
        vectorTwo.x / vectorOne.x, 
        vectorTwo.y / vectorOne.y 
    };
    return newVector2;
}


// Vector Math

float magnitude( Vector2& vector ){

    return sqrtf( 
        vector.x * vector.x + 
        vector.y * vector.y 
    );
}

Vector2 scale( Vector2& vector, float factor ){

    Vector2 newVector = {
        vector.x * factor,
        vector.y * factor
    };

    return newVector;
}

Vector2 scaleTo( Vector2& vector, float factor ){

    Vector2 unitVector = unit( vector );

    return scale( unitVector, factor );
}

Vector2 unit( Vector2& vector ){

    Vector2 newVector = {
        vector.x / magnitude( vector ),
        vector.y / magnitude( vector )
    };
    
    return newVector;
}

float dot( Vector2& vectorOne, Vector2& vectorTwo ){

    return ( 
        vectorOne.x * vectorTwo.x +
        vectorOne.y * vectorTwo.y
    );
}


// Vector Rotations

float angleDegrees( Vector2& vector ){

    // cmath uses radians natively
    return atan2f( vector.y, vector.x ) * ( 180 / M_PI );
}

float angleRadians( Vector2& vector ){

    return atan2f( vector.y, vector.x );
}
