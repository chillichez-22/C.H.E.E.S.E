#include "vector_4.hpp"

// Vector Basic

Vector4 add( Vector4& vectorOne, Vector4& vectorTwo ){

    Vector4 newVector4 = { 
                            vectorOne.x + vectorTwo.x, 
                            vectorOne.y + vectorTwo.y, 
                            vectorOne.z + vectorTwo.z,
                            vectorOne.w + vectorTwo.w    
                        };
    return newVector4;
}

Vector4 sub( Vector4& vectorOne, Vector4& vectorTwo ){

    // VectorTwo and VectorOne are in the reversed order, since thats the most commonly used
    // way for a vector subtraction
    Vector4 newVector4 = { 
                            vectorTwo.x - vectorOne.x, 
                            vectorTwo.y - vectorOne.y,
                            vectorTwo.z - vectorOne.z,
                            vectorTwo.w - vectorOne.w    
                        };
    return newVector4;
}

Vector4 multiply( Vector4& vectorOne, Vector4& vectorTwo ){

    Vector4 newVector4 = { 
                            vectorOne.x * vectorTwo.x, 
                            vectorOne.y * vectorTwo.y,
                            vectorOne.z * vectorTwo.z,
                            vectorOne.w * vectorTwo.w      
                        };
    return newVector4;
}

Vector4 divide( Vector4& vectorOne, Vector4& vectorTwo ){

    // VectorTwo and VectorOne are in the reversed order, since thats the most commonly used
    // way for a vector division
    Vector4 newVector4 = { 
                            vectorTwo.x / vectorOne.x, 
                            vectorTwo.y / vectorOne.y,
                            vectorTwo.z / vectorOne.z,
                            vectorTwo.w / vectorOne.w    
                        };
    return newVector4;
}


// Vector Math

float magnitude( Vector4& vector ){

    return sqrtf( 
                    vector.x * vector.x + 
                    vector.y * vector.y +
                    vector.z * vector.z +
                    vector.w * vector.w
                );
}

float dot( Vector4& vectorOne, Vector4& vectorTwo ){

    return ( 
                vectorOne.x * vectorTwo.x +
                vectorOne.y * vectorTwo.y +
                vectorOne.z * vectorTwo.z +
                vectorOne.w * vectorTwo.w
            );
}

