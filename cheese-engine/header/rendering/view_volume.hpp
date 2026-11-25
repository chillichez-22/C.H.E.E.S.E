#pragma once

#include <cmath>


struct ViewVolume{

private:

    float m_height;  /*< Height of the view volume */

protected:

    float m_aspectRatio;    /**< Aspect ratio of the screen */

    float m_near;   /**< Near plane, z value */
    float m_far;    /**< Far plane, z value */

public:

    /**
     * @brief Default constructor for a new `Frustum`.
     * 
     * @returns `ViewVolume` New frustum object.
     */
    ViewVolume() = default;

    /**
     * @brief Constructor for a new `Frustum`.
     * 
     * @param aspectRatioVal Aspect ratio of the main screen, width / height.
     * @param nearDist Near side distance from the camera, as an offset from the camera's centre.
     * @param farDist Far side distance from the camera, as an offset from the camera's centre.
     * 
     * @param heightVal Height of viewing volume. 
     * 
     * 
     * @returns `ViewVolume` New frustum object.
     */
    ViewVolume( 
        float aspectRatioVal, 
        float nearDist, 
        float farDist,
        float heightVal = 0.f 
    );


    // Getters

    /**
     * @brief Getter for the view volume's `aspectRatio`.
     * 
     * @returns `float` aspectRatio of the near plane of the view volume
     */
    float& getAspectRatio();


    // Geometry

    /**
     * @brief 
     * Calculate the height of the view volume, for its `near` side; using its `aspectRatio` and `fov`. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * 
     * @details We dont call this `get...` because its easier to just have the name. 
     * 
     * 
     * @returns `float` View volume's height value, for the `near` side.
     */
    virtual float height();

    /**
     * @brief 
     * Calculate the width of the view volume, for its `near` side; using its `aspectRatio` and `fov`. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * 
     * @details We dont call this `get...` because its easier to just have the name. 
     * 
     * 
     * @returns `float` View volume's width value, for the `near` side.
     */
    float width();


    /**
     * @brief Gets the `near` side of the view volume.
     * 
     * 
     * @details We dont call this `get...` because its easier to just have the name. 
     * 
     * @returns `float&` View volume's `near` side value.
     */
    float& n();

    /**
     * @brief Gets the `far` side of the view volume.
     * 
     * 
     * @details We dont call this `get...` because its easier to just have the name. 
     * 
     * @returns `float&` View volume's `far` side value.
     */
    float& f();


    /**
     * @brief Gets the left side of the view volume, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` View volume's left side value, for the `near` side.
     */
    float l();

    /**
     * @brief Gets the right side of the view volume, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the far side value.
     * 
     * @returns `float` View volume's right side value, for the `near` side.
     */
    float r();

    /**
     * @brief Gets the top side of the view volume, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` View volume's top side value, for the `near` side.
     */
    float t();

    /**
     * @brief Gets the bottom side of the view volume, on its `near` side. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * @returns `float` View volume's bottom side value, for the `near` side.
     */
    float b();

    
    /**
     * @brief Scales a side to the far side, since the `left()`, `right()`, `top()`, `bottom()` is calculated for the `near` side only.
     * 
     * @param side Side to scale to the `far` side.
     * 
     * @returns `float` - Side scaled to the far side
     */
    float scaleToFar( float side );



    // Setter

    /**
     * @brief Setter for the view volume's aspect ratio.
     * 
     * @param newAspectRatio New aspect ratio to set. ( width / height ) 
     */
    void setAspectRatio( float newAspectRatio );

    /**
     * @brief Setter for the view volume's near plane distance.
     * 
     * The distance is from the centre of the camera, and should assume the camera is at origin ( 0, 0, 0 ). 
     * Since the distance is just an offset, and not an actual coord or pos.
     * 
     * @param nearDist New value for the near side.
     */
    void setNear( float nearDist );

    /**
     * @brief Setter for the view volume's far plane distance.
     * 
     * The distance is from the centre of the camera, and should assume the camera is at origin ( 0, 0, 0 ). 
     * Since the distance is just an offset, and not an actual coord or pos.
     * 
     * @param farDist New value for the far side.
     */
    void setFar( float farDist );


    /**
     * @brief Setter for the view volume's height.
     * 
     * @param heightVal New value for the height.
     */
    virtual void setHeight( float heightVal );

    /**
     * @brief Setter for the view volume's width.
     * 
     * @param widthVal New value for the width.
     */
    void setWidth( float widthVal );


};



struct Frustum : public ViewVolume {

private:

    float m_fov;    /**< FOV for the camera */


public:

    // Constructors

    /**
     * @brief Default constructor for a new `Frustum`.
     * 
     * @returns `Frustum` New frustum object.
     */
    Frustum() = default;

    /**
     * @brief Constructor for a new `Frustum`.
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
    );


    // Conversions

    /**
     * @brief Constructor for a new `Frustum`
     * 
     * @param viewVol Viewing volume to convert.
     * @param fov Field of view for the frustum.
     * 
     * @returns `Frustum` New frustum object.
     */
    Frustum(

        ViewVolume viewVol,
        float fov = 120.f
    );


    // Getters

    /**
     * @brief Getter for the frustum's `fov`.
     * 
     * @returns `float` fov angle in degrees.
     */
    float& getFov();


    // Geometry

    /**
     * @brief 
     * Calculate the height of the frustum, for its `near` side; using its `aspectRatio` and `fov`. 
     * 
     * Use `scaleToFar()` to convert this to the `far` side value.
     * 
     * 
     * @details We dont call this `get...` because its easier to just have the name. 
     * 
     * 
     * @returns `float` Frustum's height value, for the `near` side.
     */
    float height() override;


    // Setters

    /**
     * @brief Setter for the frustum's field of view, fov.
     * 
     * @param fieldOfView New fov to set.
     */
    void setFov( float fieldOfView );

    /**
     * @brief Setter for the view volume's height.
     * 
     * @param heightVal New value for the height.
     */
    void setHeight( float heightVal ) override;

};