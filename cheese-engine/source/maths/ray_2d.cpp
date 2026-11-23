#include "maths/ray_2d.hpp"


// Ray2D

Ray2D::Ray2D( Vector2 originPos, Vector2 dirVec ){

    origin = originPos;
    direction = dirVec;
};


// Ray Hit

RayHit2D::RayHit2D(){};

RayHit2D::RayHit2D( Vector2 collisionPoint, Vector2 uvCoord, float tValue ){

    collision = collisionPoint;
    uv = uvCoord;
    t = tValue;
};
