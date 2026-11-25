#include "entity/camera.hpp"

Camera::Camera(){};

Camera::Camera( 
    Vector3 camPos,
    float aspectRatio,
    float fieldOfView, 
    float renderDist 
){

    m_transform.setPos( camPos );

    m_cameraViewVolume = Frustum( aspectRatio, fieldOfView, 0.1f, renderDist + 0.1f );

};

// Getters

float& Camera::getAspectRatio(){

    return m_cameraViewVolume.getAspectRatio();
};


float& Camera::getFov(){

    return m_cameraViewVolume.getFov();
};


float& Camera::getRenderDistance(){

    return m_cameraViewVolume.f();
};


Vector3& Camera::getFront(){ 
    
    return  m_front; 
};

Vector3& Camera::getUp(){ 
    
    return  m_up; 
};

Vector3& Camera::getRight(){ 
    
    return  m_right; 
};


// Setters

void Camera::setAspectRatio( float newAspectRatio ){

    m_cameraViewVolume.setAspectRatio( newAspectRatio );
};


void Camera::setFov( float newFov ){

    m_cameraViewVolume.setFov( newFov );
};


void Camera::setRenderDistance( float newDistance ){

    m_cameraViewVolume.setFar( newDistance );
};


