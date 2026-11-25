#pragma once

#include <cstdint>

#include "entity/entity.hpp"

#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"
#include "rendering/view_volume.hpp"


/**
 * @brief Camera class, for seeing the world / scene
 * 
 * @attention 
 * If a scene has no camera, then the scene will be viewed from the world origin, with no rotation, perspective, object-ordering or clipping
 * 
 */
class Camera : public Entity{

private:

    Transform3D m_transform;  /**< Transform to position and rotate the camera */ 

    Frustum m_cameraViewVolume;   /**< Viewing volume of the camera*/


    float m_zoom;   /*< Zoom of the camera. */

    Vector3 m_front;    /*< 3D Vector pointing in the front direction. */
	Vector3 m_right;    /*< 3D Vector pointing in the right direction. */
	Vector3 m_up;       /*< 3D Vector pointing in the up direction. */


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
     * @brief Getter for the camera's transform.
     * 
     * @returns `Transform3D` - Transform for the camera. Scale is not used.
     */
    Transform3D& getTransform();

    /**
     * @brief Getter for the camera's view volume.
     * 
     * @returns `Frustum` - View volume for the camera.
     */
    Frustum& ViewVolume();


    /**
     * @brief Getter for the aspectRatio.
     * 
     * @details Abstracts the `cameraViewVolumes`'s aspect ratio value.
     * 
     * @returns `float` Aspect ratio of the camera.
     */
    float& getAspectRatio();

    /**
     * @brief Getter for the fov.
     * 
     * @details Abstracts the `cameraViewVolumes`'s fov value.
     * 
     * @returns `float` Fov of the camera.
     */
    float& getFov();

    /**
     * @brief Gets the render distance.
     * 
     * @details Abstracts the `cameraViewVolumes`'s far value.
     * 
     * @returns `float` Camera's render distance.
     */
    float& getRenderDistance();


	/**
	 * @brief Getter for the front (forward) vector of the camera.
	 *
	 * @return
	 * `glm::vec3&` Reference to this camera's local front-facing (forward-facing)
	 * vector.
	 */
	Vector3& getFront();

	/**
	 * @brief Getter for the up vector of the camera.
	 *
	 * @return
	 * `glm::vec3&` Reference to this camera's local upwards-facing vector.
	 */
	Vector3& getUp();

	/**
	 * @brief Getter for the right vector of the camera.
	 * 
	 * @return 
	 * `glm::vec3&` Reference to this camera's local right-facing vector.
	 */
	Vector3& getRight();


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
