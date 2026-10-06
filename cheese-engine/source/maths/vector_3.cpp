#include "vector_3.hpp"


Vector3::Vector3(){};

Vector3::Vector3( float newX, float newY, float newZ ){

    x = newX;
    y = newY;
    z = newZ;
};


// Comparison Operator Overloading

bool Vector3::operator==( Vector3& vector ){

    if ( x == vector.x && y == vector.y && z == vector.z ){
        
        return true;
    };

    return false;
}

bool Vector3::operator!=( Vector3& vector ){

    if ( x != vector.x && y != vector.y && z != vector.z ){
        
        return true;
    };

    return false;
}


// Basic Operator Overloading

Vector3 Vector3::operator+( Vector3& vector ){

    return Vector3(
        x + vector.x,
        y + vector.y,
        z + vector.z
    );
};

Vector3 Vector3::operator-( Vector3& vector ){

    return Vector3(
        x - vector.x,
        y - vector.y,
        z - vector.z
    );
};

Vector3 Vector3::operator*( Vector3& vector ){

    return Vector3(
        x * vector.x,
        y * vector.y,
        z * vector.z
    );
};

Vector3 Vector3::operator/( Vector3& vector ){

    return Vector3(
        x / vector.x,
        y / vector.y,
        z / vector.z
    );
};

Vector3 Vector3::operator^( float& scale ){

    return Vector3(
        powf(x, scale),
        powf(y, scale),
        powf(z, scale)
    );
};


// Assignment Operator Overloading

void Vector3::operator+=( Vector3& vector ){

    x += vector.x;
    y += vector.y;
    z += vector.z;
};

void Vector3::operator-=( Vector3& vector ){

    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
};

void Vector3::operator*=( Vector3& vector ){

    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
};

void Vector3::operator/=( Vector3& vector ){

    x /= vector.x;
    y /= vector.y;
    z /= vector.z;
};

void Vector3::operator^=( float& scale ){

    x = powf( x, scale );
    y = powf( y, scale );
    z = powf( z, scale );
};


// Vector Basic

Vector3 Vector3::add( Vector3& otherVector ){

    Vector3 newVector3 = { 
        x + otherVector.x, 
        y + otherVector.y, 
        z + otherVector.z  
    };
    return newVector3;
}

Vector3 Vector3::sub( Vector3& otherVector ){

    // OtherVector and this vector are in the reversed order, since that's the most commonly used
    // way for a vector subtraction
    Vector3 newVector3 = { 
        otherVector.x - x, 
        otherVector.y - y,
        otherVector.z - z  
    };
    return newVector3;
}

Vector3 Vector3::multiply( Vector3& otherVector ){
    
    Vector3 newVector3 = { 
        x * otherVector.x, 
        y * otherVector.y,
        z * otherVector.z  
    };
    return newVector3;
}

Vector3 Vector3::divide( Vector3& otherVector ){

    // OtherVector and this vector are in the reversed order, since that's the most commonly used
    // way for a vector division
    Vector3 newVector3 = { 
        otherVector.x / x, 
        otherVector.y / y,
        otherVector.z / z  
    };
    return newVector3;
}


// Vector Math

float Vector3::magnitude(){

    return sqrtf(
        x * x + 
        y * y +
        z * z 
    );
}

Vector3 Vector3::scale( float factor ){

    Vector3 newVector = {
        x * factor,
        y * factor,
        z * factor
    };

    return newVector;
}

Vector3 Vector3::scaleTo( float factor ){

    Vector3 unitVector = unit();

    return scale( factor );
}

Vector3 Vector3::unit(){

    Vector3 newVector = {
        x / magnitude(),
        y / magnitude(),
        z / magnitude()
    };
    
    return newVector;
}


// Vector Rotations

Vector3 Vector3::angleDegrees(){

    Vector3 radians = angleRadians();
    return radians.scale( (180 / M_PI) );

}

Vector3 Vector3::angleRadians(){

    float vectorMagnitude = magnitude();

    float alpha = acosf( x / vectorMagnitude );
    float beta = acosf( y / vectorMagnitude );
    float gamma = acosf( z / vectorMagnitude );

    Vector3 angleVector = {
        alpha,
        beta,
        gamma
    };

    return angleVector;
}


float dot( Vector3& vectorOne, Vector3& vectorTwo ){
    
    return ( 
        vectorOne.x * vectorTwo.x +
        vectorOne.y * vectorTwo.y +
        vectorOne.z * vectorTwo.z
    );
}

Vector3 cross( Vector3& vectorOne, Vector3& vectorTwo ){

    return Vector3( 
        vectorOne.y * vectorTwo.z - vectorOne.z * vectorTwo.y,
        vectorOne.z * vectorTwo.x - vectorOne.x * vectorTwo.z,
        vectorOne.x * vectorTwo.y - vectorOne.y * vectorTwo.x
    );
}