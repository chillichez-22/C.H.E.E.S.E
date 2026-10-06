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