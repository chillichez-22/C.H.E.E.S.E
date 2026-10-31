#pragma once

#include <cmath>

struct ViewVolume{

    float aspectRatio;    /**< Aspect ratio of the screen */

    float near;    /**< Near plane, z value */
    float far;    /**< Far plane, z value */

    
    ViewVolume(){};

    ViewVolume( 
        float aspectRatioVal, 
        float nearDist, 
        float farDist 
    ): aspectRatio( aspectRatioVal ), near( nearDist ), far( farDist ){};

};


struct Frustum{

private:

    float aspectRatio;  /**< Aspect ratio of the screen */
    float fov;          /**< FOV for the camera */

    float near;   /**< Near plane, z value */
    float far;    /**< Far plane, z value */

public:

    /**
     * @brief Default constructor for a new `Frustum`
     * 
     * @returns `Frustum` New frustum object.
     */
    Frustum(){};

    /**
     * @brief Constructor for a new `Frustum`
     * 
     * 
     * @param aspectRatioVal Aspect ratio of the main screen, width / height.
     * @param feildOfView FOV for the camera ( mainly known as the horizontal fov ).
     * @param nearDist Near side distance from the camera, as an offset from the camera's centre.
     * @param farDist Far side distance from the camera, as an offset from the camera's centre.
     * 
     * @returns `Frustum` New frustum object.
     */
    Frustum( 
        float aspectRatioVal, 
        float fieldOfView, 
        float nearDist, 
        float farDist
    ): aspectRatio( aspectRatioVal ), fov( fieldOfView ), near( nearDist ), far( farDist ){};



    // Getters

    /**
     * @brief Getter for the frustum's `aspectRatio`.
     * 
     * @returns `float` aspectRatio of the near plane of the frustum
     */
    float& getAspectRatio();

    /**
     * @brief Getter for the frustum's `fov`.
     * 
     * @returns `float` fov angle in degrees.
     */
    float& getFov();

    
    /**
     * @brief Getter for the frustum's `aspectRatio`'s pointer.
     * 
     * @returns `float*` Pointer to the, aspectRatio; of the near plane of the frustum.
     */
    float* getAspectRatioPointer();

    /**
     * @brief Getter for the frustum's `fov`'s pointer.
     * 
     * @returns `float*` Pointer to the, fov; angle in degrees.
     */
    float* getFovPointer();


    // Geometry

    /**
     * @brief Calculate the width of the frustum, for its `near` side; using its `aspectRatio` and `fov`. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` Frustum's width value, for the `near` side.
     */
    float width();

    /**
     * @brief Calculate the height of the frustum, for its `near` side; using its `aspectRatio` and `fov`. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` Frustum's height value, for the `near` side.
     */
    float height();


    /**
     * @brief Gets the left side of the frustum, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` Frustum's left side value, for the `near` side.
     */
    float l();

    /**
     * @brief Gets the right side of the frustum, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the far side value.
     * 
     * @returns `float` Frustum's right side value, for the `near` side.
     */
    float r();

    /**
     * @brief Gets the top side of the frustum, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` Frustum's top side value, for the `near` side.
     */
    float t();

    /**
     * @brief Gets the bottom side of the frustum, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` Frustum's bottom side value, for the `near` side.
     */
    float b();

    /**
     * @brief Gets the `near` side of the frustum, on its `near` side.
     * 
     * @returns `float` Frustum's `near` side value.
     */
    float n();

    /**
     * @brief Gets the `far` side of the frustum, on its `near` side.
     * 
     * @returns `float` Frustum's `far` side value.
     */
    float f();

    /**
     * @brief Scales a side to the far side, since the `left()`, `right()`, `top()`, `bottom()` is calculated for the `near` side only.
     * 
     * @param side Side to scale to the `far` side.
     * 
     * @returns `float` Side scaled to the far side
     */
    float scaleToFar( float side );


    // Setters

    /**
     * @brief Setter for the frustum's aspect ratio.
     * 
     * @param newAspectRatio New aspect ratio to set. ( width / height ) 
     */
    void setAspectRatio( float newAspectRatio );

    /**
     * @brief Setter for the frustum's field of view, fov.
     * 
     * @param fieldOfView New fov to set.
     */
    void setFov( float fieldOfView );

    /**
     * @brief Setter for the frustum's near plane distance.
     * 
     * The distance is from the centre of the camera, and should assume the camera is at origin ( 0, 0, 0 ). 
     * Since the distance is just an offset, and not an actual coord or pos.
     * 
     * @param nearDist New near distance to set 
     */
    void setNear( float nearDist );

    /**
     * @brief Setter for the frustum's far plane distance.
     * 
     * The distance is from the centre of the camera, and should assume the camera is at origin ( 0, 0, 0 ). 
     * Since the distance is just an offset, and not an actual coord or pos.
     * 
     * @param farDist New far distance to set 
     */
    void setFar( float farDist );

};