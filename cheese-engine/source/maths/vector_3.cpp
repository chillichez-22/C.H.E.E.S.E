#include "vector_3.hpp"

// Vector Basic

Vector3 add( Vector3& vectorOne, Vector3& vectorTwo ){

    Vector3 newVector3 = { 
                            vectorOne.x + vectorTwo.x, 
                            vectorOne.y + vectorTwo.y, 
                            vectorOne.z + vectorTwo.z  
                        };
    return newVector3;
}

Vector3 sub( Vector3& vectorOne, Vector3& vectorTwo ){

    // VectorTwo and VectorOne are in the reversed order, since thats the most commonly used
    // way for a vector subtraction
    Vector3 newVector3 = { 
                            vectorTwo.x - vectorOne.x, 
                            vectorTwo.y - vectorOne.y,
                            vectorTwo.z - vectorOne.z  
                        };
    return newVector3;
}

Vector3 multiply( Vector3& vectorOne, Vector3& vectorTwo ){
    
    Vector3 newVector3 = { 
                            vectorOne.x * vectorTwo.x, 
                            vectorOne.y * vectorTwo.y,
                            vectorOne.z * vectorTwo.z  
                        };
    return newVector3;
}

Vector3 divide( Vector3& vectorOne, Vector3& vectorTwo ){

    // VectorTwo and VectorOne are in the reversed order, since thats the most commonly used
    // way for a vector division
    Vector3 newVector3 = { 
                            vectorTwo.x / vectorOne.x, 
                            vectorTwo.y / vectorOne.y,
                            vectorTwo.z / vectorOne.z  
                        };
    return newVector3;
}


// Vector Math

float magnitude( Vector3& vector ){

    return sqrtf( 
                    vector.x * vector.x + 
                    vector.y * vector.y +
                    vector.z * vector.z 
                );
}

Vector3 scale( Vector3& vector, float factor ){

    Vector3 newVector = {

                            vector.x * factor,
                            vector.y * factor,
                            vector.z * factor
                        };

    return newVector;
}

Vector3 scaleTo( Vector3& vector, float factor ){

    Vector3 unitVector = unit( vector );

    return scale( unitVector, factor );
}

Vector3 unit( Vector3& vector ){

    Vector3 newVector = {

                            vector.x / magnitude( vector ),
                            vector.y / magnitude( vector ),
                            vector.z / magnitude( vector )
                        };
    
    return newVector;
}

float dot( Vector3& vectorOne, Vector3& vectorTwo ){
    
    return ( 
                vectorOne.x * vectorTwo.x +
                vectorOne.y * vectorTwo.y +
                vectorOne.z * vectorTwo.z
            );
}


// Vector Rotations

Vector3 angleDegrees( Vector3& vector ){

    Vector3 radians = angleRadians( vector );
    return scale( radians, (180 / M_PI) );

}

Vector3 angleRadians( Vector3& vector ){

    float vectorMagnitude = magnitude( vector );

    float alpha = acosf( vector.x / vectorMagnitude );
    float beta = acosf( vector.y / vectorMagnitude );
    float gamma = acosf( vector.z / vectorMagnitude );

    Vector3 angleVector = {
                            alpha,
                            beta,
                            gamma
                        };

    return angleVector;
}

