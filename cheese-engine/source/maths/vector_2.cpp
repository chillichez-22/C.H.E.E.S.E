#include "vector_2.hpp"


Vector2::Vector2( float x, float y ){
    x = x;
    y = y;
};

// Basic Operator Overloading

Vector2 Vector2::operator+( Vector2& vector ){

    return Vector2(
        x + vector.x,
        y + vector.y
    );
};

Vector2 Vector2::operator-( Vector2& vector ){

    return Vector2(
        x - vector.x,
        y - vector.y
    );
};

Vector2 Vector2::operator*( Vector2& vector ){

    return Vector2(
        x * vector.x,
        y * vector.y
    );
};

Vector2 Vector2::operator/( Vector2& vector ){

    return Vector2(
        x / vector.x,
        y / vector.y
    );
};

Vector2 Vector2::operator^( float& scale ){

    return Vector2(
        powf(x, scale),
        powf(y, scale)
    );
};


// Assignment Operator Overloading

void Vector2::operator+=( Vector2& vector ){

    x += vector.x;
    y += vector.y;
};

void Vector2::operator-=( Vector2& vector ){

    x -= vector.x;
    y -= vector.y;
};

void Vector2::operator*=( Vector2& vector ){

    x *= vector.x;
    y *= vector.y;
};

void Vector2::operator/=( Vector2& vector ){

    x /= vector.x;
    y /= vector.y;
};

void Vector2::operator^=( float& scale ){

    x = powf( x, scale );
    y = powf( y, scale );
};


// Vector Maths

float Vector2::magnitude(  ){

    return sqrtf( 
        x * x + 
        y * y 
    );
}


void Vector2::normalise(){

    x /= magnitude();
    y /= magnitude();
}

Vector2 Vector2::normalised(){

    Vector2 newVector = Vector2(
        x / magnitude(),
        y / magnitude()
    );
    
    return newVector;
}


void Vector2::scale( float factor ){

    x *= factor;
    y *= factor;
}

void Vector2::scaleTo( float factor ){

    normalise();
    scale( factor );
}

Vector2 Vector2::scaled( float factor ){

    Vector2 newVector = Vector2(
        x * factor,
        y * factor
    );

    return newVector;
}

Vector2 Vector2::scaledTo( float factor ){

    Vector2 unitVector = normalised();

    return unitVector.scaled( factor );
}


// Vector Rotations

float Vector2::angleDegrees(){

    // cmath uses radians natively
    return atan2f( y, x ) * ( 180 / M_PI );
}

float Vector2::angleRadians(){

    return atan2f( y, x );
}


// Vector Math

float dot( Vector2& vectorOne, Vector2& vectorTwo ){

    return ( 
        vectorOne.x * vectorTwo.x +
        vectorOne.y * vectorTwo.y
    );
}


