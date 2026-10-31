#pragma once

#include "component.hpp"
#include "vector_3.hpp"

#include <iostream>
#include <array>
#include <cstdint>
#include <stdfloat>

struct Transform3D : public Component{

private:

    std::array< std::float64_t, 3 > positionList = { 0.f, 0.f, 0.f }; /**< Array of 64 Bit floats for positional values */
    std::array< std::float64_t, 3 > rotationList = { 0.f, 0.f, 0.f }; /**< Array of 64 Bit floats for euler rotation values */
    std::array< std::float32_t, 3 > scaleList = { 1.f, 1.f, 1.f};     /**< Array of 32 Bit floats for scalar values */

public:

    /**
     * @brief Default Constructor
     */
    Transform3D(){};

    /**
     * @brief Allows the use of `<iostream>` to print this object.
     * 
     * @param os Output stream object.
     * @param obj Object to output into stream.
     * 
     * @returns `ostream` Output stream object. 
     */
    friend std::ostream& operator<<( std::ostream& os, const Transform3D obj ){

        os << "Pos:" << obj.getPos()      << " | ";
        os << "Rot:" << obj.getRotation() << " | ";
        os << "Scl:" << obj.getScale();
        
        return os;
    }

    // Getters


    // Position

    /**
     * @brief Gets the position values for x,y,z axis.
     * 
     * @returns `Vector3` Vector containing the position in the x,y,z axis.
     */
    Vector3 getPos() const;

    /**
     * @brief Gets the position in the x axis.
     * 
     * @returns `float` X axis position.
     */
    float getPosX() const;

    /**
     * @brief Gets the position in the y axis.
     * 
     * @returns `float` Y axis position.
     */
    float getPosY() const;

    /**
     * @brief Gets the position in the z axis.
     * 
     * @returns `float` Z axis position.
     */
    float getPosZ() const;


    // Rotation

    /**
     * @brief Gets the rotation angle ( in degrees ) for x,y,z axis.
     * 
     * @returns `Vector3` Vector containing the rotation in the x,y,z axis.
     */
    Vector3 getRotation() const;

    /**
     * @brief Gets the rotation angle ( in degrees ) in the x axis.
     * 
     * @returns `float` X axis angle.
     */
    float getRotationX() const;

    /**
     * @brief Gets the rotation angle ( in degrees ) in the y axis.
     * 
     * @returns `float` Y axis angle.
     */
    float getRotationY() const;

    /**
     * @brief Gets the rotation angle ( in degrees ) in the z axis.
     * 
     * @returns `float` Z axis angle.
     */
    float getRotationZ() const;


    // Scale

    /**
     * @brief Gets the scale values for x,y,z axis.
     * 
     * @returns `Vector3` Vector containing the scale in the x,y,z axis.
     */
    Vector3 getScale() const;

    /**
     * @brief Gets the scale in the x axis.
     * 
     * @returns `float` X axis scale value.
     */
    float getScaleX() const;

    /**
     * @brief Gets the scale in the y axis.
     * 
     * @returns `float` Y axis scale value.
     */
    float getScaleY() const;

    /**
     * @brief Gets the scale in the z axis.
     * 
     * @returns `float` Z axis scale value.
     */
    float getScaleZ() const;


    
    // Setters


    // Position

    /**
     * @brief Sets a new position.
     * 
     * @param positionVector Vector holding new x,y,z values for the position 
     */    
    void setPos( Vector3 positionVector );

    /**
     * @brief Sets the position in the X axis.
     * 
     * @param x New X axis position.
     */
    void setPosX( float& x );

    /**
     * @brief Sets the position in the Y axis.
     * 
     * @param y New Y axis position.
     */
    void setPosY( float& y );

    /**
     * @brief Sets the position in the Z axs.
     * 
     * @param z New Z axis position.
     */
    void setPosZ( float& z );



    // Rotate

    /**
     * @brief Sets a new rotation. Uses euler degrees to represent the angle
     * 
     * @param rotationVector Vector holding new x,y,z values for the rotation
     */
    void setRotate( Vector3 rotationVector );

    /**
     * @brief Sets the rotation in the X axis.
     * 
     * @param x New X axis angle in degrees.
     */
    void setRotateX( float& degrees );

    /**
     * @brief Sets the rotation in the Y axis.
     * 
     * @param Y New Y axis angle in degrees.
     */
    void setRotateY( float& degrees );

    /**
     * @brief Sets the rotation in the Z axis.
     * 
     * @param z New Z axis angle in degrees.
     */
    void setRotateZ( float& degrees );


    // Scale

    /**
     * @brief Sets a new scale.
     * 
     * @param scaleVector Vector holding new x,y,z values for the scale
     */
    void setScale( Vector3 scaleVector );

    /**
     * @brief Sets the scale in the X axis.
     * 
     * @param x New X axis scale.
     */
    void setScaleX( float& x );

    /**
     * @brief Sets the scale in the Y axis.
     * 
     * @param Y New Y axis scale.
     */
    void setScaleY( float& y );

    /**
     * @brief Sets the scale in the Z axis.
     * 
     * @param z New Z axis scale.
     */
    void setScaleZ( float& z );


};