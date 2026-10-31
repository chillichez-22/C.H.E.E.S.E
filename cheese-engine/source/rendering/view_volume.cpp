#include "view_volume.hpp"


/* Frustum */


// Frustum Getters

float& Frustum::getAspectRatio(){

    return aspectRatio;
};

float& Frustum::getFov(){

    return fov;
};


float* Frustum::getAspectRatioPointer(){

    return &aspectRatio;
};


float* Frustum::getFovPointer(){

    return &fov;
};


// Frustum Geometry

float Frustum::width(){

    return ( height() * aspectRatio );
};

float Frustum::height(){

    return ( 2 * tanf( fov / 2 ) * near );
};


// Frustum Points/Sides

float Frustum::l(){

    return -( width() / 2 );
};

float Frustum::r(){

    return ( width() / 2 );
};

float Frustum::t(){

    return -( height() / 2 );
};

float Frustum::b(){

    return ( height() / 2 );
};

float Frustum::n(){

    return near;
};

float Frustum::f(){

    return far;
};


float Frustum::scaleToFar( float side ){

    return side * ( far / near ); 
}


// Frustum Setters

void Frustum::setAspectRatio( float newAspectRatio ){
    aspectRatio = newAspectRatio;
};

void Frustum::setFov( float fieldOfView ){ 
    fov = fieldOfView;
};

void Frustum::setNear( float nearDist ){ 
    near = nearDist;
};

void Frustum::setFar( float farDist ){ 
    far = farDist;
};