#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"


/**
 * @brief A 2D Ray starting from an `origin` with a `direction`.
 */
struct Ray2D{

    Vector2 origin;
    Vector2 direction;

    /**
     * @brief Default Constructor
     */
    Ray2D();

    /**
     * @brief Constructor for a new Ray2D.
     * 
     * @param originPos Origin point, where the ray starts from.
     * @param dirVec Direction the ray will face.
     * 
     * @returns `Ray2D` New Ray2D.
     */
    Ray2D( Vector2 originPos, Vector2 dirVec );

};

/**
 * @brief A 3D Ray starting from an `origin` with a `direction`.
 */
struct Ray3D{

    Vector3 origin;
    Vector3 direction;

    /**
     * @brief Default Constructor
     */
    Ray3D();

    /**
     * @brief Constructor for a new Ray3D.
     * 
     * @param originPos Origin point, where the ray starts from.
     * @param dirVec Direction the ray will face.
     * 
     * @returns `Ray3D` New Ray3D.
     */
    Ray3D( Vector3 originPos, Vector3 dirVec );

};

struct RayHit2D{

    Vector2 collision; /**< Collision point of the ray hit.*/
    Vector2 uv; /**< UV coord of the ray hit. */
    float t; /**< Scalar value from the ray, for the hit */

    /**
     * @brief Default Constructor
     */
    RayHit2D();

    /**
     * @brief Constructor for a successfull 2d ray hit with another shape.
     * 
     * @param collisionPoint Point of collision with the shape.
     * @param uvCoord Coordinate for the UV value.
     * @param tValue T value of the scalar distance, for the collision's point along the ray's direction.
     */
    RayHit2D( Vector2 collisionPoint, Vector2 uvCoord, float tValue );
};

struct RayHit3D{

    Vector3 collision; /**< Collision point of the ray hit.*/
    Vector2 uv; /**< UV coord of the ray hit. */
    float t; /**< Scalar value from the ray, for the hit.*/


    /**
     * @brief Default Constructor
     */
    RayHit3D();

    /**
     * @brief Constructor for a successfull 3d ray hit with another shape.
     * 
     * @param collisionPoint Point of collision with the shape.
     * @param uvCoord Coordinate for the UV value.
     * @param tValue T value of the scalar distance, for the collision's point along the ray's direction.
     * 
     * @returns `RayHit3D` New RayHit3D
     */
    RayHit3D( Vector3 collisionPoint, Vector2 uvCoord, float tValue );
};