#pragma once

#include <cstdint>

#include "entity.hpp"

#include "vector_3.hpp"
#include "vector_4.hpp"
#include "view_volume.hpp"


/**
 * @brief Camera class, for seeing the world / scene
 * 
 * @attention 
 * If a scene has no camera, then the scene will be viewed from the world origin, with no rotation, perspective, object-ordering or clipping
 * 
 */
class Camera : public Entity{

private:

	Vector3 cameraDirection{ 0.f, 0.f, 1.f };     /**< Direction the camera is facing */

public:

    Transform3D transform;      /**< Transform to position and rotate the camera */

	Frustum cameraViewVolume;   /**< Viewing volume of the camera*/


public:

    /**
     * @brief Default constructor for the camera.
     * 
     * Creates a new camera class to view the scene, with default values:
     * 
     * - `transform` = default: ( 0, 0, 0 ) pos & rotation, ( 1, 1, 1 ) scale.
     * 
     * - `camDirection` = { 0.0, 0.0, 0.0 }.
     * 
     * - `fov` = 120.0.
     * 
     * - `renderDistance` = 100.0.
     * 
     * - `cameraViewVolume` = default: 0 left, right, bottom, top, near, far.
     * 
     * @returns `Camera` New camera with default values.
     */
    Camera();


    /**
     * @brief Creates a new camera class to view the scene.
     * 
     * @param camPos Position of the camera in world space.
     * @param aspectRatio Aspect ratio of the screen.
     * @param fieldOfView FOV of the camera.
     * @param renderDist Render distance of the camera.
     * 
     * @returns `Camera` New camera for the scene.
     */
    Camera( 
        Vector3 camPos,
        float aspectRatio,
        float fieldOfView, 
        float renderDist 
    );

    // Getters

    /**
     * @brief Getter for the aspectRatio.
     * 
     * @details Abstracts the `cameraViewVolumes`'s aspect ratio value.
     * 
     * @returns `float` Aspect ratio of the camera.
     */
    float getAspectRatio();

    /**
     * @brief Getter for the fov.
     * 
     * @details Abstracts the `cameraViewVolumes`'s fov value.
     * 
     * @returns `float` Fov of the camera.
     */
    float getFov();

    /**
     * @brief Gets the render distance.
     * 
     * @details Abstracts the `cameraViewVolumes`'s far value.
     * 
     * @returns `float` Camera's render distance.
     */
    float getRenderDistance();


    // Setters

    /**
     * @brief Sets a new aspect ratio for the camera. 
     * 
     * @details Abstracts the `cameraViewVolumes`'s setter for the aspect ratio.
     */
    void setAspectRatio( float newAspectRatio );

    /**
     * @brief Sets a new fov for the camera. 
     * 
     * @details Abstracts the `cameraViewVolumes`'s setter for the fov. 
     */
    void setFov( float newFov );

    /** 
     * @brief Sets a new render distance for the camera.
     * 
     * @details Abstracts the `cameraViewVolumes`'s setter for the far.
    */
    void setRenderDistance( float newDistance );

};
