#include "ray.hpp"


// Ray2D

Ray2D::Ray2D( Vector2 originPos, Vector2 dirVec ){

    origin = originPos;
    direction = dirVec;
}


// Ray3D

Ray3D::Ray3D( Vector3 originPos, Vector3 dirVec ){

    origin = originPos;
    direction = dirVec;
};


// RayHit

RayHit2D::RayHit2D(){};

RayHit2D::RayHit2D( Vector2 collisionPoint, Vector2 uvCoord, float tValue ){

    collision = collisionPoint;
    uv = uvCoord;
    t = tValue;
};


RayHit3D::RayHit3D(){};

RayHit3D::RayHit3D( Vector3 collisionPoint, Vector2 uvCoord, float tValue ){

    collision = collisionPoint;
    uv = uvCoord;
    t = tValue;
};