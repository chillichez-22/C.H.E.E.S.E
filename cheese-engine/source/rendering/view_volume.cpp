
#include "rendering/view_volume.hpp"


/* Viewing Volume*/

// Constructor

ViewVolume::ViewVolume( 
    float aspectRatioVal, 
    float nearDist, 
    float farDist,
    float heightVal
):
    m_aspectRatio( aspectRatioVal ),
    m_near( nearDist ),
    m_far( farDist ),
    m_height( heightVal )
{

}


// Getter

float& ViewVolume::getAspectRatio(){

    return m_aspectRatio;
};


// Geometry

float ViewVolume::height(){

    return m_height;
};

float ViewVolume::width(){

    return ( height() * m_aspectRatio );
};



float ViewVolume::l(){

    return -( width() / 2 );
};

float ViewVolume::r(){

    return ( width() / 2 );
};

float ViewVolume::t(){

    return -( height() / 2 );
};

float ViewVolume::b(){

    return ( height() / 2 );
};

float& ViewVolume::n(){

    return m_near;
};

float& ViewVolume::f(){

    return m_far;
};


float ViewVolume::scaleToFar( float side ){

    return side * ( m_far / m_near ); 
}


// Setter

void ViewVolume::setAspectRatio( float newAspectRatio ){

    m_aspectRatio = newAspectRatio;
};

void ViewVolume::setNear( float nearDist ){ 

    m_near = nearDist;
};

void ViewVolume::setFar( float farDist ){ 

    m_far = farDist;
};


void ViewVolume::setWidth( float widthVal ){
    
    m_aspectRatio = widthVal / height();
}

void ViewVolume::setHeight( float heightVal ){

    m_height = heightVal;
}



/* Frustum */

// Constructor

Frustum::Frustum( 
    float aspectRatioVal, 
    float fieldOfView, 
    float nearDist, 
    float farDist

): ViewVolume(
    aspectRatioVal, 
    nearDist, 
    farDist 
){
    m_fov = fieldOfView;
};


// Conversions

Frustum::Frustum(
    ViewVolume viewVol,
    float fov

): ViewVolume( 
    viewVol 
){
    m_fov = fov;
}


// Frustum Getters

float& Frustum::getFov(){

    return m_fov;
};


// Frustum Geometry


float Frustum::height(){

    return ( 2 * tanf( m_fov / 2 ) * m_near );
};


// Frustum Setters

void Frustum::setFov( float fieldOfView ){ 
    
    m_fov = fieldOfView;
};

void Frustum::setHeight( float heightVal ){

    /* Conversion:
    
    H = 2 * tan( fov / 2 ) * near 
    
    
    H / (2 * near) = tan( fov / 2)
    arctan( H / (2*near) ) = fov / 2
    2*arctan( h / (2*near) ) = fov
    */

    m_fov = 2 * atan( heightVal / ( 2 * n() ) );    

}