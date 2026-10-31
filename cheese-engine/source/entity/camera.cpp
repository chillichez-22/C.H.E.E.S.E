#include "camera.hpp"

Camera::Camera(){};

Camera::Camera( 
    Vector3 camPos,
    float aspectRatio,
    float fieldOfView, 
    float renderDist 
){

    transform.setPos( camPos );

    cameraViewVolume = Frustum( aspectRatio, fieldOfView, 0.1f, renderDist + 0.1f );

};

// Getters

float Camera::getAspectRatio(){

    return cameraViewVolume.getAspectRatio();
};


float Camera::getFov(){

    return cameraViewVolume.getFov();
};


float Camera::getRenderDistance(){

    return cameraViewVolume.f();
};


// Setters

void Camera::setAspectRatio( float newAspectRatio ){

    cameraViewVolume.setAspectRatio( newAspectRatio );
};


void Camera::setFov( float newFov ){

    cameraViewVolume.setFov( newFov );
};


void Camera::setRenderDistance( float newDistance ){

    cameraViewVolume.setFar( newDistance );
};


