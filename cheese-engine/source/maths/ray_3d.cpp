#include "maths/ray_3d.hpp"


// Ray3D

Ray3D::Ray3D( Vector3 originPos, Vector3 dirVec ){

    origin = originPos;
    direction = dirVec;
};


// Ray Hit

RayHit3D::RayHit3D(){};

RayHit3D::RayHit3D( Vector3 collisionPoint, Vector2 uvCoord, float tValue ){

    collision = collisionPoint;
    uv = uvCoord;
    t = tValue;
};