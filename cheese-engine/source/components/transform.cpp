#include "transform.hpp"


/* Getters */


// Position

Vector3 Transform3D::getPos() const{

    return Vector3(  
        float( positionList[0] ),
        float( positionList[1] ),
        float( positionList[2] )
    );
};

float Transform3D::getPosX() const{

    return float( positionList[0] ); 
};

float Transform3D::getPosY() const{

    return float( positionList[1] );
};

float Transform3D::getPosZ() const{

    return float( positionList[2] ); 
};


// Rotation

Vector3 Transform3D::getRotation() const{

    return Vector3(  
        float( rotationList[0] ),
        float( rotationList[1] ),
        float( rotationList[2] )
    );
};

float Transform3D::getRotationX() const{

    return float( rotationList[0] ); 
};

float Transform3D::getRotationY() const{

    return float( rotationList[1] ); 
};

float Transform3D::getRotationZ() const{

    return float( rotationList[2] ); 
};


// Scale

Vector3 Transform3D::getScale() const{

    return Vector3(  
        float( scaleList[0] ),
        float( scaleList[1] ),
        float( scaleList[2] )
    );
};

float Transform3D::getScaleX() const{

    return float( scaleList[0] ); 
};

float Transform3D::getScaleY() const{

    return float( scaleList[1] ); 
};

float Transform3D::getScaleZ() const{

    return float( scaleList[2] ); 
};



/* Setters */


// Position

void Transform3D::setPos( Vector3 positionVector){

    positionList[0] = std::float64_t( positionVector.x );
    positionList[1] = std::float64_t( positionVector.y );
    positionList[2] = std::float64_t( positionVector.z );
};

void Transform3D::setPosX( float& x){

    positionList[0] = std::float64_t( x );
};

void Transform3D::setPosY( float& y){

    positionList[1] = std::float64_t( y );
};

void Transform3D::setPosZ( float& z){

    positionList[2] = std::float64_t( z );
};


// Rotate

void Transform3D::setRotate( Vector3 rotationVector){

    rotationList[0] = std::float64_t( rotationVector.x );
    rotationList[1] = std::float64_t( rotationVector.y );
    rotationList[2] = std::float64_t( rotationVector.z );
};

void Transform3D::setRotateX( float& degrees){

    rotationList[0] = std::float64_t( degrees );
};


void Transform3D::setRotateY( float& degrees){

    rotationList[1] = std::float64_t( degrees );
};

void Transform3D::setRotateZ( float& degrees){

    rotationList[2] = std::float64_t( degrees );
};


// Scale

void Transform3D::setScale( Vector3 scaleVector){

    scaleList[0] = std::float32_t( scaleVector.x );
    scaleList[1] = std::float32_t( scaleVector.y );
    scaleList[2] = std::float32_t( scaleVector.z );
};

void Transform3D::setScaleX( float& x){

    scaleList[0] = std::float32_t( x );
};

void Transform3D::setScaleY( float& y){

    scaleList[1] = std::float32_t( y );
};

void Transform3D::setScaleZ( float& z){

    scaleList[2] = std::float32_t( z );
};

